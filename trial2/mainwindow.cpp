#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QString>
#include <QInputDialog>
#include <QFileDialog>
#include <QCryptographicHash>
#include <QMessageBox>

QString difficulty_ = "";
int score_ = 0;
int correct_ans = 0;
int missed_q = 0;
bool pauseBtn_, resumeBtn_;
QString topic_ = "";
int a = 0;
int user_id = 0;
QString namee;
QString catt;
int question_no_easy = 1;
int question_no_med = 1;
int question_no_hard = 1;
int cat_id = 0;
bool ans_e;
QString optn1, optn2, optn3, optn4, ans_m, ans_h, diff_;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->quizBox->setCurrentIndex(0);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./sqlite.db");
    if (db.open()) {
        ui->title->setText("connected...");
    } else {
        ui->title->setText("error! db is not connected");
    }

    QSqlQuery qry(db);
    qry.exec("PRAGMA foreign_keys = ON;");

    QSqlQuery qry1(db);
    QSqlQuery qry2(db);
    QSqlQuery qry3(db);
    QSqlQuery qry4(db);
    QSqlQuery qry5(db);
    QSqlQuery qry6(db);
    QSqlQuery qry7(db);

    qry1.prepare("CREATE TABLE IF NOT EXISTS users ("
                "ID integer PRIMARY KEY AUTOINCREMENT NOT NULL,"
                "name VARCHAR(20) not null unique,"
                "hashed_pass VARCHAR(20) not null);");
    qry2.prepare("CREATE TABLE IF NOT EXISTS category ("
                 "ID integer PRIMARY KEY AUTOINCREMENT not null,"
                 "category VARCHAR(20) not null,"
                 "note VARCHAR(100));");
    qry3.prepare("CREATE TABLE IF NOT EXISTS questionsEasy ("
                 "ID integer PRIMARY KEY AUTOINCREMENT NOT NULL,"
                 "question VARCHAR(100) not null,"
                 "answer BOOLEAN not null,"
                 "owner_id integer not null,"
                 "category_id integer not null,"
                 "foreign key (owner_id) references users(ID),"
                 "foreign key (category_id) references category(ID));");
    qry4.prepare("CREATE TABLE IF NOT EXISTS questionMedium ("
                 "ID integer PRIMARY KEY AUTOINCREMENT NOT NULL,"
                 "question VARCHAR(100) not null,"
                 "option1 VARCHAR(100) not null,"
                 "option2 VARCHAR(100) not null,"
                 "option3 VARCHAR(100) not null,"
                 "option4 VARCHAR(100) not null,"
                 "answer VARCHAR(100) not null,"
                 "owner_id integer not null,"
                 "category_id integer not null,"
                 "foreign key (owner_id) references users(ID),"
                 "foreign key (category_id) references category(ID));");
    qry5.prepare("CREATE TABLE IF NOT EXISTS questionHard ("
                 "ID integer PRIMARY KEY AUTOINCREMENT NOT NULL,"
                 "question VARCHAR(100) not null,"
                 "answer VARCHAR(100) not null,"
                 "owner_id integer not null,"
                 "category_id integer not null,"
                 "foreign key (owner_id) references users(ID),"
                 "foreign key (category_id) references category(ID));");
    qry6.prepare("CREATE TABLE IF NOT EXISTS leaderboard ("
                 "ID integer PRIMARY KEY AUTOINCREMENT NOT NULL,"
                 "name VARCHAR(20) not null unique,"
                 "difficulty VARCHAR(20) not null,"
                 "score integer not null);");
    qry7.prepare("CREATE TABLE IF NOT EXISTS reviewers ("
                 "ID integer PRIMARY KEY AUTOINCREMENT NOT NULL,"
                 "file_name VARCHAR(50) not null,"
                 "file blob null);");
    if (!qry1.exec() ||
            !qry2.exec() ||
            !qry3.exec() ||
            !qry4.exec() ||
            !qry5.exec() ||
            !qry6.exec() ||
            !qry7.exec()) {
        qDebug() << "table not created";
        return;
    }
}


MainWindow::~MainWindow()
{
    delete ui;
    db.close();
}

void delay()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 1);
}

void addUsers (QString name, QString hashed_pass) {
    QSqlQuery qry;
    qry.prepare("INSERT INTO users ("
                "name,"
                "hashed_pass)"
                "VALUES (?, ?);");
    qry.addBindValue(name);
    qry.addBindValue(hashed_pass);

    if (!qry.exec()) {
        qDebug() << "Error adding value to database";
    }
}

void addcategory (QString category_name, QString note_inp) {
    QSqlQuery qry;
    qry.prepare("INSERT INTO category ("
                "category,"
                "note)"
                "VALUES (?, ?);");
    qry.addBindValue(category_name);
    qry.addBindValue(note_inp);
    if (!qry.exec()) {
        qDebug() << "Error category";
    }
}

void addQuestionEasy (QString ques, bool ans, int owner_id, int category_id) {
    QSqlQuery qry;
    qry.prepare("INSERT INTO questionseasy ("
                "question,"
                "answer,"
                "owner_id,"
                "category_id)"
                "VALUES (?, ?, ?, ?);");
    qry.addBindValue(ques);
    qry.addBindValue(ans);
    qry.addBindValue(owner_id);
    qry.addBindValue(category_id);
    if (!qry.exec()) {
        qDebug() << "error easy";
    }
}

void addQuestionMed (QString ques, QString opt1, QString opt2, QString opt3,
                     QString opt4, QString ans, int owner_id, int category_id) {
    QSqlQuery qry;
    qry.prepare("INSERT INTO questionMedium ("
                "question,"
                "option1,"
                "option2,"
                "option3,"
                "option4,"
                "answer,"
                "owner_id,"
                "category_id)"
                "VALUES (?, ?, ?, ?, ?, ?, ?, ?);");
    qry.addBindValue(ques);
    qry.addBindValue(opt1);
    qry.addBindValue(opt2);
    qry.addBindValue(opt3);
    qry.addBindValue(opt4);
    qry.addBindValue(ans);
    qry.addBindValue(owner_id);
    qry.addBindValue(category_id);
    if (!qry.exec()) {
        qDebug() << "error med";
    }
}

void addQuestionHard (QString ques, QString ans, int owner_id, int category_id) {
    QSqlQuery qry;
    qry.prepare("INSERT INTO questionHard ("
                "question,"
                "answer,"
                "owner_id,"
                "category_id)"
                "VALUES (?, ?, ?, ?);");
    qry.addBindValue(ques);
    qry.addBindValue(ans);
    qry.addBindValue(owner_id);
    qry.addBindValue(category_id);
    if (!qry.exec()) {
        qDebug() << "error hard";
    }
}

void Leaderboard (QString name, int score) {
    QSqlQuery qry;
    qry.prepare("INSERT INTO leaderboard("
                "name,"
                "score)"
                "VALUES (?, ?);");
    qry.addBindValue(name);
    qry.addBindValue(score);
    if (!qry.exec()) {
        qDebug() << "error leaderboard";
    }
}

void Reviewer (QString fileN, QByteArray file) {
    QSqlQuery qry;
    qry.prepare("INSERT INTO reviewers ("
                "file_name,"
                "file)"
                "VALUES (?, ?);");
    qry.addBindValue(fileN);
    qry.addBindValue(file);
    if (!qry.exec()) {
        qDebug() << "error reviewer";
    }
}

void q_num (QString q_diff, int owner_id, int cat_id) {
    QSqlQuery qry;
    qry.prepare("SELECT owner_id, category_id FROM \'" + q_diff + "\' WHERE owner_id = ? AND category_id = ?");
    qry.bindValue(0, owner_id);
    qry.bindValue(1, cat_id);
    qDebug() << q_diff;
    qDebug() << owner_id;
    qDebug() << cat_id;

    if (qry.exec()) {
        qDebug() << "di na error";
        if (qry.next()) {
            if (q_diff == "questionsEasy") {
                question_no_easy += 1;
                qDebug() << question_no_easy;
            } else if (q_diff == "questionMedium") {
                question_no_med += 1;
                qDebug() << question_no_med;
            } else {
                question_no_hard += 1;
                qDebug() << question_no_hard;
            }
        }
    }
}

void ShowQE(int owner_id, int cat_id) {
    QSqlQuery qry;
    qry.prepare("SELECT * FROM questionsEasy WHERE owner_id = ? AND category_id = ?");
    qry.bindValue(0, owner_id);
    qry.bindValue(1, cat_id);

    if (qry.exec()) {
        if(qry.next()) {
            int id_ = qry.value(0).toInt();
            QString q = qry.value(1).toString();
            bool ans = qry.value(2).toBool();
            int o_id = qry.value(3).toInt();
            int c_id = qry.value(4).toInt();
        }
    }
}


void MainWindow::timer_() {
    pauseBtn_ = false;
    resumeBtn_ = false;
    int num = 30;
    int i = 0;
    while(i < num+1) {
        ui->timer->setText(QString::number(num-i));
        delay();
        if (pauseBtn_ == true && resumeBtn_ == false) {
            continue;
        } else {
            i += 1;
        }
    }
}

//question arrays
std::string algEQarr []= {"eaq1", "eaq2", "eaq3", "eaq4", "eaq5"};
std::string geoEQarr []= {"egq1", "egq2", "egq3", "egq4", "egq5"};
std::string trigoEQarr []= {"etq1 ", "etq2", "etq3", "etq4", "etq5"};
std::string algMQarr []= {"maq1", "maq2", "maq3", "maq4", "maq5"};
std::string geoMQarr []= {"mgq1", "mgq2", "mgq3", "mgq4", "mgq5"};
std::string trigoMQarr []= {"mtq1 ", "mtq2", "mtq3", "mtq4", "mtq5"};
std::string algHQarr []= {"x^2 + 11x + 28 ", "x^2 + 6x + 5", "x^2 + 4x", "x^2 + 7x", "x^2 - 4x + 4"};
std::string geoHQarr []= {"gq1", "gq2", "gq3", "gq4", "gq5"};
std::string trigoHQarr []= {"tq1 ", "tq2", "tq3", "tq4", "tq5"};


void MainWindow::askAlgEQues(){
        ui -> eq -> setText(QString::fromStdString(algEQarr[a]));
        a++;
        int arrsize = sizeof(algEQarr)/sizeof(algEQarr[0]) +1;
        if (arrsize == a){
           ui->stackedWidget->setCurrentIndex(7);
        }
};
void MainWindow::askgeoEQues(){
        ui -> eq -> setText(QString::fromStdString(geoEQarr[a]));
        a++;
       int arrsize = sizeof(geoEQarr)/sizeof(geoEQarr[0]) +1;
        if (arrsize == a){
           ui->stackedWidget->setCurrentIndex(7);
        }
};
void MainWindow::asktrigoEQues(){
        ui -> eq -> setText(QString::fromStdString(trigoEQarr[a]));
        a++;
        int arrsize = sizeof(trigoEQarr)/sizeof(trigoEQarr[0])+1;
        if (arrsize == a){
           ui->stackedWidget->setCurrentIndex(7);
        }
};
void MainWindow::askAlgMQues(){
        ui -> mq -> setText(QString::fromStdString(algMQarr[a]));
        a++;
        int arrsize = sizeof(algMQarr)/sizeof(algMQarr[0]) +1;
        if (arrsize == a){
           ui->stackedWidget->setCurrentIndex(7);
        }
};
void MainWindow::askgeoMQues(){
        ui -> mq -> setText(QString::fromStdString(geoMQarr[a]));
        a++;
       int arrsize = sizeof(geoMQarr)/sizeof(geoMQarr[0]) +1;
        if (arrsize == a){
           ui->stackedWidget->setCurrentIndex(7);
        }
};
void MainWindow::asktrigoMQues(){
        ui -> mq -> setText(QString::fromStdString(trigoMQarr[a]));
        a++;
        int arrsize = sizeof(trigoMQarr)/sizeof(trigoMQarr[0])+1;
        if (arrsize == a){
           ui->stackedWidget->setCurrentIndex(7);
        }
};
void MainWindow::askAlgHQues(){
        ui -> hq -> setText(QString::fromStdString(algHQarr[a]));
        a++;
        int arrsize = sizeof(algHQarr)/sizeof(algHQarr[0]) +1;
        if (arrsize == a){
           ui->stackedWidget->setCurrentIndex(7);
        }
};
void MainWindow::askgeoHQues(){
        ui -> hq -> setText(QString::fromStdString(geoHQarr[a]));
        a++;
       int arrsize = sizeof(geoHQarr)/sizeof(geoHQarr[0]) +1;
        if (arrsize == a){
           ui->stackedWidget->setCurrentIndex(7);
        }
};
void MainWindow::asktrigoHQues(){
        ui -> hq -> setText(QString::fromStdString(trigoHQarr[a]));
        a++;
        int arrsize = sizeof(trigoHQarr)/sizeof(trigoHQarr[0])+1;
        if (arrsize == a){
           ui->stackedWidget->setCurrentIndex(7);
        }
};

//buttons
void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
//    ui->scoreLbl->setText(QString::number(score_)); !!!!!!!!!!!!!!!!!! para san to????? ang aga naman ng sa score HAHA
}

void MainWindow::on_quizBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_geo_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    topic_ = "geo";
    a=0;
}

void MainWindow::on_alg_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    topic_ = "alg";
    a=0;

}

void MainWindow::on_trig_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    topic_ = "trig";
    a=0;
}


void MainWindow::on_back_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_backBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_main_menu_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_easyBtn_clicked()
{
    difficulty_ = "easy";
    ui->stackedWidget->setCurrentIndex(4);
    ui->instruction->setText("instruction sa easy");
    if (topic_ == "geo" ){
        ui -> eq -> setText(QString::fromStdString(geoEQarr[a]));
        a++;
    }
    else if (topic_ == "alg"){
        ui -> eq -> setText(QString::fromStdString(algEQarr[a]));
        a++;
    }
    else {
        ui -> eq -> setText(QString::fromStdString(trigoEQarr[a]));
        a++;
    };
}

void MainWindow::on_mediumBtn_clicked()
{
    difficulty_ = "medium";
    ui->stackedWidget->setCurrentIndex(4);
    ui->instruction->setText("instruction sa med");
    if (topic_ == "geo" ){
        ui -> mq -> setText(QString::fromStdString(geoMQarr[a]));
        a++;
    }
    else if (topic_ == "alg"){
        ui -> mq -> setText(QString::fromStdString(algMQarr[a]));
        a++;
    }
    else {
        ui -> mq -> setText(QString::fromStdString(trigoMQarr[a]));
        a++;
    };
}

void MainWindow::on_difficultBtn_clicked()
{
            difficulty_ = "hard";
    ui->stackedWidget->setCurrentIndex(4);
    ui->instruction->setText("instruction sa hard");
    if (topic_ == "geo" ){
        ui -> hq -> setText(QString::fromStdString(geoHQarr[a]));
        a++;
    }
    else if (topic_ == "alg"){
        ui -> hq -> setText(QString::fromStdString(algHQarr[a]));
        a++;
    }
    else {
        ui -> hq -> setText(QString::fromStdString(trigoHQarr[a]));
        a++;
    };
}

void MainWindow::on_t1_clicked()
{
//    if else kung korik chuchu
//    if () {
//        ui->t1->setStyleSheet("QPushButton { background-color: rgb(0, 255, 0);}");
//    }
//    else {
//        ui->t1->setStyleSheet("QPushButton { background-color: rgb(255, 0, 0);}");
//    }
    ui->quizBox->setCurrentIndex(1);
}

void MainWindow::on_f1_clicked()
{
    //    if () {
    //        ui->f1->setStyleSheet("QPushButton { background-color: rgb(0, 255, 0);}");
    //    }
    //    else {
    //        ui->f1->setStyleSheet("QPushButton { background-color: rgb(255, 0, 0);}");
    //    }
    ui->quizBox->setCurrentIndex(1);
}


//void MainWindow::on_revBtn_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(5);
//}

void MainWindow::on_pause_btn_clicked()
{
    pauseBtn_ = true;
    resumeBtn_ = false;
    ui->stackedWidget->setCurrentIndex(6);

}

void MainWindow::on_resumeBtn_clicked()
{
    resumeBtn_ = true;
    pauseBtn_ = false;
    ui->stackedWidget->setCurrentIndex(5);
    ui->diff_label->setText(difficulty_);
    if (difficulty_ == "easy") {
        ui->quizBox->setCurrentIndex(0);
    } else if (difficulty_ == "medium") {
        ui->quizBox->setCurrentIndex(1);
    } else {
        ui->quizBox->setCurrentIndex(2);
    }
}


void MainWindow::on_okaybtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
//    ui->label_2->setText();
    ui->diff_label->setText(difficulty_);
    if (difficulty_ == "easy") {
        ui->quizBox->setCurrentIndex(0);
    } else if (difficulty_ == "medium") {
        ui->quizBox->setCurrentIndex(1);
    } else {
        ui->quizBox->setCurrentIndex(2);
    }
    timer_();
    ui->scoreLbl->setText(QString::number(score_));
}

void MainWindow::on_menuBtnP_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_retryBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->diff_label->setText(difficulty_);
    if (difficulty_ == "easy") {
        ui->quizBox->setCurrentIndex(0);
        a = 0;
        if(topic_ == "alg"){
            ui -> eq -> setText(QString::fromStdString(algEQarr[a]));
            a++;
        } else if (topic_ == "geo"){
            ui -> eq -> setText(QString::fromStdString(geoEQarr[a]));
            a++;
        } else {
            ui -> eq -> setText(QString::fromStdString(trigoEQarr[a]));
            a++;
        }
    } else if (difficulty_ == "medium") {
        ui->quizBox->setCurrentIndex(1);
        a = 0;
        if(topic_ == "alg"){
            ui -> mq -> setText(QString::fromStdString(algMQarr[a]));
            a++;
        } else if (topic_ == "geo"){
            ui -> mq -> setText(QString::fromStdString(geoMQarr[a]));
            a++;
        } else {
            ui -> mq -> setText(QString::fromStdString(trigoMQarr[a]));
            a++;
        }
    } else {
        ui->quizBox->setCurrentIndex(2);
        a = 0;
        if(topic_ == "alg"){
            ui -> hq -> setText(QString::fromStdString(algHQarr[a]));
            a++;
        } else if (topic_ == "geo"){
            ui -> hq -> setText(QString::fromStdString(geoHQarr[a]));
            a++;
        } else {
            ui -> hq -> setText(QString::fromStdString(trigoHQarr[a]));
            a++;
        }
    }
    timer_();

}



void MainWindow::on_submit_btn_clicked()
{
    QString hardAns = ui -> ans_inp -> text();
    if (hardAns != "" && topic_ == "alg"){
        ui -> ans_inp -> setText("");
        askAlgHQues();
//    QString ques = ui -> hq -> text();
//    QString hehe = QString::fromStdString(algHQarr[a]);
        if(hardAns != "1" /*&& ques == hehe*/){
            score_ += 0;
        }else {
            score_++;
        };
        ui -> scoreLbl -> setText(QString::number(score_));
    } else if (hardAns != "" && topic_ == "geo") {
        ui -> ans_inp -> setText("");
        askgeoHQues();
    } else if (hardAns != "" && topic_ == "trigo"){
        ui -> ans_inp -> setText("");
        asktrigoHQues();
    } else {
        ui -> ans_inp -> setText("");
    }
}


//custom
void MainWindow::on_cus_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
    ui->ls_box->setCurrentIndex(0);
    ui->login_sec->setStyleSheet("font: 900 9pt 'Segoe UI Black';"
                                 "text-decoration: underline;");
    ui->sign_sec->setStyleSheet("");
}

void MainWindow::on_login_sec_clicked()
{

    ui->ls_box->setCurrentIndex(0);
    ui->login_sec->setStyleSheet("font: 900 9pt 'Segoe UI Black';"
                                 "text-decoration: underline;");
    ui->sign_sec->setStyleSheet("");
    ui->name_inp_auth->setText("");
    ui->pass_inp_auth->setText("");
    ui->name_inp_auth_s->setText("");
    ui->pass_inp_auth_s->setText("");
    ui->error_msg->setText("");
    ui->error_msg_l->setText("");
    ui->cpass_->setText("");
}

void MainWindow::on_sign_sec_clicked()
{
    ui->ls_box->setCurrentIndex(1);
    ui->login_sec->setStyleSheet("");
    ui->sign_sec->setStyleSheet("font: 900 9pt 'Segoe UI Black';"
                                "text-decoration: underline;");
    ui->name_inp_auth->setText("");
    ui->pass_inp_auth->setText("");
    ui->name_inp_auth_s->setText("");
    ui->pass_inp_auth_s->setText("");
    ui->error_msg->setText("");
    ui->error_msg_l->setText("");
    ui->cpass_->setText("");
}

void MainWindow::on_back_btn_c_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->name_inp_auth->setText("");
    ui->pass_inp_auth->setText("");
    ui->name_inp_auth_s->setText("");
    ui->pass_inp_auth_s->setText("");
    ui->error_msg->setText("");
    ui->error_msg_l->setText("");
    ui->cpass_->setText("");
}


void MainWindow::on_signup_btn_clicked()
{
    QString name_inps, pass_inps, cpass_inps;
    if (!db.isOpen()) {
        qDebug() << "db not connected";
        return;
    }

    name_inps = ui->name_inp_auth_s->text();
    pass_inps = ui->pass_inp_auth_s->text();
    cpass_inps = ui->cpass_->text();

    if (name_inps == "" || pass_inps == "" || cpass_inps == "") {
        ui->error_msg->setText("don't leave it blank");
        return;
    }

    QSqlQuery qry(db);

    if  (qry.exec("SELECT name FROM users "
                 "WHERE name=\'" + name_inps + "\'")) {
        if (qry.next()) {
            ui->error_msg->setText(name_inps + " is already taken");
        } else {
            if (pass_inps == cpass_inps) {
                QString encodedPass = QCryptographicHash::hash((pass_inps.toLocal8Bit()),QCryptographicHash::Md5);
                qDebug() << name_inps;
                qDebug() << encodedPass;
                ::addUsers(name_inps, encodedPass);
                ui->error_msg->setText("Acc created");
            } else {
                ui->error_msg->setText("Recheck your pass");
            }
        }
    }
}

void MainWindow::on_login_btn_clicked()
{
    QString name_inpl, pass_inpl, pass_inph;
    if (!db.isOpen()) {
        qDebug() << "db not connected";
        return;
    }
    name_inpl = ui->name_inp_auth->text();
    pass_inpl = ui->pass_inp_auth->text();
    qDebug() << name_inpl;
    qDebug() << pass_inpl;
    if (name_inpl == "" || pass_inpl == "") {
        ui->error_msg_l->setText("don't leave it blank");
        return;
    }

    pass_inph = QCryptographicHash::hash((pass_inpl.toLocal8Bit()),QCryptographicHash::Md5);

    QSqlQuery qry(db);
    if (qry.exec("SELECT name, hashed_pass, ID FROM users "
             "WHERE name=\'" + name_inpl + "\' AND hashed_pass=\'" + pass_inph + "\'")) {
        if (qry.next()) {
            QString name = qry.value(0).toString();
            QString pass = qry.value(1).toString();
            int id = qry.value(2).toInt();
            qDebug() << name;
            qDebug() << pass;
            qDebug() << id;
            user_id = id;
            namee = name;
//            ui->error_msg_l->setText("korik");
            ui->name_inp_auth->setText("");
            ui->pass_inp_auth->setText("");
            ui->name_inp_auth_s->setText("");
            ui->pass_inp_auth_s->setText("");
            ui->error_msg->setText("");
            ui->error_msg_l->setText("");
            ui->cpass_->setText("");
            ui->stackedWidget->setCurrentIndex(9);
            ui->name_1->setText(name);
        }
        else {
            ui->error_msg_l->setText("wrong name or pass");
        }
    }
}


void MainWindow::on_BackBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}


void MainWindow::on_pushButton_2_clicked()
{
    QString cat = ui->lineEdit_2->text();
    QString note = ui->lineEdit_4->text();
    if (cat == "" || note == "") {
        ui->error1->setText("luh");
        return;
    }
    QMessageBox msgBox;
     msgBox.setText("The document has been modified.");
     msgBox.setInformativeText("Do you want to save your changes?");
     msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
     msgBox.setDefaultButton(QMessageBox::Save);
     int ret = msgBox.exec();
     switch (ret) {
       case QMessageBox::Save:
           // Save was clicked
           ::addcategory(cat, note);
           ui->q_no->setText(QString::number(question_no_easy));
           catt = cat;
           ui->stackedWidget->setCurrentIndex(10);
           ui->comboBox->setCurrentIndex(0);
           ui->stackedWidget_2->setCurrentIndex(0);
           ui->cat->setText(catt);
           ui->name_2->setText(namee);
           break;
       case QMessageBox::Discard:
           // Don't Save was clicked
         qDebug() << "bye";
           break;
     }

     QSqlQuery qry;

     if (qry.exec("SELECT ID FROM category WHERE ID = (SELECT MAX(ID) FROM category);")) {
         if (qry.next()) {
             cat_id = qry.value(0).toInt();
         }
     }

//     QSqlQuery qry;

//     if (qry.exec("SELECT ID, category, note FROM category "
//                  "WHERE category=\'" + cat + "\' AND note=\'" + note + "\'")) {
//        if (qry.next()) {
//            int id_ = qry.value(0).toInt();
//            QString category = qry.value(1).toString();
//            QString note = qry.value(2).toString();
//            qDebug() << category;
//            qDebug() << note;
//            qDebug() << id_;
//            cat_id = id_;
//        }
//     }
//    QMessageBox::information(this,"Confirmation", "Are You Sure?", QMessageBox::Ok, QMessageBox::Cancel);
}

//void MainWindow::on_BackBtn_2_clicked()
//{

//    ui->stackedWidget->setCurrentIndex(9);
//}

void MainWindow::on_comboBox_activated(int index)
{
    qDebug() << index;
    if (index == 0) {
        ui->stackedWidget_2->setCurrentIndex(index);
        ui->q_no->setText(QString::number(question_no_easy));
    } else if (index == 1) {
        ui->stackedWidget_2->setCurrentIndex(index);
        ui->q_no->setText(QString::number(question_no_med));
    } else {
        ui->stackedWidget_2->setCurrentIndex(index);
        ui->q_no->setText(QString::number(question_no_hard));
    }
    ui->trueBtn->setStyleSheet("");
    ui->falseBtn->setStyleSheet("");
    ui->lineEdit->setText("");
}

void MainWindow::on_toolButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open a File", "C://");
    ui->reviewer->setText(filename);
}


void MainWindow::on_pushButton_9_clicked()
{

}

void MainWindow::on_Add_clicked()
{
    QString question = ui->lineEdit->text();
    if (question == "") {
        ui->error_msg1->setText("Don't leave it blank");
        return;
    }
    int index_stacked = ui->stackedWidget_2->currentIndex();
    qDebug() << index_stacked;
    if (index_stacked == 0) {
//        QString ques, bool ans, int owner_id, int category_id
        qDebug() << question;
        qDebug() << ans_e;
        qDebug() << user_id;
        qDebug() << cat_id;

        QString true_btn = ui->trueBtn->styleSheet();
        QString false_btn = ui->falseBtn->styleSheet();

        if (true_btn == "" && false_btn == "") {
            ui->error_msg1->setText("Pili ka sis");
            return;
        }

        QMessageBox msgBox1;
         msgBox1.setText("The document has been modified.");
         msgBox1.setInformativeText("Add?");
         msgBox1.setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
         msgBox1.setDefaultButton(QMessageBox::Save);
         int ret = msgBox1.exec();
         switch (ret) {
           case QMessageBox::Save:
               // Save was clicked
               qDebug() << cat_id << "lololol";
               diff_ = "questionsEasy";
               ::addQuestionEasy(question, ans_e, user_id, cat_id);
               ui->lineEdit->setText("");
               ui->falseBtn->setStyleSheet("");
               ui->trueBtn->setStyleSheet("");
               qDebug() << ans_e;
               qDebug() << "yey!";
               ::q_num(diff_, user_id, cat_id);
               ui->q_no->setText(QString::number(question_no_easy));
               break;
           case QMessageBox::Discard:
               // Don't Save was clicked
               qDebug() << "bye";
               break;
         }
    }
    else if (index_stacked == 1) {
//        QString ques, bool ans, int owner_id, int category_id
        qDebug() << question;
        qDebug() << ans_m;
        qDebug() << user_id;
        qDebug() << cat_id << "lololol1";
        diff_ = "questionMedium";

        QString aC_btn = ui->a_btn->styleSheet();
        QString bC_btn = ui->b_btn->styleSheet();
        QString cC_btn = ui->c_btn->styleSheet();
        QString dC_btn = ui->d_btn->styleSheet();

        if (aC_btn == "" && bC_btn == "" && cC_btn == "" && dC_btn == "") {
            ui->error_msg1->setText("Pili ka sis");
            return;
        }

        optn1 = ui -> aLineEdit ->text();
        optn2 = ui -> bLineEdit ->text();
        optn3 = ui -> cLineEdit ->text();
        optn4 = ui -> dLineEdit ->text();

        QMessageBox msgBox1;
         msgBox1.setText("The document has been modified.");
         msgBox1.setInformativeText("Add?");
         msgBox1.setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
         msgBox1.setDefaultButton(QMessageBox::Save);
         int ret = msgBox1.exec();
         switch (ret) {
           case QMessageBox::Save:
               // Save was clicked
               qDebug() << cat_id;
               ::addQuestionMed(question, optn1, optn2, optn3, optn4, ans_m, user_id, cat_id);
               ui->lineEdit->setText("");
               ui->a_btn->setStyleSheet("");
               ui->b_btn->setStyleSheet("");
               ui->c_btn->setStyleSheet("");
               ui->d_btn->setStyleSheet("");
               qDebug() << ans_m;
               qDebug() << "yey!";
               ::q_num(diff_, user_id, cat_id);
               ui->q_no->setText(QString::number(question_no_med));
               break;
           case QMessageBox::Discard:
               // Don't Save was clicked
               qDebug() << "bye";
               break;
         }
    }
    else {
        qDebug() << question;
        qDebug() << ans_h;
        qDebug() << user_id;
        qDebug() << cat_id << "lololol2";
        diff_ = "questionHard";


       ans_h = ui->hardlineEdit->text();

        if (ans_h == "") {
            ui->error_msg1->setText("lagay ka sis");
            return;
        }

        QMessageBox msgBox1;
         msgBox1.setText("The document has been modified.");
         msgBox1.setInformativeText("Add?");
         msgBox1.setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
         msgBox1.setDefaultButton(QMessageBox::Save);
         int ret = msgBox1.exec();
         switch (ret) {
           case QMessageBox::Save:
               // Save was clicked
               qDebug() << cat_id;
               ::addQuestionHard(question, ans_h, user_id, cat_id);
               ui->lineEdit->setText("");
               qDebug() << ans_h;
               qDebug() << "yey!";
               ::q_num(diff_, user_id, cat_id);
               ui->q_no->setText(QString::number(question_no_hard));
               break;
           case QMessageBox::Discard:
               // Don't Save was clicked
               qDebug() << "bye";
               break;
        }
    }
}

void MainWindow::on_trueBtn_clicked()
{
    ui->trueBtn->setStyleSheet("background-color: qlineargradient"
                               "(spread:pad, x1:0, y1:0, x2:1, y2:1, "
                               "stop:0 rgba(0, 255, 0, 255), stop:1 "
                               "rgba(0, 255, 0, 255))");
    ui->falseBtn->setStyleSheet("");
    ans_e = true;
}


void MainWindow::on_falseBtn_clicked()
{
    ui->falseBtn->setStyleSheet("background-color: qlineargradient"
                               "(spread:pad, x1:0, y1:0, x2:1, y2:1, "
                               "stop:0 rgba(0, 255, 0, 255), stop:1 "
                               "rgba(0, 255, 0, 255))");
    ui->trueBtn->setStyleSheet("");
    ans_e = false;
}


void MainWindow::on_a_btn_clicked()
{
    ui->a_btn->setStyleSheet("background-color: qlineargradient"
                               "(spread:pad, x1:0, y1:0, x2:1, y2:1, "
                               "stop:0 rgba(0, 255, 0, 255), stop:1 "
                               "rgba(0, 255, 0, 255))");
    ui->b_btn->setStyleSheet("");
    ui->c_btn->setStyleSheet("");
    ui->d_btn->setStyleSheet("");
    ans_m = ui-> aLineEdit -> text();
}


void MainWindow::on_b_btn_clicked()
{
    ui->b_btn->setStyleSheet("background-color: qlineargradient"
                               "(spread:pad, x1:0, y1:0, x2:1, y2:1, "
                               "stop:0 rgba(0, 255, 0, 255), stop:1 "
                               "rgba(0, 255, 0, 255))");
    ui->a_btn->setStyleSheet("");
    ui->c_btn->setStyleSheet("");
    ui->d_btn->setStyleSheet("");
    ans_m = ui-> bLineEdit -> text();
}



void MainWindow::on_c_btn_clicked()
{
    ui->c_btn->setStyleSheet("background-color: qlineargradient"
                               "(spread:pad, x1:0, y1:0, x2:1, y2:1, "
                               "stop:0 rgba(0, 255, 0, 255), stop:1 "
                               "rgba(0, 255, 0, 255))");
    ui->a_btn->setStyleSheet("");
    ui->b_btn->setStyleSheet("");
    ui->d_btn->setStyleSheet("");
    ans_m = ui-> cLineEdit -> text();
}


void MainWindow::on_d_btn_clicked()
{
    ui->d_btn->setStyleSheet("background-color: qlineargradient"
                               "(spread:pad, x1:0, y1:0, x2:1, y2:1, "
                               "stop:0 rgba(0, 255, 0, 255), stop:1 "
                               "rgba(0, 255, 0, 255))");
    ui->a_btn->setStyleSheet("");
    ui->b_btn->setStyleSheet("");
    ui->c_btn->setStyleSheet("");
    ans_m = ui-> dLineEdit -> text();
}


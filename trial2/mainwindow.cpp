#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTime>
#include <QString>
#include <QInputDialog>
#include <QCryptographicHash>

QString difficulty_ = "";
int score_ = 0;
int correct_ans = 0;
int missed_q = 0;
bool pauseBtn_, resumeBtn_;
QString topic_ ="";
int a = 0;



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
                 "category VARCHAR(20) not null);");
    qry3.prepare("CREATE TABLE IF NOT EXISTS questionsEasy ("
                 "ID integer PRIMARY KEY AUTOINCREMENT NOT NULL,"
                 "question VARCHAR(100) not null,"
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

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
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
    ui->diff_label->setText(difficulty_);
    if (difficulty_ == "easy") {
        ui->quizBox->setCurrentIndex(0);
    } else if (difficulty_ == "medium") {
        ui->quizBox->setCurrentIndex(1);
    } else {
        ui->quizBox->setCurrentIndex(2);
    }
    timer_();
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

    QSqlQuery qry(db);
    qry.exec("SELECT name FROM users");

    while (qry.next()) {
        QString name = qry.value(0).toString();
        if (name_inps == name) {
            ui->error_msg->setText(name_inps + " is already taken");
            qDebug() << name_inps << " is already taken";
            return;
        }
    }
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

void MainWindow::on_login_btn_clicked()
{
    QString name_inpl, pass_inpl, pass_inph;
    if (!db.isOpen()) {
        qDebug() << "db not connected";
        return;
    }
    name_inpl = ui->name_inp_auth->text();
    pass_inpl = ui->pass_inp_auth->text();
    pass_inph = QCryptographicHash::hash((pass_inpl.toLocal8Bit()),QCryptographicHash::Md5);

    QSqlQuery qry(db);
    qry.exec("SELECT name, hashed_pass FROM users");

    while (qry.next()) {
        QString name = qry.value(0).toString();
        QString pass = qry.value(1).toString();
        if (name_inpl == name) {
            if (pass_inph != pass) {
                ui->error_msg_l->setText("incorrect password");
            } else {
                ui->error_msg_l->setText("Okay");
            }
        } else {
            ui->error_msg_l->setText("username '" + name_inpl + "' doesn\'t exist");
        }
    }
}


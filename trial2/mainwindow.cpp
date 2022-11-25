#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTime>
#include <QString>
#include <QInputDialog>

QString difficulty_ = "";
int score_ = 0;
int correct_ans = 0;
int missed_q = 0;
bool pauseBtn_, resumeBtn_;
QString topic_ ="";
int a = 0;


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


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->quizBox->setCurrentIndex(0);
//    connect(ui->resumeBtn, &QPushButton::clicked, this, &MainWindow::resumeBtnC);

}



MainWindow::~MainWindow()
{
    delete ui;
}

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



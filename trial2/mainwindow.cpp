#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTime>

QString difficulty_ = "";
int num = 30;

void delay()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 1);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->quizBox->setCurrentIndex(0);
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
}

void MainWindow::on_alg_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_trig_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
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
    ui->eq->setText("EASY - Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
}

void MainWindow::on_mediumBtn_clicked()
{
    difficulty_ = "medium";
    ui->stackedWidget->setCurrentIndex(4);
    ui->instruction->setText("instruction sa med");
    ui->mq->setText("MEDIUM - Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
}

void MainWindow::on_difficultBtn_clicked()
{
    difficulty_ = "hard";
    ui->stackedWidget->setCurrentIndex(4);
    ui->instruction->setText("instruction sa hard");
    ui->hq->setText("HARD - Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
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
    for (int i = 0; i < num+1; i++) {
        ui->timer->setText(QString::number(num-i));
        delay();
    }
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
    ui->stackedWidget->setCurrentIndex(6);
}


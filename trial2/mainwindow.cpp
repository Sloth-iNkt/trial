#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainmenu.h"
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_enterBtn_clicked()
{
    hide();
    mainmenu mainMenu;
    mainMenu.setModal(true);
    mainMenu.exec();
}


#include "dialog.h"
#include "ui_dialog.h"
#include "easywindow.h"
#include "mediumwindow.h"
#include "questions.h"
#include "mainmenu.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_easyBtn_clicked()
{
    hide();
    easyWindow *easyWin = new easyWindow();
    eq1.askQuestion(easyWin->ui);
    easyWin->exec();
}


void Dialog::on_mediumBtn_clicked()
{
    hide();
    mediumWindow *medWin = new mediumWindow();
    askMQues(medWin->ui);
    medWin->exec();
}


void Dialog::on_backBtn_clicked()
{
    hide();
    mainmenu mainMenu;
    mainMenu.setModal(true);
    mainMenu.exec();
}


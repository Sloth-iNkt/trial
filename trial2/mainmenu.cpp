#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "dialog.h"
#include "howtoplay.h"
#include "review.h"

mainmenu::mainmenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainmenu)
{
    ui->setupUi(this);
}

mainmenu::~mainmenu()
{
    delete ui;
}

void mainmenu::on_quizBtn_clicked()
{
    hide();
    Dialog dialog;
    dialog.setModal(true);
    dialog.exec();
}


void mainmenu::on_instrucBtn_clicked()
{
    hide();
    howtoplay htp;
    htp.setModal(true);
    htp.exec();
}


void mainmenu::on_revBtn_clicked()
{
    hide();
    review rev;
    rev.setModal(true);
    rev.exec();
}


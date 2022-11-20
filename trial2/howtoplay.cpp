#include "howtoplay.h"
#include "ui_howtoplay.h"
#include "mainmenu.h"

howtoplay::howtoplay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::howtoplay)
{
    ui->setupUi(this);
}

howtoplay::~howtoplay()
{
    delete ui;
}

void howtoplay::on_backBtn_clicked()
{
    hide();
    mainmenu mainMenu;
    mainMenu.setModal(true);
    mainMenu.exec();
}


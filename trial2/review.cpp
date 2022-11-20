#include "review.h"
#include "ui_review.h"
#include "mainmenu.h"

review::review(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::review)
{
    ui->setupUi(this);
}

review::~review()
{
    delete ui;
}

void review::on_backBtn_clicked()
{
    hide();
    mainmenu mainMenu;
    mainMenu.setModal(true);
    mainMenu.exec();
}


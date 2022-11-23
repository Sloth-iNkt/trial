#include "mediumwindow.h"
#include "ui_mediumwindow.h"
//#include "questions.h"

mediumWindow::mediumWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mediumWindow)
{
    ui->setupUi(this);
}

mediumWindow::~mediumWindow()
{
    delete ui;
}

void mediumWindow::on_medText_textChanged()
{



}


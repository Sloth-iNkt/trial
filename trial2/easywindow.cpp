#include "easywindow.h"
#include "ui_easywindow.h"
//#include "questions.h"

easyWindow::easyWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::easyWindow)
{
    ui->setupUi(this);
}

easyWindow::~easyWindow()
{
    delete ui;
}

//    eq2.askQuestion(easyWin->ui);




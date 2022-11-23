/********************************************************************************
** Form generated from reading UI file 'easywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EASYWINDOW_H
#define UI_EASYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_easyWindow
{
public:
    QPushButton *optnThree;
    QLabel *qstnLbl;
    QPushButton *optnOne;
    QPushButton *optnFour;
    QPushButton *optnTwo;

    void setupUi(QDialog *easyWindow)
    {
        if (easyWindow->objectName().isEmpty())
            easyWindow->setObjectName("easyWindow");
        easyWindow->resize(400, 300);
        optnThree = new QPushButton(easyWindow);
        optnThree->setObjectName("optnThree");
        optnThree->setGeometry(QRect(60, 240, 111, 31));
        qstnLbl = new QLabel(easyWindow);
        qstnLbl->setObjectName("qstnLbl");
        qstnLbl->setGeometry(QRect(60, 50, 261, 61));
        qstnLbl->setAlignment(Qt::AlignCenter);
        optnOne = new QPushButton(easyWindow);
        optnOne->setObjectName("optnOne");
        optnOne->setGeometry(QRect(60, 190, 111, 31));
        optnFour = new QPushButton(easyWindow);
        optnFour->setObjectName("optnFour");
        optnFour->setGeometry(QRect(220, 240, 111, 31));
        optnTwo = new QPushButton(easyWindow);
        optnTwo->setObjectName("optnTwo");
        optnTwo->setGeometry(QRect(220, 190, 111, 31));

        retranslateUi(easyWindow);

        QMetaObject::connectSlotsByName(easyWindow);
    } // setupUi

    void retranslateUi(QDialog *easyWindow)
    {
        easyWindow->setWindowTitle(QCoreApplication::translate("easyWindow", "Dialog", nullptr));
        optnThree->setText(QCoreApplication::translate("easyWindow", "option 3", nullptr));
        qstnLbl->setText(QCoreApplication::translate("easyWindow", "Question", nullptr));
        optnOne->setText(QCoreApplication::translate("easyWindow", "option 1", nullptr));
        optnFour->setText(QCoreApplication::translate("easyWindow", "option 4", nullptr));
        optnTwo->setText(QCoreApplication::translate("easyWindow", "option 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class easyWindow: public Ui_easyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EASYWINDOW_H

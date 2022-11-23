/********************************************************************************
** Form generated from reading UI file 'mediumwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIUMWINDOW_H
#define UI_MEDIUMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_mediumWindow
{
public:
    QLabel *qstnLbl;

    void setupUi(QDialog *mediumWindow)
    {
        if (mediumWindow->objectName().isEmpty())
            mediumWindow->setObjectName("mediumWindow");
        mediumWindow->resize(400, 300);
        qstnLbl = new QLabel(mediumWindow);
        qstnLbl->setObjectName("qstnLbl");
        qstnLbl->setGeometry(QRect(60, 40, 261, 61));
        qstnLbl->setAlignment(Qt::AlignCenter);

        retranslateUi(mediumWindow);

        QMetaObject::connectSlotsByName(mediumWindow);
    } // setupUi

    void retranslateUi(QDialog *mediumWindow)
    {
        mediumWindow->setWindowTitle(QCoreApplication::translate("mediumWindow", "Dialog", nullptr));
        qstnLbl->setText(QCoreApplication::translate("mediumWindow", "Question", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mediumWindow: public Ui_mediumWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIUMWINDOW_H

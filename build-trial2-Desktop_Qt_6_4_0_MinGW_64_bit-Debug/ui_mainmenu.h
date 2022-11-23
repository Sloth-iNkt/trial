/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_mainmenu
{
public:
    QPushButton *quizBtn;
    QPushButton *ldrbrdBtn;
    QPushButton *revBtn;
    QPushButton *instrucBtn;

    void setupUi(QDialog *mainmenu)
    {
        if (mainmenu->objectName().isEmpty())
            mainmenu->setObjectName("mainmenu");
        mainmenu->resize(361, 280);
        quizBtn = new QPushButton(mainmenu);
        quizBtn->setObjectName("quizBtn");
        quizBtn->setGeometry(QRect(30, 60, 301, 41));
        ldrbrdBtn = new QPushButton(mainmenu);
        ldrbrdBtn->setObjectName("ldrbrdBtn");
        ldrbrdBtn->setGeometry(QRect(30, 210, 301, 41));
        revBtn = new QPushButton(mainmenu);
        revBtn->setObjectName("revBtn");
        revBtn->setGeometry(QRect(30, 110, 301, 41));
        instrucBtn = new QPushButton(mainmenu);
        instrucBtn->setObjectName("instrucBtn");
        instrucBtn->setGeometry(QRect(30, 160, 301, 41));

        retranslateUi(mainmenu);

        QMetaObject::connectSlotsByName(mainmenu);
    } // setupUi

    void retranslateUi(QDialog *mainmenu)
    {
        mainmenu->setWindowTitle(QCoreApplication::translate("mainmenu", "Dialog", nullptr));
        quizBtn->setText(QCoreApplication::translate("mainmenu", "Start Quiz", nullptr));
        ldrbrdBtn->setText(QCoreApplication::translate("mainmenu", "Leaderboards", nullptr));
        revBtn->setText(QCoreApplication::translate("mainmenu", "Review", nullptr));
        instrucBtn->setText(QCoreApplication::translate("mainmenu", "How to Play", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainmenu: public Ui_mainmenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H

/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *shuffledBtn;
    QPushButton *easyBtn;
    QPushButton *difficultBtn;
    QPushButton *mediumBtn;
    QPushButton *backBtn;
    QLabel *difficulty;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(362, 330);
        shuffledBtn = new QPushButton(Dialog);
        shuffledBtn->setObjectName("shuffledBtn");
        shuffledBtn->setGeometry(QRect(30, 220, 301, 41));
        easyBtn = new QPushButton(Dialog);
        easyBtn->setObjectName("easyBtn");
        easyBtn->setGeometry(QRect(30, 70, 301, 41));
        difficultBtn = new QPushButton(Dialog);
        difficultBtn->setObjectName("difficultBtn");
        difficultBtn->setGeometry(QRect(30, 170, 301, 41));
        mediumBtn = new QPushButton(Dialog);
        mediumBtn->setObjectName("mediumBtn");
        mediumBtn->setGeometry(QRect(30, 120, 301, 41));
        backBtn = new QPushButton(Dialog);
        backBtn->setObjectName("backBtn");
        backBtn->setGeometry(QRect(30, 270, 301, 41));
        difficulty = new QLabel(Dialog);
        difficulty->setObjectName("difficulty");
        difficulty->setGeometry(QRect(130, 20, 111, 41));
        QFont font;
        font.setPointSize(12);
        difficulty->setFont(font);
        difficulty->setLayoutDirection(Qt::LeftToRight);
        difficulty->setScaledContents(false);
        difficulty->setAlignment(Qt::AlignCenter);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        shuffledBtn->setText(QCoreApplication::translate("Dialog", "Custom", nullptr));
        easyBtn->setText(QCoreApplication::translate("Dialog", "Easy (Multiple Choice)", nullptr));
        difficultBtn->setText(QCoreApplication::translate("Dialog", "Difficult", nullptr));
        mediumBtn->setText(QCoreApplication::translate("Dialog", "Medium (Identification)", nullptr));
        backBtn->setText(QCoreApplication::translate("Dialog", "Back", nullptr));
        difficulty->setText(QCoreApplication::translate("Dialog", "DIFFICULTY", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H

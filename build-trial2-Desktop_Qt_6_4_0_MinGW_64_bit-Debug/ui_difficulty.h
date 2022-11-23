/********************************************************************************
** Form generated from reading UI file 'difficulty.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIFFICULTY_H
#define UI_DIFFICULTY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_difficulty
{
public:
    QPushButton *easyBtn;
    QPushButton *difficultBtn;
    QPushButton *mediumBtn;
    QPushButton *backBtn;
    QLabel *difficulty_lbl;
    QPushButton *main_menu;

    void setupUi(QDialog *difficulty)
    {
        if (difficulty->objectName().isEmpty())
            difficulty->setObjectName("difficulty");
        difficulty->resize(362, 330);
        easyBtn = new QPushButton(difficulty);
        easyBtn->setObjectName("easyBtn");
        easyBtn->setGeometry(QRect(30, 70, 301, 41));
        difficultBtn = new QPushButton(difficulty);
        difficultBtn->setObjectName("difficultBtn");
        difficultBtn->setGeometry(QRect(30, 170, 301, 41));
        mediumBtn = new QPushButton(difficulty);
        mediumBtn->setObjectName("mediumBtn");
        mediumBtn->setGeometry(QRect(30, 120, 301, 41));
        backBtn = new QPushButton(difficulty);
        backBtn->setObjectName("backBtn");
        backBtn->setGeometry(QRect(30, 220, 301, 41));
        difficulty_lbl = new QLabel(difficulty);
        difficulty_lbl->setObjectName("difficulty_lbl");
        difficulty_lbl->setGeometry(QRect(130, 20, 111, 41));
        QFont font;
        font.setPointSize(12);
        difficulty_lbl->setFont(font);
        difficulty_lbl->setLayoutDirection(Qt::LeftToRight);
        difficulty_lbl->setScaledContents(false);
        difficulty_lbl->setAlignment(Qt::AlignCenter);
        main_menu = new QPushButton(difficulty);
        main_menu->setObjectName("main_menu");
        main_menu->setGeometry(QRect(30, 270, 301, 41));

        retranslateUi(difficulty);

        QMetaObject::connectSlotsByName(difficulty);
    } // setupUi

    void retranslateUi(QDialog *difficulty)
    {
        difficulty->setWindowTitle(QCoreApplication::translate("difficulty", "Difficulty", nullptr));
        easyBtn->setText(QCoreApplication::translate("difficulty", "Easy (True or False)", nullptr));
        difficultBtn->setText(QCoreApplication::translate("difficulty", "Difficult (Identification)", nullptr));
        mediumBtn->setText(QCoreApplication::translate("difficulty", "Medium (Multiple Choice)", nullptr));
        backBtn->setText(QCoreApplication::translate("difficulty", "Back", nullptr));
        difficulty_lbl->setText(QCoreApplication::translate("difficulty", "DIFFICULTY", nullptr));
        main_menu->setText(QCoreApplication::translate("difficulty", "Main Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class difficulty: public Ui_difficulty {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIFFICULTY_H

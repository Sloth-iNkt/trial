/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *main_page;
    QLabel *title;
    QPushButton *pushButton;
    QWidget *main_menu;
    QPushButton *quizBtn;
    QPushButton *revBtn;
    QPushButton *instrucBtn;
    QPushButton *ldrbrdBtn;
    QWidget *category;
    QLabel *cat_title;
    QPushButton *cus_btn;
    QPushButton *back_btn;
    QGroupBox *groupBox;
    QPushButton *alg_btn;
    QPushButton *geo_btn;
    QPushButton *trig_btn;
    QWidget *difficulty;
    QLabel *difficulty_lbl;
    QPushButton *easyBtn;
    QPushButton *mediumBtn;
    QPushButton *difficultBtn;
    QPushButton *backBtn;
    QPushButton *main_menu_2;
    QWidget *instruction_win;
    QPushButton *okaybtn;
    QLabel *instruction;
    QWidget *quiz;
    QLabel *diff_label;
    QLabel *score;
    QLabel *label;
    QStackedWidget *easy;
    QWidget *tof1;
    QLabel *eq1;
    QPushButton *t1;
    QPushButton *f1;
    QWidget *tof2;
    QLabel *eq2;
    QPushButton *f2;
    QPushButton *t2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(359, 352);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, -10, 361, 361));
        main_page = new QWidget();
        main_page->setObjectName("main_page");
        title = new QLabel(main_page);
        title->setObjectName("title");
        title->setGeometry(QRect(150, 90, 63, 20));
        pushButton = new QPushButton(main_page);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(120, 220, 93, 29));
        stackedWidget->addWidget(main_page);
        main_menu = new QWidget();
        main_menu->setObjectName("main_menu");
        quizBtn = new QPushButton(main_menu);
        quizBtn->setObjectName("quizBtn");
        quizBtn->setGeometry(QRect(30, 50, 301, 41));
        revBtn = new QPushButton(main_menu);
        revBtn->setObjectName("revBtn");
        revBtn->setGeometry(QRect(30, 100, 301, 41));
        instrucBtn = new QPushButton(main_menu);
        instrucBtn->setObjectName("instrucBtn");
        instrucBtn->setGeometry(QRect(30, 160, 301, 41));
        ldrbrdBtn = new QPushButton(main_menu);
        ldrbrdBtn->setObjectName("ldrbrdBtn");
        ldrbrdBtn->setGeometry(QRect(30, 220, 301, 41));
        stackedWidget->addWidget(main_menu);
        category = new QWidget();
        category->setObjectName("category");
        cat_title = new QLabel(category);
        cat_title->setObjectName("cat_title");
        cat_title->setGeometry(QRect(140, 20, 111, 31));
        QFont font;
        font.setPointSize(12);
        cat_title->setFont(font);
        cat_title->setAlignment(Qt::AlignCenter);
        cus_btn = new QPushButton(category);
        cus_btn->setObjectName("cus_btn");
        cus_btn->setGeometry(QRect(140, 210, 101, 29));
        back_btn = new QPushButton(category);
        back_btn->setObjectName("back_btn");
        back_btn->setGeometry(QRect(140, 250, 101, 29));
        groupBox = new QGroupBox(category);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(90, 60, 161, 251));
        alg_btn = new QPushButton(groupBox);
        alg_btn->setObjectName("alg_btn");
        alg_btn->setGeometry(QRect(10, 30, 93, 29));
        geo_btn = new QPushButton(groupBox);
        geo_btn->setObjectName("geo_btn");
        geo_btn->setGeometry(QRect(10, 70, 93, 29));
        trig_btn = new QPushButton(groupBox);
        trig_btn->setObjectName("trig_btn");
        trig_btn->setGeometry(QRect(20, 110, 101, 29));
        stackedWidget->addWidget(category);
        difficulty = new QWidget();
        difficulty->setObjectName("difficulty");
        difficulty_lbl = new QLabel(difficulty);
        difficulty_lbl->setObjectName("difficulty_lbl");
        difficulty_lbl->setGeometry(QRect(130, 20, 111, 41));
        difficulty_lbl->setFont(font);
        difficulty_lbl->setLayoutDirection(Qt::LeftToRight);
        difficulty_lbl->setScaledContents(false);
        difficulty_lbl->setAlignment(Qt::AlignCenter);
        easyBtn = new QPushButton(difficulty);
        easyBtn->setObjectName("easyBtn");
        easyBtn->setGeometry(QRect(30, 70, 301, 41));
        mediumBtn = new QPushButton(difficulty);
        mediumBtn->setObjectName("mediumBtn");
        mediumBtn->setGeometry(QRect(30, 120, 301, 41));
        difficultBtn = new QPushButton(difficulty);
        difficultBtn->setObjectName("difficultBtn");
        difficultBtn->setGeometry(QRect(30, 170, 301, 41));
        backBtn = new QPushButton(difficulty);
        backBtn->setObjectName("backBtn");
        backBtn->setGeometry(QRect(30, 220, 301, 41));
        main_menu_2 = new QPushButton(difficulty);
        main_menu_2->setObjectName("main_menu_2");
        main_menu_2->setGeometry(QRect(30, 270, 301, 41));
        stackedWidget->addWidget(difficulty);
        instruction_win = new QWidget();
        instruction_win->setObjectName("instruction_win");
        okaybtn = new QPushButton(instruction_win);
        okaybtn->setObjectName("okaybtn");
        okaybtn->setGeometry(QRect(130, 230, 93, 29));
        instruction = new QLabel(instruction_win);
        instruction->setObjectName("instruction");
        instruction->setGeometry(QRect(70, 70, 221, 131));
        stackedWidget->addWidget(instruction_win);
        quiz = new QWidget();
        quiz->setObjectName("quiz");
        diff_label = new QLabel(quiz);
        diff_label->setObjectName("diff_label");
        diff_label->setGeometry(QRect(10, 20, 63, 20));
        score = new QLabel(quiz);
        score->setObjectName("score");
        score->setGeometry(QRect(10, 40, 63, 20));
        label = new QLabel(quiz);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 20, 63, 20));
        easy = new QStackedWidget(quiz);
        easy->setObjectName("easy");
        easy->setGeometry(QRect(20, 80, 311, 251));
        easy->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));
        tof1 = new QWidget();
        tof1->setObjectName("tof1");
        eq1 = new QLabel(tof1);
        eq1->setObjectName("eq1");
        eq1->setGeometry(QRect(20, 30, 251, 61));
        t1 = new QPushButton(tof1);
        t1->setObjectName("t1");
        t1->setGeometry(QRect(30, 160, 93, 29));
        f1 = new QPushButton(tof1);
        f1->setObjectName("f1");
        f1->setGeometry(QRect(190, 160, 93, 29));
        easy->addWidget(tof1);
        tof2 = new QWidget();
        tof2->setObjectName("tof2");
        eq2 = new QLabel(tof2);
        eq2->setObjectName("eq2");
        eq2->setGeometry(QRect(30, 30, 251, 61));
        f2 = new QPushButton(tof2);
        f2->setObjectName("f2");
        f2->setGeometry(QRect(190, 150, 93, 29));
        t2 = new QPushButton(tof2);
        t2->setObjectName("t2");
        t2->setGeometry(QRect(20, 150, 93, 29));
        easy->addWidget(tof2);
        stackedWidget->addWidget(quiz);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(5);
        easy->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "trial", nullptr));
        title->setText(QCoreApplication::translate("MainWindow", "Trial", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Enter", nullptr));
        quizBtn->setText(QCoreApplication::translate("MainWindow", "Start Quiz", nullptr));
        revBtn->setText(QCoreApplication::translate("MainWindow", "Review", nullptr));
        instrucBtn->setText(QCoreApplication::translate("MainWindow", "How to Play", nullptr));
        ldrbrdBtn->setText(QCoreApplication::translate("MainWindow", "Leaderboards", nullptr));
        cat_title->setText(QCoreApplication::translate("MainWindow", "CATEGORY", nullptr));
        cus_btn->setText(QCoreApplication::translate("MainWindow", "Customized", nullptr));
        back_btn->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        groupBox->setTitle(QString());
        alg_btn->setText(QCoreApplication::translate("MainWindow", "Algebra", nullptr));
        geo_btn->setText(QCoreApplication::translate("MainWindow", "Geometry", nullptr));
        trig_btn->setText(QCoreApplication::translate("MainWindow", "Trigonometry", nullptr));
        difficulty_lbl->setText(QCoreApplication::translate("MainWindow", "DIFFICULTY", nullptr));
        easyBtn->setText(QCoreApplication::translate("MainWindow", "Easy (True or False)", nullptr));
        mediumBtn->setText(QCoreApplication::translate("MainWindow", "Medium (Multiple Choice)", nullptr));
        difficultBtn->setText(QCoreApplication::translate("MainWindow", "Difficult (Identification)", nullptr));
        backBtn->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        main_menu_2->setText(QCoreApplication::translate("MainWindow", "Main Menu", nullptr));
        okaybtn->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        instruction->setText(QString());
        diff_label->setText(QCoreApplication::translate("MainWindow", "diff", nullptr));
        score->setText(QCoreApplication::translate("MainWindow", "Score:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Time", nullptr));
        eq1->setText(QCoreApplication::translate("MainWindow", "Question 1", nullptr));
        t1->setText(QCoreApplication::translate("MainWindow", "True", nullptr));
        f1->setText(QCoreApplication::translate("MainWindow", "False", nullptr));
        eq2->setText(QCoreApplication::translate("MainWindow", "Question 2", nullptr));
        f2->setText(QCoreApplication::translate("MainWindow", "False", nullptr));
        t2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

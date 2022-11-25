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
#include <QtWidgets/QLineEdit>
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
    QPushButton *ldrbrdBtn;
    QWidget *category;
    QLabel *cat_title;
    QGroupBox *groupBox;
    QPushButton *alg_btn;
    QPushButton *geo_btn;
    QPushButton *trig_btn;
    QPushButton *cus_btn;
    QPushButton *back_btn;
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
    QLabel *time;
    QStackedWidget *quizBox;
    QWidget *easy;
    QGroupBox *easyBox;
    QLabel *eq;
    QPushButton *t;
    QPushButton *f;
    QWidget *medium;
    QGroupBox *mediumBox;
    QLabel *mq;
    QPushButton *a;
    QPushButton *b;
    QPushButton *c;
    QPushButton *d;
    QWidget *hard;
    QGroupBox *hardBox;
    QLabel *hq;
    QLineEdit *ans_inp;
    QPushButton *submit_btn;
    QLabel *timer;
    QPushButton *pause_btn;
    QLabel *label;
    QLabel *label_2;
    QWidget *pause_win;
    QLabel *pause_lbl;
    QPushButton *resumeBtn;
    QPushButton *retryBtn;
    QPushButton *menuBtnP;
    QWidget *result;
    QLabel *remarks;
    QLabel *scr_lbl;
    QLabel *ca_lbl;
    QLabel *c_ans;
    QLabel *scre;
    QLabel *name;
    QLineEdit *name_inp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(373, 371);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 371, 371));
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
        quizBtn->setGeometry(QRect(30, 100, 301, 41));
        revBtn = new QPushButton(main_menu);
        revBtn->setObjectName("revBtn");
        revBtn->setGeometry(QRect(30, 160, 301, 41));
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
        groupBox = new QGroupBox(category);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(130, 70, 120, 251));
        alg_btn = new QPushButton(groupBox);
        alg_btn->setObjectName("alg_btn");
        alg_btn->setGeometry(QRect(10, 30, 93, 29));
        geo_btn = new QPushButton(groupBox);
        geo_btn->setObjectName("geo_btn");
        geo_btn->setGeometry(QRect(10, 70, 93, 29));
        trig_btn = new QPushButton(groupBox);
        trig_btn->setObjectName("trig_btn");
        trig_btn->setGeometry(QRect(10, 110, 101, 29));
        cus_btn = new QPushButton(groupBox);
        cus_btn->setObjectName("cus_btn");
        cus_btn->setGeometry(QRect(10, 150, 101, 29));
        back_btn = new QPushButton(groupBox);
        back_btn->setObjectName("back_btn");
        back_btn->setGeometry(QRect(10, 190, 101, 29));
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
        diff_label->setGeometry(QRect(10, 50, 63, 20));
        score = new QLabel(quiz);
        score->setObjectName("score");
        score->setGeometry(QRect(10, 70, 63, 20));
        time = new QLabel(quiz);
        time->setObjectName("time");
        time->setGeometry(QRect(10, 110, 63, 20));
        quizBox = new QStackedWidget(quiz);
        quizBox->setObjectName("quizBox");
        quizBox->setGeometry(QRect(30, 130, 311, 211));
        quizBox->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));
        easy = new QWidget();
        easy->setObjectName("easy");
        easyBox = new QGroupBox(easy);
        easyBox->setObjectName("easyBox");
        easyBox->setGeometry(QRect(10, 20, 281, 181));
        eq = new QLabel(easyBox);
        eq->setObjectName("eq");
        eq->setGeometry(QRect(30, 30, 211, 51));
        t = new QPushButton(easyBox);
        t->setObjectName("t");
        t->setGeometry(QRect(20, 140, 93, 29));
        f = new QPushButton(easyBox);
        f->setObjectName("f");
        f->setGeometry(QRect(160, 140, 93, 29));
        quizBox->addWidget(easy);
        medium = new QWidget();
        medium->setObjectName("medium");
        mediumBox = new QGroupBox(medium);
        mediumBox->setObjectName("mediumBox");
        mediumBox->setGeometry(QRect(20, 40, 271, 201));
        mq = new QLabel(mediumBox);
        mq->setObjectName("mq");
        mq->setGeometry(QRect(30, 30, 211, 31));
        a = new QPushButton(mediumBox);
        a->setObjectName("a");
        a->setGeometry(QRect(20, 70, 231, 29));
        b = new QPushButton(mediumBox);
        b->setObjectName("b");
        b->setGeometry(QRect(20, 100, 231, 29));
        c = new QPushButton(mediumBox);
        c->setObjectName("c");
        c->setGeometry(QRect(20, 130, 231, 29));
        d = new QPushButton(mediumBox);
        d->setObjectName("d");
        d->setGeometry(QRect(20, 160, 231, 29));
        quizBox->addWidget(medium);
        hard = new QWidget();
        hard->setObjectName("hard");
        hardBox = new QGroupBox(hard);
        hardBox->setObjectName("hardBox");
        hardBox->setGeometry(QRect(20, 30, 271, 201));
        hq = new QLabel(hardBox);
        hq->setObjectName("hq");
        hq->setGeometry(QRect(40, 30, 201, 41));
        ans_inp = new QLineEdit(hardBox);
        ans_inp->setObjectName("ans_inp");
        ans_inp->setGeometry(QRect(30, 110, 191, 31));
        ans_inp->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        submit_btn = new QPushButton(hardBox);
        submit_btn->setObjectName("submit_btn");
        submit_btn->setGeometry(QRect(80, 150, 93, 29));
        quizBox->addWidget(hard);
        timer = new QLabel(quiz);
        timer->setObjectName("timer");
        timer->setGeometry(QRect(120, 20, 161, 51));
        pause_btn = new QPushButton(quiz);
        pause_btn->setObjectName("pause_btn");
        pause_btn->setGeometry(QRect(10, 0, 93, 29));
        label = new QLabel(quiz);
        label->setObjectName("label");
        label->setGeometry(QRect(220, 10, 91, 20));
        label_2 = new QLabel(quiz);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(320, 10, 63, 20));
        stackedWidget->addWidget(quiz);
        pause_win = new QWidget();
        pause_win->setObjectName("pause_win");
        pause_lbl = new QLabel(pause_win);
        pause_lbl->setObjectName("pause_lbl");
        pause_lbl->setGeometry(QRect(110, 20, 141, 71));
        resumeBtn = new QPushButton(pause_win);
        resumeBtn->setObjectName("resumeBtn");
        resumeBtn->setGeometry(QRect(130, 130, 93, 29));
        retryBtn = new QPushButton(pause_win);
        retryBtn->setObjectName("retryBtn");
        retryBtn->setGeometry(QRect(130, 170, 93, 29));
        menuBtnP = new QPushButton(pause_win);
        menuBtnP->setObjectName("menuBtnP");
        menuBtnP->setGeometry(QRect(130, 210, 93, 29));
        stackedWidget->addWidget(pause_win);
        result = new QWidget();
        result->setObjectName("result");
        remarks = new QLabel(result);
        remarks->setObjectName("remarks");
        remarks->setGeometry(QRect(130, 40, 111, 51));
        scr_lbl = new QLabel(result);
        scr_lbl->setObjectName("scr_lbl");
        scr_lbl->setGeometry(QRect(30, 160, 71, 31));
        ca_lbl = new QLabel(result);
        ca_lbl->setObjectName("ca_lbl");
        ca_lbl->setGeometry(QRect(30, 120, 121, 31));
        c_ans = new QLabel(result);
        c_ans->setObjectName("c_ans");
        c_ans->setGeometry(QRect(170, 130, 63, 20));
        scre = new QLabel(result);
        scre->setObjectName("scre");
        scre->setGeometry(QRect(170, 160, 63, 20));
        name = new QLabel(result);
        name->setObjectName("name");
        name->setGeometry(QRect(30, 210, 63, 20));
        name_inp = new QLineEdit(result);
        name_inp->setObjectName("name_inp");
        name_inp->setGeometry(QRect(160, 210, 113, 26));
        stackedWidget->addWidget(result);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(5);
        quizBox->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "trial", nullptr));
        title->setText(QCoreApplication::translate("MainWindow", "Trial", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Enter", nullptr));
        quizBtn->setText(QCoreApplication::translate("MainWindow", "Start Quiz", nullptr));
        revBtn->setText(QCoreApplication::translate("MainWindow", "Review", nullptr));
        ldrbrdBtn->setText(QCoreApplication::translate("MainWindow", "Leaderboards", nullptr));
        cat_title->setText(QCoreApplication::translate("MainWindow", "CATEGORY", nullptr));
        groupBox->setTitle(QString());
        alg_btn->setText(QCoreApplication::translate("MainWindow", "Algebra", nullptr));
        geo_btn->setText(QCoreApplication::translate("MainWindow", "Geometry", nullptr));
        trig_btn->setText(QCoreApplication::translate("MainWindow", "Trigonometry", nullptr));
        cus_btn->setText(QCoreApplication::translate("MainWindow", "Customized", nullptr));
        back_btn->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
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
        time->setText(QCoreApplication::translate("MainWindow", "Time", nullptr));
        easyBox->setTitle(QCoreApplication::translate("MainWindow", "Easy", nullptr));
        eq->setText(QCoreApplication::translate("MainWindow", "Question 1", nullptr));
        t->setText(QCoreApplication::translate("MainWindow", "true", nullptr));
        f->setText(QCoreApplication::translate("MainWindow", "False", nullptr));
        mediumBox->setTitle(QCoreApplication::translate("MainWindow", "Medium", nullptr));
        mq->setText(QCoreApplication::translate("MainWindow", "Question 2", nullptr));
        a->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        b->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        c->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        d->setText(QCoreApplication::translate("MainWindow", "D", nullptr));
        hardBox->setTitle(QCoreApplication::translate("MainWindow", "hard", nullptr));
        hq->setText(QCoreApplication::translate("MainWindow", "Question 1", nullptr));
        submit_btn->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        timer->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pause_btn->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Prepared by:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        pause_lbl->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        resumeBtn->setText(QCoreApplication::translate("MainWindow", "Resume", nullptr));
        retryBtn->setText(QCoreApplication::translate("MainWindow", "Retry", nullptr));
        menuBtnP->setText(QCoreApplication::translate("MainWindow", "Main Menu", nullptr));
        remarks->setText(QCoreApplication::translate("MainWindow", "Passed or Not", nullptr));
        scr_lbl->setText(QCoreApplication::translate("MainWindow", "Score:", nullptr));
        ca_lbl->setText(QCoreApplication::translate("MainWindow", "Correct Answer/s:", nullptr));
        c_ans->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        scre->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        name->setText(QCoreApplication::translate("MainWindow", "Name: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Ui::MainWindow *ui;

private slots:
    void on_pushButton_clicked();

    void on_quizBtn_clicked();

    void on_trig_btn_clicked();

    void on_geo_btn_clicked();

    void on_alg_btn_clicked();

    void on_back_btn_clicked();

    void on_backBtn_clicked();

    void on_main_menu_2_clicked();

    void on_easyBtn_clicked();

    void on_mediumBtn_clicked();

    void on_difficultBtn_clicked();

    void on_okaybtn_clicked();

    void on_t1_clicked();

private:

};




//huhu gumana ka na plz hauf na multi defn yan ala nga sabi

#endif // MAINWINDOW_H

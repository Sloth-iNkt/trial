#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>

namespace Ui {
class mainmenu;
}

class mainmenu : public QDialog
{
    Q_OBJECT

public:
    explicit mainmenu(QWidget *parent = nullptr);
    ~mainmenu();

private slots:
    void on_quizBtn_clicked();

    void on_instrucBtn_clicked();

    void on_revBtn_clicked();

private:
    Ui::mainmenu *ui;
};

#endif // MAINMENU_H

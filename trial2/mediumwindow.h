#ifndef MEDIUMWINDOW_H
#define MEDIUMWINDOW_H

#include <QDialog>

namespace Ui {
class mediumWindow;
}

class mediumWindow : public QDialog
{
    Q_OBJECT

public:
    explicit mediumWindow(QWidget *parent = nullptr);
    ~mediumWindow();
    Ui::mediumWindow *ui;

private slots:
//    void on_medText_textChanged();

private:

};

#endif // MEDIUMWINDOW_H

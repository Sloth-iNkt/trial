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

private:
    Ui::mediumWindow *ui;
};

#endif // MEDIUMWINDOW_H

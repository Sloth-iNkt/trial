#ifndef EASYWINDOW_H
#define EASYWINDOW_H

#include <QDialog>

namespace Ui {
class easyWindow;
}

class easyWindow : public QDialog
{
    Q_OBJECT

public:
    explicit easyWindow(QWidget *parent = nullptr);
    ~easyWindow();
    Ui::easyWindow *ui;

private:

};

#endif // EASYWINDOW_H

#ifndef GETDETAILS_H
#define GETDETAILS_H

#include <QMainWindow>

namespace Ui {
class getdetails;
}

class getdetails : public QMainWindow
{
    Q_OBJECT

public:
    explicit getdetails(QWidget *parent = nullptr);
    ~getdetails();

private:
    Ui::getdetails *ui;
};

#endif // GETDETAILS_H

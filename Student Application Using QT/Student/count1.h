#ifndef COUNT1_H
#define COUNT1_H

#include <QMainWindow>
#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <deletedetails.h>
#include <QTableView>


class menu1;

namespace Ui {
class count1;
}

class count1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit count1(QWidget *parent = nullptr);
    ~count1();

private slots:
    void on_ok_clicked();

    void on_menu_clicked();

private:
    Ui::count1 *ui;
    QSqlDatabase db;
    menu1 *mu;
    count1 *ct;

};

#endif // COUNT1_H

#ifndef DISPLAYDETAILS_H
#define DISPLAYDETAILS_H

#include <QMainWindow>
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
class displaydetails;
}

class displaydetails : public QMainWindow
{
    Q_OBJECT

public:
    explicit displaydetails(QWidget *parent = nullptr);
    ~displaydetails();

private slots:
    void on_OK_clicked();

   // void on_GET_clicked();
    //void checkExistingData();

    void on_menu_clicked();

private:
    Ui::displaydetails *ui;
    QSqlDatabase db;
    menu1 *mu;
    displaydetails *dis;
};

#endif // DISPLAYDETAILS_H

#ifndef MENU1_H
#define MENU1_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <add.h>
#include <deletedetails.h>
#include <modifydetails.h>
#include <displaydetails.h>
#include <highest.h>
#include <lowest.h>
#include <searchdetails.h>
#include <count1.h>
#include <QDialog>


class MainWindow;
class menu;

namespace Ui {
class menu1;
}

class menu1 : public QDialog
{
    Q_OBJECT

public:
    explicit menu1(QWidget *parent = nullptr);
    ~menu1();

private slots:

    void on_ADD_clicked();

   // void on_HomePage_clicked();

    //void on_Back_clicked();

    void on_deletedetails_clicked();

    void on_modify_clicked();

    void on_get_clicked();

    void on_highest_clicked();

   // void on_pushButton_2_clicked();

    void on_lowest_clicked();

    void on_searchdetails_clicked();

    //void on_status_clicked();

    void on_HOMEPAGE_clicked();

    //void on_status_clicked();

    void on_COUNT_clicked();

private:
    Ui::menu1 *ui;
    QSqlDatabase db;
    MainWindow *mw;
    menu *m;
    menu1 *mu;
    add *add1;
    deletedetails *del;
    modifydetails *mod;
    displaydetails *dis;
    highest *h;
    lowest *l;
    searchdetails *s;
    count1 *ct;

};

#endif // MENU1_H

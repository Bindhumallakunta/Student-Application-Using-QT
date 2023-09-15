#ifndef COUNT_H
#define COUNT_H
#include <QMainWindow>
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
class count;
}

class Ui::count : public QMainWindow
{
    Q_OBJECT

public:
    explicit status1(QWidget *parent = nullptr);
    ~status1();
    //void checkExistingData();

private slots:
               //void on_ok_clicked();

    void on_ok_clicked();

    // void on_graph_clicked();

    //void on_status_clicked();

    void on_menu_clicked();

private:
    Ui::status1 *ui;
    QSqlDatabase db;
    menu1 *mu;
    count *ct;

};


#endif // COUNT_H

//#include <QMainWindow>
//#include <QMainWindow>
//#include <QMainWindow>
//#include <QDialog>
//#include <QtSql>
//#include <QtDebug>
//#include <QFileInfo>
//#include <QMessageBox>
//#include <deletedetails.h>
//#include <QTableView>

//class menu1;

//namespace Ui {
//class status1;
//}

//class status1 : public QMainWindow
//{
//    Q_OBJECT

//public:
//    explicit status1(QWidget *parent = nullptr);
//    ~status1();
//    //void checkExistingData();

//private slots:
//    //void on_ok_clicked();

//private:
//    Ui::status1 *ui;
//    QSqlDatabase db;
//    menu1 *mu;
//    status1 *ss;
//};

//#endif // COUNT_H


//#ifndef STATUS1_H
//#define STATUS1_H

//#include <QMainWindow>
//#include <QMainWindow>
//#include <QMainWindow>
//#include <QDialog>
//#include <QtSql>
//#include <QtDebug>
//#include <QFileInfo>
//#include <QMessageBox>
//#include <deletedetails.h>
//#include <QTableView>


//class menu1;

//namespace Ui {
//class status1;
//}

//class status1 : public QMainWindow
//{
//    Q_OBJECT

//public:
//    explicit status1(QWidget *parent = nullptr);
//    ~status1();
//    //void checkExistingData();

//private slots:
//               //void on_ok_clicked();

//    void on_ok_clicked();

//   // void on_graph_clicked();

//    //void on_status_clicked();

//    void on_menu_clicked();

//private:
//    Ui::status1 *ui;
//    QSqlDatabase db;
//    menu1 *mu;
//    status1 *ss;

//};

//#endif // STATUS1_H

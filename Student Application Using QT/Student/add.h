#ifndef ADD_H
#define ADD_H

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
class add;
}

class add : public QMainWindow
{
    Q_OBJECT

public:
    explicit add(QWidget *parent = nullptr);
    ~add();

private slots:
    //void on_ADD_clicked();

    //void on_submit_clicked();

    void on_menu_clicked();
    void checkExistingData();

    void on_ok_clicked();

private:
    Ui::add *ui;
    QSqlDatabase db;
    menu1 *mu;
    add *add1;

};

#endif // ADD_H

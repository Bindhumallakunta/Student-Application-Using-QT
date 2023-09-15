#ifndef HIGHEST_H
#define HIGHEST_H

#include <QMainWindow>
#include <QMainWindow>
#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <deletedetails.h>
#include <QTableView>
#include <QSqlTableModel>

class menu1;

namespace Ui {
class highest;
}

class highest : public QMainWindow
{
    Q_OBJECT

public:
    explicit highest(QWidget *parent = nullptr);
    ~highest();

private slots:
    //void on_highest_2_clicked();

    void on_menu_clicked();

    void on_ok_clicked();

private:
    Ui::highest *ui;
    QSqlDatabase db;
    menu1 *mu;
    highest *h;
};

#endif // HIGHEST_H

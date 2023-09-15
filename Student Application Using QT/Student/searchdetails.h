#ifndef SEARCHDETAILS_H
#define SEARCHDETAILS_H

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
class searchdetails;
}

class searchdetails : public QMainWindow
{
    Q_OBJECT

public:
    explicit searchdetails(QWidget *parent = nullptr);
    ~searchdetails();

private slots:
    void on_ok_clicked();

    void on_menu_clicked();

private:
    Ui::searchdetails *ui;
    QSqlDatabase db;
    menu1 *mu;
    searchdetails *s;
};

#endif // SEARCHDETAILS_H

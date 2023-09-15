#ifndef STATUS_H
#define STATUS_H

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
class status;
}

class status : public QMainWindow
{
    Q_OBJECT

public:
    explicit status(QWidget *parent = nullptr);
    ~status();

private slots:
    void on_ok_clicked();
    //void checkExistingData();

    void on_menu_clicked();

private:
    Ui::status *ui;
    QSqlDatabase db;
    menu1 *mu;
    status *st;
};

#endif // STATUS_H

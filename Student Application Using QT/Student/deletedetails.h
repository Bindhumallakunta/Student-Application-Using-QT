#ifndef DELETEDETAILS_H
#define DELETEDETAILS_H

#include <QMainWindow>
#include <QMainWindow>
#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QTableView>

class menu1;
namespace Ui {
class deletedetails;
}

class deletedetails : public QMainWindow
{
    Q_OBJECT

public:
    explicit deletedetails(QWidget *parent = nullptr);
    ~deletedetails();

private slots:
    //void on_pushButton_clicked();

    void on_OK_clicked();

    void on_menu_clicked();

private:
    Ui::deletedetails *ui;
    QSqlDatabase db;
    menu1 *mu;
    deletedetails *del;
};

#endif // DELETEDETAILS_H

#ifndef MODIFYDETAILS_H
#define MODIFYDETAILS_H
#include <QMainWindow>
#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QTableView>

#include <QMainWindow>
class menu1;
namespace Ui {
class modifydetails;
}

class modifydetails : public QMainWindow
{
    Q_OBJECT

public:
    explicit modifydetails(QWidget *parent = nullptr);
    ~modifydetails();
    //int modifydetails_validation();

private slots:
    //void on_submit_clicked();

    void on_menu_clicked();
    //void modifydetails_validation(int);

    void on_OK_clicked();
    //void checkExistingData();

private:
    Ui::modifydetails *ui;
    QSqlDatabase db;
    menu1 *mu1;
    modifydetails *mod;
};

#endif // MODIFYDETAILS_H

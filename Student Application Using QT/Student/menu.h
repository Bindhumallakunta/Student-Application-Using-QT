#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QDialog>
#include <menu1.h>
#include <QRegularExpression>

class MainWindow;
//#include <menu.h>


namespace Ui {
class menu;
}

class menu : public QDialog

{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    //void on_login_clicked();

    void on_ok_clicked();

    //void on_login_clicked();

    void on_homepage_clicked();

private:
    Ui::menu *ui;
    QSqlDatabase db;
    menu *m;
    menu1 *m1;
    MainWindow *mw;
};

#endif // MENU_H



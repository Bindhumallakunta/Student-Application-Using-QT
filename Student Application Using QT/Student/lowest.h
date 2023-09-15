#ifndef LOWEST_H
#define LOWEST_H

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
#include <QSqlTableModel>

namespace Ui {
class lowest;
}

class lowest : public QMainWindow
{
    Q_OBJECT

public:
    explicit lowest(QWidget *parent = nullptr);
    ~lowest();

private slots:
    void on_ok_2_clicked();

    void on_menu_2_clicked();

private:
    Ui::lowest *ui;
    QSqlDatabase db;
    menu1 *mu;
    lowest *l;
};

#endif // LOWEST_H

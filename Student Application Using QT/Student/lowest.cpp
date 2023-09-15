#include "lowest.h"
#include "ui_lowest.h"

#include "menu1.h"

class menu1;

lowest::lowest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::lowest),mu(nullptr)
{
    ui->setupUi(this);
}

lowest::~lowest()
{
    if(mu != nullptr)
    {
        delete mu;
    }
    delete ui;
}

void lowest::on_ok_2_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/MBINDHU/Desktop/QT_PROJECT/Student/STUDENT1.db");

    if(db.open())
    {
        QString Standard = ui->lineEdit_standard_2->text();
        bool isStandardValid = false;
        int standardValue = Standard.toInt(&isStandardValid);
        if (!isStandardValid || standardValue < 1 || standardValue > 10)
        {
            QMessageBox::information(this, "Invalid Standard", "Please enter a valid standard (1 to 10)");
            return;
        }

        //QSqlQuery qry;

        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("Standard");
        model->setFilter(QString("Standard = " + Standard + " ORDER BY totalmarks ASC"));
        model->select();

        QTableView *tableView = new QTableView;
        tableView->setModel(model);
        tableView->showMaximized();
    }
    else
    {
        QMessageBox::information(this, "Not Connected", "Database Is Not Connected");
    }
}




void lowest::on_menu_2_clicked()
{
    mu = new menu1();
    mu->show();
    mu->exec();
    this->close();
}



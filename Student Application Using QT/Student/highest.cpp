#include "highest.h"
#include "ui_highest.h"
#include "menu1.h"

class menu1;

highest::highest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::highest),mu(nullptr)
{
    ui->setupUi(this);
}

highest::~highest()
{
    if(mu != nullptr)
    {
        delete mu;
    }

    delete ui;
}

//void highest::on_highest_2_clicked()
void highest::on_ok_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/MBINDHU/Desktop/QT_PROJECT/Student/STUDENT1.db");


    if(db.open())
    {
        QString Standard = ui->lineEdit_standard->text();
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
        model->setFilter(QString("Standard = " + Standard + " ORDER BY totalmarks DESC"));
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


void highest::on_menu_clicked()
{
    mu = new menu1();
    mu->show();
    mu->exec();
    this->close();
}







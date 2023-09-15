#include "displaydetails.h"
#include "ui_displaydetails.h"
#include "menu1.h"

//#include "main"
class menu1;

displaydetails::displaydetails(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::displaydetails),mu(nullptr)
{
    ui->setupUi(this);
}

displaydetails::~displaydetails()
{
    if(mu != nullptr)
    {
        delete mu;
    }
    delete ui;
}
//void displaydetails::checkExistingData()
//{
//    QString Standard = ui->lineEdit_standard->text();
//    QString RollNo = ui->lineEdit_rollno->text();

//    QSqlQuery checkQuery;
//    checkQuery.prepare("SELECT * FROM Standard WHERE standard = :standard AND rollno = :rollno");
//    checkQuery.bindValue(":standard", Standard);
//    checkQuery.bindValue(":rollno", RollNo);

//    if (checkQuery.exec() && checkQuery.next())
//    {
//        QMessageBox::information(this, "Error", "Standard and RollNo already exist in the database");
//    }
//    else
//    {
//        // Proceed with the submission
//        on_ok_clicked();
//        //on_submit_clicked();
//    }
//}

void displaydetails::on_OK_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/MBINDHU/Desktop/QT_PROJECT/Student/STUDENT1.db");

    if (db.open())
    {
        QString Standard = ui->lineEdit_standard->text();
        QString RollNo = ui->lineEdit_rollno->text();
        bool isStandardValid = false;
        int standardValue = Standard.toInt(&isStandardValid);
        if (!isStandardValid || standardValue < 1 || standardValue > 10)
        {
            QMessageBox::information(this, "Invalid Standard", "Please enter a valid standard (1 to 10)");
            return;
        }
        bool isRollnoValid = false;
        int rollnoValue = RollNo.toInt(&isRollnoValid);
        if (!isRollnoValid || rollnoValue < 1 || rollnoValue > 40)
        {
            QMessageBox::information(this, "Invalid rollno", "Please enter a valid rollno (1 to 40)");
            return;
        }


        //QSqlQuery qry;

        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("Standard");
        //model->setFilter(QString("Standard = " + Standard + AND "RollNo = " + RollNo + );
        model->setFilter(QString("standard = '%1' AND rollno = '%2'").arg(Standard).arg(RollNo));
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



void displaydetails::on_menu_clicked()
{
    mu = new menu1();
    mu->show();
    this->close();
}

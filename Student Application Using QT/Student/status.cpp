#include "status.h"
#include "ui_status.h"
#include "menu1.h"

status::status(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::status),mu(nullptr)
{
    ui->setupUi(this);
}

status::~status()
{
    if(mu != nullptr)
    {
        delete mu;
    }
    delete ui;
}

void status::on_ok_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/MBINDHU/Desktop/QT_PROJECT/Student/STUDENT1.db");

    if (db.open())
    {
        QString Standard = ui->lineEdit_standard->text();
       // QString Rollno = ui->lineEdit_rollno->text();

        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT * FROM Standard WHERE  standard = :Standard");
        //checkQuery.bindValue(":Rollno", Rollno);
        checkQuery.bindValue(":Standard", Standard);
        bool isStandardValid = false;
        int standardValue = Standard.toInt(&isStandardValid);
        if (!isStandardValid || standardValue < 1 || standardValue > 10)
        {
            QMessageBox::information(this, "Invalid Standard", "Please enter a valid standard (1 to 10)");
            return;
        }

        // Validate Rollno
//        static QRegularExpression rollnoRegex("[^0-9]");
//        if (Rollno.isEmpty() || Rollno.contains(rollnoRegex))
//        {
//            QMessageBox::information(this, "Invalid Rollno", "Please enter a valid roll number (numeric value)");
//            return;
//        }

        if (checkQuery.exec() && checkQuery.next())
        {
            QSqlTableModel *model = new QSqlTableModel;
            model->setTable("Standard");

            // Apply filters to display specific records
            model->setFilter( "Standard = "  + Standard );
            model->select();

            if (model->rowCount() > 0)
            {
                QMessageBox::information(this, "Details Found", "Details are displayed");
                QTableView *tableView = new QTableView;
                tableView->setModel(model);
                tableView->showMaximized();
            }
            else
            {
                QMessageBox::information(this, "No Details", "No details found for the provided Standard and RollNo");
            }
        }
        else
        {
            QMessageBox::information(this, "Error", "Standard and RollNo do not exist in the database");
        }
    }
    else
    {
        QMessageBox::information(this, "Not Connected", "Database Is Not Connected");
    }
}



void status::on_menu_clicked()
{
    mu = new menu1();
    mu->show();
    this->close();
}



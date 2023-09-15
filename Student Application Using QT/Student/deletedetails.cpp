#include "deletedetails.h"
#include "ui_deletedetails.h"
#include "menu1.h"
//class menu1;
deletedetails::deletedetails(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::deletedetails),mu(nullptr)
{
    ui->setupUi(this);
}

deletedetails::~deletedetails()
{
    if(mu != nullptr)
    {
        delete mu;
    }
    delete ui;
}


//void deletedetails::on_OK_clicked()
//{
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("C:/Users/MBINDHU/Desktop/QT_PROJECT/Student/STUDENT1.db");

//    if(db.open())
//    {
//        QString Standard = ui->lineEdit_standard->text();
//        QString Rollno = ui->lineEdit_rollno->text();

//        QSqlQuery qry;

//        qry.prepare("DELETE FROM Standard WHERE rollno = :Rollno AND standard = :Standard");
//        qry.bindValue(":Rollno", Rollno);
//        qry.bindValue(":Standard", Standard);

//        if(qry.exec())
//        {
//            QMessageBox::information(this, "Deleted", "Data Deleted Successfully");
//            QSqlTableModel *model = new QSqlTableModel;
//            model->setTable("Standard");
//            model->select();

//            QTableView *tableView = new QTableView;
//            tableView->setModel(model);
//            tableView->showMaximized();
//        }
//        else
//        {
//            qDebug() << qry.lastQuery();
//            qDebug() << qry.lastError();
//            QMessageBox::information(this, "Not Deleted", "Data Is Not Deleted");
//        }
//    }
//    else
//    {
//        QMessageBox::information(this, "Not Connected", "Database Is Not Connected");
//    }
//}


void deletedetails::on_OK_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/MBINDHU/Desktop/QT_PROJECT/Student/STUDENT1.db");

    if (db.open())
    {
        QString Standard = ui->lineEdit_standard->text();
        QString Rollno = ui->lineEdit_rollno->text();

        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT * FROM Standard WHERE rollno = :Rollno AND standard = :Standard");
        checkQuery.bindValue(":Rollno", Rollno);
        checkQuery.bindValue(":Standard", Standard);
        bool isStandardValid = false;
        int standardValue = Standard.toInt(&isStandardValid);
        if (!isStandardValid || standardValue < 1 || standardValue > 10)
        {
            QMessageBox::information(this, "Invalid Standard", "Please enter a valid standard (1 to 10)");
            return;
        }
        bool isRollnoValid = false;
        int rollnoValue = Rollno.toInt(&isRollnoValid);
        if (!isRollnoValid || rollnoValue < 1 || rollnoValue > 40)
        {
            QMessageBox::information(this, "Invalid rollno", "Please enter a valid rollno (1 to 40)");
            return;
        }

//        // Validate Rollno
//        static QRegularExpression rollnoRegex("[^0-9]");
//        if (Rollno.isEmpty() || Rollno.contains(rollnoRegex))
//        {
//            QMessageBox::information(this, "Invalid Rollno", "Please enter a valid roll number (numeric value)");
//            return;
//        }

        if (checkQuery.exec() && checkQuery.next())
        {
            QSqlQuery deleteQuery;
            deleteQuery.prepare("DELETE FROM Standard WHERE rollno = :Rollno AND standard = :Standard");
            deleteQuery.bindValue(":Rollno", Rollno);
            deleteQuery.bindValue(":Standard", Standard);

            if (deleteQuery.exec())
            {
                QMessageBox::information(this, "Deleted", "Data Deleted Successfully");
                QSqlTableModel *model = new QSqlTableModel;
                model->setTable("Standard");
                model->select();

                QTableView *tableView = new QTableView;
                tableView->setModel(model);
                tableView->showMaximized();
            }
            else
            {
                qDebug() << deleteQuery.lastQuery();
                qDebug() << deleteQuery.lastError();
                QMessageBox::information(this, "Not Deleted", "Data Is Not Deleted");
            }
        }
        else
        {
            QMessageBox::information(this, "Error", "Student and RollNo do not exist in the database");
        }
    }
    else
    {
        QMessageBox::information(this, "Not Connected", "Database Is Not Connected");
    }
}




void deletedetails::on_menu_clicked()
{
    mu = new menu1();
    mu->show();
    this->close();
}


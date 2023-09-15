#include "menu.h"
#include "ui_menu.h"

#include "mainwindow.h"
#include <QRegularExpression>

menu::menu(QWidget *parent) :
    QDialog(parent),

    ui(new Ui::menu),m1(nullptr),mw(nullptr)
{
    ui->setupUi(this);
}

menu::~menu()
{
    if(m1 != nullptr)
    {
        delete m1;
    }
    if(mw != nullptr)
    {
        delete mw;
    }
    delete ui;
}

//#include <QRegularExpression> // Include the QRegularExpression header

void menu::on_ok_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/MBINDHU/Desktop/QT_PROJECT/Student/STUDENT1.db");

    if (db.open())
    {
        // Retrieve Data From Input Fields
        QString Standard = ui->lineEdit_standard->text();
        QString Rollno = ui->lineEdit_rollno->text();
        QString Name = ui->lineEdit_name->text();

        // Validate Standard
        bool isStandardValid = false;
        int standardValue = Standard.toInt(&isStandardValid);
        if (!isStandardValid || standardValue < 1 || standardValue > 10)
        {
            QMessageBox::information(this, "Invalid Standard", "Please enter a valid standard (1 to 10)");
            return;
        }

        // Validate Rollno
        static QRegularExpression rollnoRegex("[^0-9]");
        if (Rollno.isEmpty() || Rollno.contains(rollnoRegex))
        {
            QMessageBox::information(this, "Invalid Rollno", "Please enter a valid roll number (numeric value)");
            return;
        }

        // Validate Name
        static QRegularExpression nameRegex("^[A-Za-z]+$");
        if (Name.isEmpty() || !Name.contains(nameRegex))
        {
            QMessageBox::information(this, "Invalid Name", "Please enter a valid name (alphabetical characters only)");
            return;
        }

        // Run Our Insert Query
        QSqlQuery qry;
        qry.prepare("INSERT INTO STUDENT2 (Standard, Rollno, Name) VALUES (:Standard, :Rollno, :Name) ");
        qry.bindValue(":Standard", Standard);
        qry.bindValue(":Rollno", Rollno);
        qry.bindValue(":Name", Name);

        if (qry.exec())
        {
            QMessageBox::information(this, "Inserted", "Data Inserted Successfully");
            m1 = new menu1();
            m1->show();
            this->close();
        }
        else
        {
            QMessageBox::information(this, "Not Inserted", "Data Is Not Inserted");
        }
    }
    else
    {
        QMessageBox::information(this, "Not Connected", "Database Is Not Connected");
    }
}


//void menu::on_ok_clicked()
//{
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("C:/Users/MBINDHU/Desktop/QT_PROJECT/Student/STUDENT1.db");

//    if (db.open())
//    {
//        // Retrieve Data From Input Fields
//        QString Standard = ui->lineEdit_standard->text();
//        QString Rollno = ui->lineEdit_rollno->text();
//        QString Name = ui->lineEdit_name->text();

//        // Validate Standard
//        bool isStandardValid = false;
//        int standardValue = Standard.toInt(&isStandardValid);
//        if (!isStandardValid || standardValue < 1 || standardValue > 10)
//        {
//            QMessageBox::information(this, "Invalid Standard", "Please enter a valid standard (1 to 10)");
//            return;
//        }

//        // Validate Rollno
//        if (Rollno.isEmpty() || Rollno.contains(QRegExp("[^0-9]")))
//        {
//            QMessageBox::information(this, "Invalid Rollno", "Please enter a valid roll number (numeric value)");
//            return;
//        }

//        // Validate Name
//        if (Name.isEmpty() || !Name.contains(QRegExp("^[A-Za-z]+$")))
//        {
//            QMessageBox::information(this, "Invalid Name", "Please enter a valid name (alphabetical characters only)");
//            return;
//        }

//        // Run Our Insert Query
//        QSqlQuery qry;
//        qry.prepare("INSERT INTO STUDENT2 (Standard, Rollno, name) VALUES (:Standard, :Rollno, :name) ");
//        qry.bindValue(":Standard", Standard);
//        qry.bindValue(":Rollno", Rollno);
//        qry.bindValue(":name", Name);

//        if (qry.exec())
//        {
//            QMessageBox::information(this, "Inserted", "Data Inserted Successfully");
//            m1 = new menu1();
//            m1->show();
//            this->close();
//        }
//        else
//        {
//            QMessageBox::information(this, "Not Inserted", "Data Is Not Inserted");
//        }
//    }
//    else
//    {
//        QMessageBox::information(this, "Not Connected", "Database Is Not Connected");
//    }
//}

//void menu::on_ok_clicked()
//{
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("C:/Users/MBINDHU/Desktop/QT_PROJECT/Student/STUDENT1.db");

//    if (db.open())
//    {
//        // Retrieve Data From Input Fields
//        QString Standard = ui->lineEdit_standard->text();
//        QString Rollno = ui->lineEdit_rollno->text();
//        QString Name = ui->lineEdit_name->text();

//        // Validate Standard Input
//        bool isStandardValid = false;
//        int standardValue = Standard.toInt(&isStandardValid);
//        if (!isStandardValid || standardValue < 1 || standardValue > 10)
//        {
//            QMessageBox::information(this, "Invalid Standard", "Please enter a valid standard value (1-10).");
//            return;
//        }

//        // Run Our Insert Query
//        QSqlQuery qry;
//        qry.prepare("INSERT INTO STUDENT2 (Standard, Rollno, name) VALUES (:Standard, :Rollno, :name) ");
//        qry.bindValue(":Standard", Standard);
//        qry.bindValue(":Rollno", Rollno);
//        qry.bindValue(":name", Name);

//        if (qry.exec())
//        {
//            QMessageBox::information(this, "Inserted", "Data Inserted Successfully");
//            m1 = new menu1();
//            m1->show();
//            this->close();
//        }
//        else
//        {
//            qDebug() << qry.lastQuery();
//            qDebug() << qry.lastError();
//            QMessageBox::information(this, "Not Inserted", "Data Is Not Inserted");
//        }
//    }
//    else
//    {
//        QMessageBox::information(this, "Not Connected", "Database Is Not Connected");
//    }
//}


//void menu::on_ok_clicked()
//{
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("C:/Users/MBINDHU/Desktop/QT_PROJECT/Student/STUDENT1.db");

//    if(db.open())
//    {
//        //Retrevie Data From Input Fields
//        QString Standard = ui->lineEdit_standard->text();
//        QString Rollno = ui->lineEdit_rollno->text();
//        QString Name = ui->lineEdit_name->text();


//        // Run Our Insert Query

//        QSqlQuery qry;

//        qry.prepare("INSERT INTO STUDENT2 (Standard,Rollno,name) VALUES (:Standard,:Rollno,:name) ");

//        qry.bindValue(":Standard", Standard);
//        qry.bindValue(":Rollno", Rollno);
//        qry.bindValue(":name", Name);


//        if(qry.exec()) {
//            QMessageBox::information(this, "Inserted", "Data Inserted Successfully");
//            m1 = new menu1();
//            m1->show();
//            this->close();

//        }else {
//            QMessageBox::information(this, "Not Inserted", "Data Is Not Inserted");
//        }
//    }else {
//        QMessageBox::information(this, "Not Connected", "Database Is Not Connected");
//    }
//}

void menu::on_homepage_clicked()
{
    mw = new MainWindow();
    mw->show();
    this->close();
}


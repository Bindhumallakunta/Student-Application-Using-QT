#include "count1.h"
#include "ui_count1.h"
#include "menu1.h"

count1::count1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::count1),mu(nullptr)
{
    ui->setupUi(this);
}

count1::~count1()
{
    if(mu != nullptr)
    {
        delete mu;
    }
    delete ui;
}

void count1::on_ok_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/MBINDHU/Desktop/QT_PROJECT/Student/STUDENT1.db");

    if (db.open())
    {
        QString Standard = ui->lineEdit_standard->text();
        bool isStandardValid = false;
        int standardValue = Standard.toInt(&isStandardValid);
        if (!isStandardValid || standardValue < 1 || standardValue > 10)
        {
            QMessageBox::information(this, "Invalid Standard", "Please enter a valid standard (1 to 10)");
            return;
        }

        QSqlQuery countQuery;
        countQuery.prepare("SELECT COUNT(*) FROM Standard WHERE standard = :Standard");
        countQuery.bindValue(":Standard", Standard);

        if (countQuery.exec() && countQuery.next())
        {
            int studentCount = countQuery.value(0).toInt();
            QString message = QString("Number of students in Standard %1: %2").arg(Standard).arg(studentCount);
            QMessageBox::information(this, "Student Count", message);
        }
        else
        {
            QMessageBox::information(this, "Error", "Failed to retrieve student count");
        }
    }
    else
    {
        QMessageBox::information(this, "Not Connected", "Database Is Not Connected");
    }
}


void count1::on_menu_clicked()
{
    mu = new menu1();
    mu->show();
    this->close();
}



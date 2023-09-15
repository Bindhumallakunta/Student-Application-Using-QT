#include "add.h"
#include "ui_add.h"
#include "menu1.h"

add::add(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::add),mu(nullptr)
{
    ui->setupUi(this);
}

add::~add()
{
    if(mu != nullptr)
    {
        delete mu;
    }
    delete ui;
}


void add::checkExistingData()
{
    QString Standard = ui->lineEdit_standard->text();
    QString RollNo = ui->lineEdit_rollno->text();

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT * FROM Standard WHERE standard = :standard AND rollno = :rollno");
    checkQuery.bindValue(":standard", Standard);
    checkQuery.bindValue(":rollno", RollNo);

    if (checkQuery.exec() && checkQuery.next())
    {
        QMessageBox::information(this, "Error", "Standard and RollNo already exist in the database");
    }
    else
    {
        // Proceed with the submission
        on_ok_clicked();
        //on_submit_clicked();
    }
}

void add::on_ok_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/MBINDHU/Desktop/QT_PROJECT/Student/STUDENT1.db");

    if (db.open())
    {
        QString Standard = ui->lineEdit_standard->text();
        QString RollNo = ui->lineEdit_rollno->text();
        QString Name = ui->lineEdit_name->text();
        QString Telugu = ui->lineEdit_telugu->text();
        QString Hindi = ui->lineEdit_hindi->text();
        QString English = ui->lineEdit_english->text();

        int teluguMarks = Telugu.toInt();
        int englishMarks = English.toInt();
        int hindiMarks = Hindi.toInt();

        int TotalMarks = teluguMarks + englishMarks + hindiMarks;


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



        // Validate Name
        static QRegularExpression nameRegex("^[A-Za-z]+$");
        if (Name.isEmpty() || !Name.contains(nameRegex))
        {
            QMessageBox::information(this, "Invalid Name", "Please enter a valid name (alphabetical characters only)");
            return;
        }


        QSqlQuery query;
        //QSqlQuery query1;

        if (Standard.isEmpty() || RollNo.isEmpty())
        {
            QMessageBox::information(this, "Error", "Please enter the standard and roll number");
        }
        else
        {
            // Check if the standard and roll number already exist in the database
            QSqlQuery checkQuery;
            checkQuery.prepare("SELECT * FROM Standard WHERE standard = :standard AND rollno = :rollno");
            checkQuery.bindValue(":standard", Standard);
            checkQuery.bindValue(":rollno", RollNo);
            if (checkQuery.exec() && checkQuery.next())
            {
                QMessageBox::information(this, "Error", "Standard and RollNo already exist in the database");
            }
            else if (Name.isEmpty() || Telugu.isEmpty() || Hindi.isEmpty() || English.isEmpty())
            {
                QMessageBox::information(this, "Error", "Please enter all the required data");
            }
            else if(teluguMarks < 0 || teluguMarks > 100)
            {
                QMessageBox::information(this, "Error", "Marks should be between 0 and 100");
            }
            else if(hindiMarks < 0 || hindiMarks > 100)
            {
                QMessageBox::information(this, "Error", "Marks should be between 0 and 100");
            }
            else if(englishMarks < 0 || englishMarks > 100)
            {
                QMessageBox::information(this, "Error", "Marks should be between 0 and 100");
            }
            else
            {
                query.prepare("INSERT INTO Standard (standard, rollno, name, telugu, hindi, english, totalmarks) "
                              "VALUES (:standard, :rollno, :name, :telugu, :hindi, :english, :totalmarks)");
//                query.prepare("INSERT INTO status (standard, rollno, name, telugu, hindi, english, totalmarks) "
//                              "VALUES (:standard, :rollno, :name, :telugu, :hindi, :english, :totalmarks)");
                query.bindValue(":standard", Standard);
                query.bindValue(":rollno", RollNo);
                query.bindValue(":name", Name);
                query.bindValue(":telugu", Telugu);
                query.bindValue(":hindi", Hindi);
                query.bindValue(":english", English);
                query.bindValue(":totalmarks", TotalMarks);

                if (query.exec())
                {
                    QMessageBox::information(this, "Inserted", "Data Inserted Successfully");
                    QSqlTableModel *model = new QSqlTableModel;
                    model->setTable("Standard");
                    model->select();

                    QTableView *tableView = new QTableView;
                    tableView->setModel(model);
                    tableView->showMaximized();
                }
                else
                {
                    qDebug() << query.lastQuery();
                    qDebug() << query.lastError();
                    QMessageBox::information(this, "Not Inserted", "Data Is Not Inserted");
                }

            }
        }
    }
    else
    {
        QMessageBox::information(this, "Not Connected", "Database Is Not Connected");
    }
}

void add::on_menu_clicked()
{
    mu = new menu1();
    mu->show();
    this->close();
}

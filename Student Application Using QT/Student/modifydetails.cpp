//#include "modifydetails.h"
//#include "ui_modifydetails.h"
//#include "menu1.h"

//modifydetails::modifydetails(QWidget *parent) :
//    QMainWindow(parent),
//    ui(new Ui::modifydetails),mu1(nullptr)
//{
//    ui->setupUi(this);
//}

//modifydetails::~modifydetails()
//{
//    if(mu1 != nullptr)
//    {
//        delete mu1;
//    }
//    delete ui;
//}


//void modifydetails::on_OK_clicked()
//{
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("C:/Users/MBINDHU/Desktop/QT_PROJECT/Student/STUDENT1.db");

//    if(db.open())
//    {
//        QString Standard = ui->lineEdit_standard->text();
//        QString RollNo = ui->lineEdit_rollno->text();
//        QString Name = ui->lineEdit_name->text();
//        QString Telugu = ui->lineEdit_telugu->text();
//        QString Hindi = ui->lineEdit_hindi->text();
//        QString English = ui->lineEdit_english->text();
//        //QString TotalMarks = ui->lineEdit_totalmarks->text();

//        int teluguMarks = Telugu.toInt();
//        int englishMarks = English.toInt();
//        int hindiMarks = Hindi.toInt();

//        int TotalMarks = teluguMarks + englishMarks + hindiMarks;


//        QSqlQuery query;

//        if(Name.isEmpty() || RollNo.isEmpty() || Standard.isEmpty() || Telugu.isEmpty() || Hindi.isEmpty() ||English.isEmpty() )
//        {
//            QMessageBox::information(this, "Error", "Please enter the data");
//        }
//        else
//        {
//            query.prepare("UPDATE Standard SET rollno = :rollno, name = :name, telugu = :telugu, "
//                          "hindi = :hindi, english = :english,  totalmarks = :totalmarks "
//                          "WHERE  rollno = :rollno AND standard = :standard AND name = :name");


//            query.bindValue(":standard", Standard);

//            query.bindValue(":rollno", RollNo);

//            query.bindValue(":name", Name);

//            query.bindValue(":telugu", Telugu);

//            query.bindValue(":hindi", Hindi);

//            query.bindValue(":english", English);

//            query.bindValue(":totalmarks", TotalMarks);

//            if(query.exec())
//            {
//                QMessageBox::information(this, "Inserted", "Data Modified Successfully");
//                QSqlTableModel *model = new QSqlTableModel;
//                model->setTable("Standard");
//                model->select();

//                QTableView *tableView = new QTableView;
//                tableView->setModel(model);
//                tableView->showMaximized();
//            }
//            else
//            {
//                qDebug() << query.lastQuery();
//                qDebug() << query.lastError();
//                QMessageBox::information(this, "Not Inserted", "Data Is Not Modified");
//            }
//        }
//    }
//    else
//    {
//        QMessageBox::information(this, "Not Connected", "Database Is Not Connected");
//    }
//}

//void modifydetails::on_menu_clicked()
//{
//    mu1 = new menu1();
//    mu1->show();
//    this->close();

//}


//#include "modifydetails.h"
//#include "ui_modifydetails.h"
//#include "menu1.h"
//#define TRUE 1
//#define FALSE 0

//modifydetails::modifydetails(QWidget *parent) :
//    QMainWindow(parent),
//    ui(new Ui::modifydetails),mu1(nullptr)
//{
//    ui->setupUi(this);
//}

//modifydetails::~modifydetails()
//{
//    if(mu1 != nullptr)
//    {
//        delete mu1;
//    }
//    delete ui;
//}
//int modifydetails::modifydetails_validation(int standard)
//{
//    if (standard >= 1 && standard <= 4)
//        return TRUE;
//    else
//        return FALSE;
//}



//void modifydetails::on_OK_clicked()
//{
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("C:/Users/MBINDHU/Desktop/QT_PROJECT/Student/STUDENT1.db");

//    if(db.open())
//    {
//        QString Standard = ui->lineEdit_standard->text();
//        QString RollNo = ui->lineEdit_rollno->text();
//        QString Name = ui->lineEdit_name->text();
//        QString Telugu = ui->lineEdit_telugu->text();
//        QString Hindi = ui->lineEdit_hindi->text();
//        QString English = ui->lineEdit_english->text();
//        //QString TotalMarks = ui->lineEdit_totalmarks->text();

//        int teluguMarks = Telugu.toInt();
//        int englishMarks = English.toInt();
//        int hindiMarks = Hindi.toInt();

//        int TotalMarks = teluguMarks + englishMarks + hindiMarks;

//        QSqlQuery query;

//        if(Name.isEmpty() || RollNo.isEmpty() || Standard.isEmpty() || Telugu.isEmpty() || Hindi.isEmpty() ||English.isEmpty() )
//        {
//            QMessageBox::information(this, "Error", "Please enter the data");
//        }
//        else
//        {
//            query.prepare("UPDATE Standard SET rollno = :rollno, name = :name, telugu = :telugu, "
//                          "hindi = :hindi, english = :english,  totalmarks = :totalmarks "
//                          "WHERE  rollno = :rollno AND standard = :standard AND name = :name");


//            query.bindValue(":standard", Standard);
//            if (modifydetails_validation(Standard) == 1)
//                break;
//            else
//                cout << "Invalid Standard" << endl;
//        }

//            query.bindValue(":rollno", RollNo);

//            query.bindValue(":name", Name);

//            query.bindValue(":telugu", Telugu);

//            query.bindValue(":hindi", Hindi);

//            query.bindValue(":english", English);

//            query.bindValue(":totalmarks", TotalMarks);

//            if(query.exec())
//            {
//                QMessageBox::information(this, "Inserted", "Data Modified Successfully");
//                QSqlTableModel *model = new QSqlTableModel;
//                model->setTable("Standard");
//                model->select();

//                QTableView *tableView = new QTableView;
//                tableView->setModel(model);
//                tableView->showMaximized();
//            }
//            else
//            {
//                qDebug() << query.lastQuery();
//                qDebug() << query.lastError();
//                QMessageBox::information(this, "Not Inserted", "Data Is Not Modified");
//            }
//        }
//    }
//    else
//    {
//        QMessageBox::information(this, "Not Connected", "Database Is Not Connected");
//    }
//}

//void modifydetails::on_menu_clicked()
//{
//    mu1 = new menu1();
//    mu1->show();
//    this->close();

//}


#include "modifydetails.h"
#include "ui_modifydetails.h"
#include "menu1.h"

modifydetails::modifydetails(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::modifydetails),mu1(nullptr)
{
    ui->setupUi(this);
}

modifydetails::~modifydetails()
{
    if(mu1 != nullptr)
    {
        delete mu1;
    }
    delete ui;
}


void modifydetails::on_OK_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/MBINDHU/Desktop/QT_PROJECT/Student/STUDENT1.db");

    if(db.open())
    {
        QString Standard = ui->lineEdit_standard->text();
        QString RollNo = ui->lineEdit_rollno->text();
        //QString Name = ui->lineEdit_name->text();
        QString Telugu = ui->lineEdit_telugu->text();
        QString Hindi = ui->lineEdit_hindi->text();
        QString English = ui->lineEdit_english->text();
        //QString TotalMarks = ui->lineEdit_totalmarks->text();

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

//        // Validate Rollno
//        static QRegularExpression rollnoRegex("[^0-9]");
//        if (RollNo.isEmpty() || RollNo.contains(rollnoRegex))
//        {
//            QMessageBox::information(this, "Invalid Rollno", "Please enter a valid roll number (numeric value)");
//            return;
//        }

        // Validate Name
//        static QRegularExpression nameRegex("^[A-Za-z]+$");
//        if (Name.isEmpty() || !Name.contains(nameRegex))
//        {
//            QMessageBox::information(this, "Invalid Name", "Please enter a valid name (alphabetical characters only)");
//            return;
//        }


        QSqlQuery query;

        if( RollNo.isEmpty() || Standard.isEmpty() || Telugu.isEmpty() || Hindi.isEmpty() ||English.isEmpty() )
        {
            QMessageBox::information(this, "Error", "Please enter the data");
        }
        else if ( Telugu.isEmpty() || Hindi.isEmpty() || English.isEmpty())
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
            query.prepare("UPDATE Standard SET telugu = :telugu, "
                          "hindi = :hindi, english = :english,  totalmarks = :totalmarks "
                          "WHERE  rollno = :rollno AND standard = :standard");


            query.bindValue(":standard", Standard);

            query.bindValue(":rollno", RollNo);

            //query.bindValue(":name", Name);

            query.bindValue(":telugu", Telugu);

            query.bindValue(":hindi", Hindi);

            query.bindValue(":english", English);

            query.bindValue(":totalmarks", TotalMarks);

            if(query.exec())
            {
                QMessageBox::information(this, "Inserted", "Data Modified Successfully");
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
                QMessageBox::information(this, "Not Inserted", "Data Is Not Modified");
            }
        }
    }
    else
    {
        QMessageBox::information(this, "Not Connected", "Database Is Not Connected");
    }
}

void modifydetails::on_menu_clicked()
{
    mu1 = new menu1();
    mu1->show();
    this->close();

}



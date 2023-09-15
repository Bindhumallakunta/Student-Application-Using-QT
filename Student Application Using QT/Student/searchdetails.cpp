#include "searchdetails.h"
#include "ui_searchdetails.h"
#include "menu1.h"

searchdetails::searchdetails(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::searchdetails),mu(nullptr)
{
    ui->setupUi(this);
}

searchdetails::~searchdetails()
{
    if(mu != nullptr)
    {
        delete mu;
    }
    delete ui;
}

void searchdetails::on_ok_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/MBINDHU/Desktop/QT_PROJECT/Student/STUDENT1.db");

    if(db.open())
    {
        QString Standard = ui->lineEdit_standard->text();
        QString Character = ui->lineEdit_character->text();
        QSqlQuery qry;
        qry.bindValue(":standard", Standard);
        qry.bindValue(":character", Character);
        bool isStandardValid = false;
        int standardValue = Standard.toInt(&isStandardValid);
        if (!isStandardValid || standardValue < 1 || standardValue > 10)
        {
            QMessageBox::information(this, "Invalid Standard", "Please enter a valid standard (1 to 10)");
            return;
        }
        static QRegularExpression nameRegex("^[A-Za-z]+$");
        if (Character.isEmpty() || !Character.contains(nameRegex))
        {
            QMessageBox::information(this, "Invalid Name", "Please enter a valid name (alphabetical characters only)");
            return;
        }



        //QSqlQuery qry;

        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("Standard");
        //model->setFilter(QString("Standard = " + Standard + " ORDER BY totalmarks ASC"));
        model->setFilter(QString("standard = " + Standard + "  AND name LIKE '" +  Character + "%'"));
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



void searchdetails::on_menu_clicked()
{
    mu = new menu1();
    mu->show();
    mu->exec();
    this->close();
}

//#include "searchdetails.h"
//#include "ui_searchdetails.h"
//#include "menu1.h"

//searchdetails::searchdetails(QWidget *parent) :
//    QMainWindow(parent),
//    ui(new Ui::searchdetails), mu(nullptr)
//{
//    ui->setupUi(this);

//    // Set the validator for the Standard field
//    QIntValidator *standardValidator = new QIntValidator(1, 10, this);
//    ui->lineEdit_standard->setValidator(standardValidator);
//}

//searchdetails::~searchdetails()
//{
//    if (mu != nullptr)
//    {
//        delete mu;
//    }
//    delete ui;
//}

//void searchdetails::on_ok_clicked()
//{
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("C:/Users/MBINDHU/Desktop/QT_PROJECT/Student/STUDENT1.db");

//    if (db.open())
//    {
//        QString Standard = ui->lineEdit_standard->text();
//        QString Character = ui->lineEdit_character->text();

//        // Check if Standard is a numeric value
//        bool isNumeric = false;
//        int standardValue = Standard.toInt(&isNumeric);

//        if (isNumeric && standardValue >= 1 && standardValue <= 10)
//        {
//            QSqlQuery qry;
//            qry.bindValue(":standard", Standard);
//            qry.bindValue(":character", Character);

//            //QSqlQuery qry;

//            QSqlTableModel *model = new QSqlTableModel;
//            model->setTable("Standard");
//            //model->setFilter(QString("Standard = " + Standard + " ORDER BY totalmarks ASC"));
//            model->setFilter(QString("standard = " + Standard + "  AND name LIKE '" + Character + "%'"));
//            model->select();

//            QTableView *tableView = new QTableView;
//            tableView->setModel(model);
//            tableView->showMaximized();
//        }
//        else
//        {
//            QMessageBox::information(this, "Invalid Input", "Please enter a numeric value between 1 and 10 for Standard.");
//        }
//    }
//    else
//    {
//        QMessageBox::information(this, "Not Connected", "Database Is Not Connected");
//    }
//}

//void searchdetails::on_menu_clicked()
//{
//    mu = new menu1();
//    mu->show();
//    mu->exec();
//    this->close();
//}


//#include "searchdetails.h"
//#include "ui_searchdetails.h"
//#include "menu1.h"

//searchdetails::searchdetails(QWidget *parent) :
//    QMainWindow(parent),
//    ui(new Ui::searchdetails), mu(nullptr)
//{
//    ui->setupUi(this);

//    // Set the validator for the Standard field
//    QIntValidator *standardValidator = new QIntValidator(1, 10, this);
//    ui->lineEdit_standard->setValidator(standardValidator);

//    // Set the validator for the Character field
//    QRegularExpression alphabeticRegex("[a-zA-Z]+");
//    QRegularExpressionValidator *alphabeticValidator = new QRegularExpressionValidator(alphabeticRegex, this);
//    ui->lineEdit_character->setValidator(alphabeticValidator);
//}

//searchdetails::~searchdetails()
//{
//    if (mu != nullptr)
//    {
//        delete mu;
//    }
//    delete ui;
//}

//void searchdetails::on_ok_clicked()
//{
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("C:/Users/MBINDHU/Desktop/QT_PROJECT/Student/STUDENT1.db");

//    if (db.open())
//    {
//        QString Standard = ui->lineEdit_standard->text();
//        QString Character = ui->lineEdit_character->text();

//        // Check if Character only contains alphabetic letters
//        bool isAlphabetic = !Character.isEmpty() && Character.at(0).isLetter();

//        if (isAlphabetic|| isNumeric)
//        {
//            QSqlQuery qry;
//            qry.bindValue(":standard", Standard);
//            qry.bindValue(":character", Character);
//            //QSqlQuery qry;
//            QSqlTableModel *model = new QSqlTableModel;
//            model->setTable("Standard");
//            //model->setFilter(QString("Standard = " + Standard + " ORDER BY totalmarks ASC"));
//            model->setFilter(QString("standard = " + Standard + "  AND name LIKE '" + Character + "%'"));
//            model->select();
//            QTableView *tableView = new QTableView;
//            tableView->setModel(model);
//            tableView->showMaximized();
//        }

//        else
//        {
//            QMessageBox::information(this, "Invalid Input", "Please enter a valid standard");
//        }
//        else
//        {
//            QMessageBox::information(this, "Invalid Input", "Please enter a valid character (alphabetic letters only).");
//        }

//    }
//    else
//    {
//        QMessageBox::information(this, "Not Connected", "Database Is Not Connected");
//    }
//}

//void searchdetails::on_menu_clicked()
//{
//    mu = new menu1();
//    mu->show();
//    mu->exec();
//    this->close();
//}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), m1(nullptr)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    if(m1 != nullptr)
    {
        delete m1;
    }
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/MBINDHU/Desktop/QT_PROJECT/Student/STUDENT1.db");

    if (db.open()) {
        // Retrieve Data From Input Fields
        QString Username = ui->lineEdit_username->text();
        QString Password = ui->lineEdit_password->text();

        if (Username == "User" && Password == "1234") {
            QMessageBox::information(this, "Valid Credentials", "Logged In Successfully");
            m1 = new menu1();
            m1->show();
            this->close();
        } else {
            QMessageBox::information(this, "Invalid Credentials", "Invalid Username or Password");
        }
    } else {
        QMessageBox::information(this, "Not Connected", "Database Is Not Connected");
    }
}


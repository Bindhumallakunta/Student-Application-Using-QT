#include "menu1.h"
#include "ui_menu1.h"
#include "mainwindow.h"
#include "menu.h"
#include "menu1.h"

menu1::menu1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu1),mw(nullptr),m(nullptr),add1(nullptr),del(nullptr),mod(nullptr),dis(nullptr),h(nullptr),l(nullptr),s(nullptr),ct(nullptr)
{
    ui->setupUi(this);
}

menu1::~menu1()
{
    if(add1 != nullptr)
    {
        delete add1;
    }
    if(del != nullptr)
    {
        delete del;
    }
    if(mod != nullptr)
    {
        delete mod;
    }
    if(dis != nullptr)
    {
        delete dis;
    }
    if(h != nullptr)
    {
        delete h;
    }
    if(l != nullptr)
    {
        delete h;
    }
    if(s != nullptr)
    {
        delete s;
    }
    if(ct != nullptr)
    {
        delete ct;
    }



    if(mw != nullptr)
    {
        delete mw;
    }
    delete ui;
}
void menu1::on_ADD_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/MBINDHU/Desktop/QT_PROJECT/Student/STUDENT1.db");
    add1 = new add();
    add1->show();
    this->close();
}
//void menu1::on_HomePage_clicked()
//{
//    mw = new MainWindow();
//    mw->show();
//    this->close();
//}

//void menu1::on_Back_clicked()
//{
//    m = new menu();
//    m->show();
//    this->close();
//}

void menu1::on_deletedetails_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/MBINDHU/Desktop/QT_PROJECT/Student/STUDENT1.db");
    del = new deletedetails();
    del->show();
    this->close();
}

void menu1::on_modify_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/MBINDHU/Desktop/QT_PROJECT/Student/STUDENT1.db");
    mod = new modifydetails();
    mod->show();
    this->close();

}

void menu1::on_get_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/MBINDHU/Desktop/QT_PROJECT/Student/STUDENT1.db");
    dis = new displaydetails();
    dis->show();
    this->close();
}


void menu1::on_highest_clicked()
{
    h = new highest();
    h->show();
    this->close();
}


void menu1::on_lowest_clicked()
{
    l = new lowest();
    l->show();
    this->close();
}



void menu1::on_searchdetails_clicked()
{
    s = new searchdetails();
    s->show();
    this->close();
}



void menu1::on_HOMEPAGE_clicked()
{
    mw = new MainWindow();
    mw->show();
    this->close();
}


void menu1::on_COUNT_clicked()
{
    ct = new count1();
    ct->show();
    this->close();
}


#include "getdetails.h"
#include "ui_getdetails.h"

getdetails::getdetails(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::getdetails)
{
    ui->setupUi(this);
}

getdetails::~getdetails()
{
    delete ui;
}

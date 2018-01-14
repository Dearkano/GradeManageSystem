#include "delete.h"
#include "ui_delete.h"

Delete::Delete(QWidget *parent):
    QDialog(parent),
    ui(new Ui::Delete)
{
    ui->setupUi(this);
}
Delete::~Delete(){delete ui;}
QString Delete::getCourse(){
    QString s = ui->lineEdit->text();
    return s;
}
QString Delete::getStudent(){
    QString s = ui->lineEdit_3->text();
    return s;
}
QString Delete::getTeacher(){
    QString s = ui->lineEdit_2->text();
    return s;
}
void Delete::on_buttonBox_accepted()
{

}

void Delete::on_buttonBox_rejected()
{

}

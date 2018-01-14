#include "add.h"
#include "ui_add.h"

Add::Add(QWidget *parent):
    QDialog(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);
}
Add::~Add(){delete ui;}
QString Add::getCourse(){
    QString s = ui->lineEdit->text();
    return s;
}
QString Add::getStudent(){
    QString s = ui->lineEdit_2->text();
    return s;
}
QString Add::getTeacher(){
    QString s = ui->lineEdit_3->text();
    return s;
}
QString Add::getGrade(){
    QString s = ui->lineEdit_4->text();
    return s;
}
void Add::on_buttonBox_accepted()
{

}

void Add::on_buttonBox_rejected()
{

}

#include "dialog2.h"
#include "ui_dialog2.h"
namespace Ui {
    class Dialog2;
}
Dialog2::Dialog2(QWidget *parent):
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
}
Dialog2::~Dialog2(){delete ui;}
QString Dialog2::getCourse()
{
    QString s = ui->lineEdit->text();
    return s;
}
QString Dialog2::getTeacher()
{
    QString s = ui->lineEdit_2->text();
    return s;
}
void Dialog2::SetLabel(QString A)
{
    ui->label->setText(A);
}
void Dialog2::on_buttonBox_accepted()
{

}

void Dialog2::on_buttonBox_rejected()
{

}

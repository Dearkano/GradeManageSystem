#include "signup.h"
#include "ui_signup.h"
SignUp::SignUp(QWidget *parent):
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
}
SignUp::~SignUp(){delete ui;}
QString SignUp::getName()
{
    QString s = ui->lineEdit->text();
    return s;
}
QString SignUp::getPassword()
{
    QString s = ui->lineEdit_2->text();
    return s;
}
void SignUp::SetLabel(QString A)
{
    ui->label->setText(A);
}
void SignUp::on_buttonBox_accepted()
{

}

void SignUp::on_buttonBox_rejected()
{

}
bool SignUp::isLogIn=false;

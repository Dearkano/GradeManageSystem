#include "alert.h"
#include "ui_alert.h"

Alert::Alert(QWidget *parent):
    QDialog(parent),
    ui(new Ui::Alert)
{
    ui->setupUi(this);
}
Alert::~Alert(){delete ui;}
void Alert::SetLabel(QString A)
{
    ui->label->setText(A);
}
void Alert::on_buttonBox_accepted()
{

}

void Alert::on_buttonBox_rejected()
{

}

#ifndef DIALOG2_H
#define DIALOG2_H
#include <QDialog>
#include "ui_dialog2.h"
#include "mainwindow.h"
namespace Ui {
    class Dialog2;
}
class Dialog2 : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog2(QWidget *parent = 0);
    ~Dialog2();
    QString getCourse();
    QString getTeacher();
    void SetLabel(QString A);
    void SetLabel_2(QString A);
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Dialog2 *ui;
};
#endif // DIALOG2_H


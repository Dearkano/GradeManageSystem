#ifndef ADD_H
#define ADD_H
#include <QDialog>
#include "mainwindow.h"
#include "ui_add.h"
class Add : public QDialog
{
    Q_OBJECT
public:
    explicit Add(QWidget *parent = 0);
    ~Add();
    QString getStudent();
    QString getTeacher();
    QString getCourse();
    QString getGrade();
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::Add *ui;
};
#endif // ADD_H

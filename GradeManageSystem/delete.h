#ifndef DELETE_H
#define DELETE_H
#include <QDialog>
#include "mainwindow.h"
#include "ui_delete.h"
class Delete : public QDialog
{
    Q_OBJECT
public:
    explicit Delete(QWidget *parent = 0);
    ~Delete();
    QString getStudent();
    QString getTeacher();
    QString getCourse();
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::Delete *ui;
};
#endif // Delete_H

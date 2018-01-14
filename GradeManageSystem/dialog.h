#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include "mainwindow.h"
#include "ui_dialog.h"
class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    QString getInput();
    void SetLabel(QString A);
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H

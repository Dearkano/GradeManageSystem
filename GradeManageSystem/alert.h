#ifndef ALERT_H
#define ALERT_H
#include <QDialog>
#include "mainwindow.h"
#include "ui_alert.h"
class Alert : public QDialog
{
    Q_OBJECT
public:
    explicit Alert(QWidget *parent = 0);
    ~Alert();
    void SetLabel(QString A);
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Alert *ui;
};
#endif // ALERT_H

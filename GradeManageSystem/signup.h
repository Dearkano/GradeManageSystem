#ifndef SIGNUP_H
#define SIGNUP_H
#include <QDialog>
#include "ui_signup.h"

class SignUp : public QDialog
{
    Q_OBJECT
public:
    explicit SignUp(QWidget *parent = 0);
    ~SignUp();
    QString getName();
    QString getPassword();
    void SetLabel(QString A);
    static bool isLogIn;
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::SignUp *ui;
};
#endif // SIGNUP_H

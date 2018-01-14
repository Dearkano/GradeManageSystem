#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "dialog2.h"
#include "signup.h"
#include "alert.h"
#include "delete.h"
#include "add.h"
#include <QDebug>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTextStream>
#include <stdio.h>
bool OpenDatabase()
{
    QSqlDatabase    dbconn;
    dbconn = QSqlDatabase::addDatabase("QMYSQL");
   //QString sname = QString::fromLocal8Bit("vayne");      //数据源名称
    dbconn.setHostName("localhost");//主机名字
    dbconn.setPort(3306);
    dbconn.setDatabaseName("vayne");//数据库名字
    dbconn.setUserName("root");//用户名
    dbconn.setPassword("745213");//密码
    if(!dbconn.open())                                      //打开数据库
    {
        qDebug()<<dbconn.lastError().text();
        QMessageBox::critical(0, QObject::tr("Database error"), dbconn.lastError().text());
        return false;                                   //打开失败
    }
    else
        qDebug()<<"database open success!";
    return true;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::MainWindow)
{
    OpenDatabase();

    ui->setupUi(this);
}
void MainWindow::on_pushButton_clicked(){
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query;
    Dialog2 dialog;
    dialog.SetLabel("课程");
    dialog.SetLabel_2("教师");
    dialog.exec();
    if(dialog.result() == Dialog2::Rejected)
        return;
    QString course = dialog.getCourse();
    QString teacher = dialog.getTeacher();
    model->setQuery("select * from student_course where  teacher = '"+teacher+"' and course = '"+course+"';");//这里直接设置SQL语句，忽略最后一个参数
    ui->tableView->setModel(model);
}
void MainWindow::on_pushButton_2_clicked(){
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query;
    Dialog dialog;
    dialog.SetLabel("学生姓名");
    dialog.exec();
    if(dialog.result() == Dialog::Rejected)
        return;
    QString result = dialog.getInput();
    model->setQuery("select * from student_course where  name = '"+result+"';");//这里直接设置SQL语句，忽略最后一个参数
    ui->tableView->setModel(model);
}
void MainWindow::on_pushButton_3_clicked(){
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query;
    Dialog dialog;
    dialog.SetLabel("学科");
    dialog.exec();
    if(dialog.result() == Dialog::Rejected)
        return;
    QString result = dialog.getInput();
    model->setQuery("select * from student_course where  course = '"+result+"';");//这里直接设置SQL语句，忽略最后一个参数
    ui->tableView->setModel(model);
}
void MainWindow::on_pushButton_4_clicked(){
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query;
    Dialog dialog;
    dialog.SetLabel("课程");
    dialog.exec();
    if(dialog.result() == Dialog::Rejected)
        return;
    QString result = dialog.getInput();
    model->setQuery("select * from student_course where  course = '"+result+"';");//这里直接设置SQL语句，忽略最后一个参数
    ui->tableView->setModel(model);
}
void MainWindow::on_pushButton_5_clicked(){
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query;
    SignUp dialog;
    dialog.SetLabel("用户名");
    dialog.SetLabel_2("密码");
    dialog.exec();
    if(dialog.result() == SignUp::Rejected)
        return;
    QString name = dialog.getName();
    QString password = dialog.getPassword();
    query.exec("insert into user (name,password) values('"+name+"','"+password+"');");//这里直接设置SQL语句，忽略最后一个参数
    QSqlError error = query.lastError();
    if(error.isValid())//发生错误时isValid()返回true
    {
        switch (error.type())
        {
             case QSqlError::NoError:
                   break;
        default:
               //ErrorBox("格式错误.");
               return;
        }
    }
}
void MainWindow::on_pushButton_6_clicked(){

    QSqlQueryModel *model = new QSqlQueryModel;
    SignUp dialog;
    dialog.SetLabel("用户名");
    dialog.SetLabel_2("密码");
    dialog.exec();
    if(dialog.result() == SignUp::Rejected)
        return;
    QString name = dialog.getName();
    QString password = dialog.getPassword();
    QSqlQuery query("select password from user where name ='"+name+"';");//这里直接设置SQL语句，忽略最后一个参数
    query.next();
    QString _password = query.value(0).toString();//获取密码
    if(password==_password){
        SignUp::isLogIn=true;
        Alert alert;
        alert.SetLabel("登录成功!");
        alert.exec();
    }
    else{
        Alert alert;
        alert.SetLabel("密码错误!");
        alert.exec();
    }
    QSqlError error = query.lastError();
    if(error.isValid())//发生错误时isValid()返回true
    {
        switch (error.type())
        {
             case QSqlError::NoError:
                   break;
        default:
               //ErrorBox("格式错误.");
               return;
        }
    }
}
//录入信息
void MainWindow::on_pushButton_7_clicked(){
    QTextStream cin(stdin,  QIODevice::ReadOnly);
    QTextStream cout(stdout,  QIODevice::WriteOnly);
    QTextStream cerr(stderr,  QIODevice::WriteOnly);
    QSqlQueryModel *model = new QSqlQueryModel;
    if(SignUp::isLogIn){
        QSqlQuery query;
        Add dialog;
        dialog.exec();
        if(dialog.result() == Add::Rejected)
            return;
        QString student = dialog.getStudent();
        QString course = dialog.getCourse();
        QString teacher = dialog.getTeacher();
        QString grade = dialog.getGrade();
        QString str = "insert into student_course (name,course,teacher,grade) values('"+student+"','"+course+"','"+teacher+"','"+grade+"');";
        query.exec(str);//这里直接设置SQL语句，忽略最后一个参数
        QSqlError error = query.lastError();
        if(error.isValid())//发生错误时isValid()返回true
        {
            switch (error.type())
            {
                 case QSqlError::NoError:
                       break;
            default:
                Alert alert;
                alert.SetLabel("添加失败!");
                alert.exec();
                   return;
            }
        }
        Alert alert;
        alert.SetLabel("添加成功!");
        alert.exec();
    }else{
        Alert alert;
        alert.SetLabel("未登录!");
        alert.exec();
    }

}
//修改信息
void MainWindow::on_pushButton_8_clicked(){
   if(SignUp::isLogIn){
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query;
    Add dialog;
    dialog.exec();
    if(dialog.result() == Add::Rejected)
        return;
    QString student = dialog.getStudent();
    QString course = dialog.getCourse();
    QString teacher = dialog.getTeacher();
    QString grade = dialog.getGrade();
    QString str = "update student_course set grade = '"+grade+"'where name = '"+student+"'and course ='"+course+"'and teacher = '"+teacher+"';";
    query.exec(str);//这里直接设置SQL语句，忽略最后一个参数
    QSqlError error = query.lastError();
    if(error.isValid())//发生错误时isValid()返回true
    {
        switch (error.type())
        {
             case QSqlError::NoError:
                   break;
        default:
            Alert alert;
            alert.SetLabel("修改失败!");
            alert.exec();
               return;
        }
    }
    Alert alert;
    alert.SetLabel("修改成功!");
    alert.exec();
   }else{
       Alert alert;
       alert.SetLabel("未登录!");
       alert.exec();
   }
}
//删除成绩
void MainWindow::on_pushButton_9_clicked(){
    if(SignUp::isLogIn){
    QTextStream cin(stdin,  QIODevice::ReadOnly);
    QTextStream cout(stdout,  QIODevice::WriteOnly);
    QTextStream cerr(stderr,  QIODevice::WriteOnly);
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query;
    Delete dialog;
    dialog.exec();
    if(dialog.result() == Add::Rejected)
        return;
    QString student = dialog.getStudent();
    QString course = dialog.getCourse();
    QString teacher = dialog.getTeacher();
    QString str = "delete from student_course where name = '"+student+"'and course ='"+course+"'and teacher = '"+teacher+"';";
    cout<<str;
    query.exec(str);//这里直接设置SQL语句，忽略最后一个参数
    QSqlError error = query.lastError();
    if(error.isValid())//发生错误时isValid()返回true
    {
        switch (error.type())
        {
             case QSqlError::NoError:
                   break;
        default:
            Alert alert;
            alert.SetLabel("删除失败!");
            alert.exec();
               return;
        }
    }
    Alert alert;
    alert.SetLabel("删除成功!");
    alert.exec();
    }else{
        Alert alert;
        alert.SetLabel("未登录!");
        alert.exec();
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}

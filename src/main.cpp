#include "mainwindow.h"
#include<QPushButton>
#include <QApplication>
#include<QObject>
#include<QFont>
#include<QString>
#include"Value.h"
#pragma comment(lib, "user32.lib")
Value a,b,c;int i=0,j=0,k=0,fh=-1;

 namespace t{
    void f1(Value &p,QString &str);
} 
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);mainwindow w;Ui_mainwindow *p=w.ui;QFont font=p->lineEdit->font();
    font.setPointSize(25);p->lineEdit->setFont(font);
QObject::connect(p->Btn1,&QPushButton::clicked,&w,[=](){p->lineEdit->insert("1");});
QObject::connect(p->Btn2,&QPushButton::clicked,&w,[=](){p->lineEdit->insert("2");});
QObject::connect(p->Btn3,&QPushButton::clicked,&w,[=](){p->lineEdit->insert("3");});
QObject::connect(p->Btn4,&QPushButton::clicked,&w,[=](){p->lineEdit->insert("4");});
QObject::connect(p->Btn5,&QPushButton::clicked,&w,[=](){p->lineEdit->insert("5");});
QObject::connect(p->Btn6,&QPushButton::clicked,&w,[=](){p->lineEdit->insert("6");});
QObject::connect(p->Btn7,&QPushButton::clicked,&w,[=](){p->lineEdit->insert("7");});
QObject::connect(p->Btn8,&QPushButton::clicked,&w,[=](){p->lineEdit->insert("8");});
QObject::connect(p->Btn9,&QPushButton::clicked,&w,[=](){p->lineEdit->insert("9");});
QObject::connect(p->Btn0,&QPushButton::clicked,&w,[=](){p->lineEdit->insert("0");});
QObject::connect(p->BtnAdd,&QPushButton::clicked,&w,[=](){
if(++i<2){fh=1;QString str=p->lineEdit->text();p->lineEdit->insert("+");k=str.size();t::f1(::a,str);}j=0;

});
QObject::connect(p->BtnSub,&QPushButton::clicked,&w,[=](){
if(++i<2){fh=2;QString str=p->lineEdit->text();p->lineEdit->insert("-");k=str.size();t::f1(::a,str);}j=0;
});
QObject::connect(p->BtnChen,&QPushButton::clicked,&w,[=](){
if(++i<2){fh=3;QString str=p->lineEdit->text();p->lineEdit->insert("x");k=str.size();t::f1(::a,str);}j=0;
});
QObject::connect(p->BtnChu,&QPushButton::clicked,&w,[=](){
if(++i<2){fh=4;QString str=p->lineEdit->text();p->lineEdit->insert("÷");k=str.size();t::f1(::a,str);}j=0;
});
QObject::connect(p->BtnOutput,&QPushButton::clicked,&w,[=](){
QString str=p->lineEdit->text();str=str.mid(::k+1);t::f1(::b,str);
switch(fh){
    case(1): ::c=::a+::b;break;
    case(2): ::c=::a-::b;break;
    case(3): ::c=::a*::b;break;
    case(4): ::c=::a/::b;break;
}
str=QString::fromStdString(Value::toString(c));
p->BtnCE->clicked();p->lineEdit->setText(str);
});
QObject::connect(p->BtnD,&QPushButton::clicked,&w,[=](){
if(++j<2)p->lineEdit->insert(".");
});
QObject::connect(p->BtnCE,&QPushButton::clicked,&w,[=](){p->lineEdit->clear();Value t1;::a=::b=::c=t1;::i=::j=0;});

    w.show();return a.exec();
}
void t::f1(Value &p,QString &str){
p=str.toStdString();
}
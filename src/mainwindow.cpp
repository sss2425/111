#include "mainwindow.h"
#include<QLineEdit>
#include<Qdir>
mainwindow::mainwindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_mainwindow)
{
    ui->setupUi(this);
    setWindowTitle("简易计算器");setWindowIcon(QIcon(("../111.png")));
    ui->lineEdit->setFocusPolicy(Qt::NoFocus);ui->lineEdit->setAlignment(Qt::AlignRight);
}

mainwindow::~mainwindow()
{
    delete ui; 
}
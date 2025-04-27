#pragma once
#include "ui_mainwindow.h"
#include <QMainWindow>

class mainwindow : public QMainWindow {
    Q_OBJECT
    
public:
    mainwindow(QWidget* parent = nullptr);
    ~mainwindow();
    Ui_mainwindow* ui;
};
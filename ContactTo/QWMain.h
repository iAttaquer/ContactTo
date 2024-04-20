#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QLabel>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLineEdit>
#include "ui_QWMain.h"
#include <pqxx/pqxx>

class QWMain : public QMainWindow
{
    Q_OBJECT

public:
    QWMain(QWidget *parent = nullptr);
    ~QWMain();
private slots:
    void createnavbar();
    void createwadd();

public slots:
    void ShowMain();
    void ShowFavourite();
    void ShowSettings();
    void ShowAdd();
    void ShowContact();
    void ShowEdit();
    void BackMain();
    void BackContact();
    void on_pushButton_clicked();//test

private:
    Ui::QWMainClass ui;
    QWidget* navbar = nullptr;
    QWidget* wmain = nullptr;
    QWidget* wfavourite = nullptr;
    QWidget* waddbg = nullptr;
    QWidget* wsettings = nullptr;
    QWidget* wcontactbg = nullptr;
    QWidget* weditbg = nullptr;
};

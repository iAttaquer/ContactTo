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
#include "pgDbClient.h"

class QWMain : public QMainWindow
{
    Q_OBJECT

public:
    QWMain(QWidget *parent = nullptr);
    ~QWMain();
private slots:
    void createnavbar();
    void createwadd();
    void createlist();

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
    pgDbClient pg;
    QWidget* navbar = nullptr;
    QWidget* wmain = nullptr;
    QScrollArea* wmainscroll = nullptr;
    QWidget* wfavourite = nullptr;
    QWidget* waddbg = nullptr;
    QWidget* wsettings = nullptr;
    QWidget* wcontactbg = nullptr;
    QWidget* weditbg = nullptr;

};

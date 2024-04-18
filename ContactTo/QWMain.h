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
#include "ui_QWMain.h"

class QWMain : public QMainWindow
{
    Q_OBJECT

public:
    QWMain(QWidget *parent = nullptr);
    ~QWMain();
private slots:
    void createnavbar();

public slots:
    void ShowMain();
    void ShowFavourite();
    void ShowSettings();
    void ShowContact();
    void ShowAdd();
    void BackMain();

private:
    Ui::QWMainClass ui;
    QWidget* navbar;
    QWidget* wmain;
    QWidget* wfavourite;
    QWidget* wsettings;
    QWidget* wcontactbg;
};

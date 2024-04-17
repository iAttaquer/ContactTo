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

public slots:
    void ShowMain();
    void ShowFavourite();
    void ShowSettings();

private:
    Ui::QWMainClass ui;
    QWidget* navbar;
    QWidget* wmain;
    QWidget* wfavourite;
    QWidget* wsettings;
};

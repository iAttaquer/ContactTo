#pragma once     
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QLabel>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLineEdit>
#include <QRegularExpressionValidator>
#include <QRegularExpression>
#include "ui_QWMain.h"
#include "pgDbClient.h"

class QWMain : public QMainWindow
{
    Q_OBJECT

public:
    QWMain(QWidget *parent = nullptr);
    ~QWMain();   

public slots:
    void createnavbar();
    void createlist();
    void createfavourite();
    void createfavouritelist();
    void createwadd();
    void createsettings();
    void ShowMain();
    void ShowFavourite();
    void ShowSettings();
    void ShowAdd();
    void ShowContact(int id, QWidget* w);
    void ShowEdit(FullContact c, QWidget* w);
    void BackMain();
    void BackFavourite();
    void BackContact();
    void AddContact(FullContact c);
    void DeleteContact(int id, QWidget* w);
    void EditContact(FullContact c, QWidget* w);
    void ChangeFavourite(int id, QPushButton* btn);

private:
    Ui::QWMainClass ui;
    pgDbClient pg;
    QWidget* navbar = nullptr;
    QWidget* wmain = nullptr;
    QScrollArea* wmainscroll = nullptr;
    QWidget* wfavourite = nullptr;
    QScrollArea* wfavouritescroll = nullptr;
    QWidget* waddbg = nullptr;
    QWidget* wsettingsbg = nullptr;
    QWidget* wcontactbg = nullptr;
    QWidget* weditbg = nullptr;

};

#include "QWMain.h"
#include <QSize>
#include <QtWidgets/QMessageBox>
QWMain::QWMain(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->setWindowTitle("ContactTo");
	this->setFixedSize(600, 450);

	// Navigation Bar
    createnavbar();

    // Main Widget
    wmain = new QWidget(this);
    wmain->setGeometry(QRect(0, 50, 600, 400));

    // infobar widget
    QWidget* infobar = new QWidget(wmain);
    infobar->setGeometry(0, 0, 600, 20);
    infobar->setStyleSheet("QWidget {"
        "   background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #1C1F26, stop: 1 #1E1E1E);"
        "}"
        "QLabel {"
        "   color: #9FAABF;}"
    );

    QHBoxLayout* ilayout = new QHBoxLayout(infobar);
    ilayout->setContentsMargins(2, 2, 2, 2);
    
    QLabel* iid = new QLabel("ID");
    iid->setFont(QFont("poppins", 10));
    iid->setMaximumWidth(90);
    iid->setContentsMargins(30, 0, 0, 0);
    iid->setAlignment(Qt::AlignHCenter);
    ilayout->addWidget(iid);

    QFrame* line1 = new QFrame(wmain);
    line1->setFrameShape(QFrame::VLine);
    line1->setFrameShadow(QFrame::Sunken);
    ilayout->addWidget(line1);

    QLabel* iname = new QLabel("Firstname");
    iname->setFont(QFont("poppins", 10));
    iname->setAlignment(Qt::AlignHCenter);
    ilayout->addWidget(iname);

    QFrame* line2 = new QFrame(wmain);
    line2->setFrameShape(QFrame::VLine);
    line2->setFrameShadow(QFrame::Sunken);
    ilayout->addWidget(line2);

    QLabel* ilastname = new QLabel("Lastname");
    ilastname->setFont(QFont("poppins", 10));
    ilastname->setAlignment(Qt::AlignHCenter);
    ilayout->addWidget(ilastname);

    QFrame* line3 = new QFrame(wmain);
    line3->setFrameShape(QFrame::VLine);
    line3->setFrameShadow(QFrame::Sunken);
    ilayout->addWidget(line3);

    QLabel* inumber = new QLabel("Number");
    inumber->setFont(QFont("poppins", 10));
    inumber->setAlignment(Qt::AlignHCenter);
    inumber->setContentsMargins(0, 0, 60, 0);
    inumber->setMinimumWidth(190);
    ilayout->addWidget(inumber);

    // scrollarea
	QScrollArea* wmainscroll = new QScrollArea(wmain);
	wmainscroll->setGeometry(QRect(0, 20, 600, 380));
    wmainscroll->setWidgetResizable(true);
   
    
    QWidget* scontainer = new QWidget;
    scontainer->setGeometry(QRect(0, 0, 600, 380)); 
    scontainer->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #1C1F26, stop: 1 #1E1E1E);");
    QVBoxLayout* wmainlayout = new QVBoxLayout(scontainer);
    wmainlayout->setContentsMargins(15, 10, 15, 10);
    wmainlayout->setSpacing(10);

    for (int i = 0; i < 20; i++)
    {
        QPushButton* contactframe = new QPushButton();
        contactframe->setFixedSize(550, 50);
        contactframe->setStyleSheet("QPushButton {"
            "color: #23272F;"
            "border-radius: 25px;"
            "background-color: #23272F;"
        "}"
        "QPushButton:hover {"
            "color: #2D323D;"
        "   background-color: #2B303B;"
        "}"
            "QLabel {"
            "background-color: #333742;"
            "border-radius: 8px;"
            "color: #B8C3D9;"
            "}"
            "QLabel:hover {"
            "background-color: #333742;"
            "color: #B8C3D9;"
            "}"
        );
        connect(contactframe, SIGNAL(clicked()), this, SLOT(ShowContact()));
        wmainlayout->addWidget(contactframe);
        QLabel* cid = new QLabel(contactframe);
        cid->setText(QString("%1").arg(i+1));
        cid->setFont(QFont("poppins", 10));
        cid->setGeometry(25, 15, 40, 20);
        cid->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        QLabel* cfirstname = new QLabel(contactframe);
        cfirstname->setText("Imie");
        cfirstname->setFont(QFont("poppins", 10));
        cfirstname->setGeometry(85, 15, 140, 20);
        cfirstname->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        QLabel* clastname = new QLabel(contactframe);
        clastname->setText("Nazwisko");
        clastname->setFont(QFont("poppins", 10));
        clastname->setGeometry(240, 15, 140, 20);
        clastname->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        QLabel* cnumber = new QLabel(contactframe);
        cnumber->setText("Numer");
        cnumber->setFont(QFont("poppins", 10));
        cnumber->setGeometry(400, 15, 120, 20);
        cnumber->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    }
    wmainscroll->setWidget(scontainer);

    // Favourite Widget
    wfavourite = new QWidget(this);
    wfavourite->setGeometry(QRect(0, 50, 600, 400));
    wfavourite->setStyleSheet("background-color: rgb(0, 0, 255)");
    wfavourite->hide();

	// Settings Widget
    wsettings = new QWidget(this);
    wsettings->setGeometry(QRect(0, 50, 600, 400));
    wsettings->setStyleSheet("background-color: rgb(255, 0, 0)");
    wsettings->hide();
 
}
QWMain::~QWMain()
{}
void QWMain::createnavbar()
{
    navbar = new QWidget(this);
    navbar->setGeometry(QRect(0, 0, 600, 50));
    navbar->setStyleSheet(
        "QWidget {"
        "align-items: center;"
        "background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #1C1F26, stop: 1 #1E1E1E);"
        "}"
        "QPushButton {"
        "    color: #9FAABF;"
        "    background-color: #23272F;"
        "    border-radius: 12px;}"
        "QPushButton:hover {"
        "    color: #fff;"
        "    background-color: #2B303B;"
        "}");
    QHBoxLayout* nlayout = new QHBoxLayout(navbar);

    QPushButton* main = new QPushButton();
    main->setIcon(QIcon(":/images/images/mainbook_icon.svg"));
    main->setText(" Main");
    main->setFont(QFont("Poppins", 12, QFont::Bold));
    main->setFixedSize(QSize(110, 35));
    connect(main, SIGNAL(clicked()), this, SLOT(ShowMain()));
    nlayout->addWidget(main);

    QPushButton* favourite = new QPushButton();
    favourite->setIcon(QIcon(":/images/images/star_icon.svg"));
    favourite->setText(" Favourite");
    favourite->setFont(QFont("Poppins", 12, QFont::Bold));
    favourite->setFixedSize(QSize(110, 35));
    connect(favourite, SIGNAL(clicked()), this, SLOT(ShowFavourite()));
    nlayout->addWidget(favourite);

    QPushButton* add = new QPushButton();
    add->setIcon(QIcon(":/images/images/plus_icon.svg"));
    add->setText(" Add");
    add->setFont(QFont("Poppins", 12, QFont::Bold));
    add->setFixedSize(QSize(110, 35));

    nlayout->addWidget(add);

    QPushButton* settings = new QPushButton();
    settings->setIcon(QIcon(":/images/images/settings_icon.svg"));
    settings->setText(" Settings");
    settings->setFont(QFont("Poppins", 12, QFont::Bold));
    settings->setFixedSize(QSize(110, 35));
    connect(settings, SIGNAL(clicked()), this, SLOT(ShowSettings()));
    nlayout->addWidget(settings);
}
void QWMain::ShowMain()
{
    if (!wmain->isVisible())
    {
		wfavourite->hide();
        wsettings->hide();
		wmain->show();
    }
}
void QWMain::ShowFavourite()
{
    if (!wfavourite->isVisible())
    {
		wmain->hide();
		wsettings->hide();
		wfavourite->show();
    }
}
void QWMain::ShowSettings()
{
    if (!wsettings->isVisible())
    {
        wmain->hide();
		wfavourite->hide();
		wsettings->show();
    }
}
void QWMain::ShowContact()
{
    if (wmain->isVisible())
    {
        wmain->hide();
    }
    if (navbar->isVisible())
    {
        navbar->hide();
    }
    if (wcontactbg)
    {
        wcontactbg = new QWidget(this);
        wcontactbg->setGeometry(0, 0, 600, 450);
        wcontactbg->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #1C1F26, stop: 1 #1E1E1E);");
        QWidget* wcontact = new QWidget(wcontactbg);
        wcontact->setGeometry(25, 25, 550, 400);
        wcontact->setStyleSheet(
            "background-color: #23272F;"
            "border-radius: 20px;"
        );
        QFrame* cnavbar = new QFrame(wcontact);
        cnavbar->setFixedSize(550, 50);
        cnavbar->setStyleSheet(
            "QFrame {"
            //"background-color: red;"
            "}"
            "QPushButton {"
            //"   background-color: #23272F;"
        "}"
            "QPushButton:hover {"
            "   background-color: #2B303B;}"
        );
        QPushButton* cback = new QPushButton(cnavbar);
        cback->setGeometry(10, 5, 40, 40);
        cback->setIcon(QIcon(":/images/images/back_icon.svg"));
        cback->setIconSize(QSize(20, 20));
        connect(cback, SIGNAL(clicked()), this, SLOT(BackMain()));

        QPushButton* cedit = new QPushButton(cnavbar);
        cedit->setGeometry(450, 5, 40, 40);
        cedit->setIcon(QIcon(":/images/images/edit_icon.svg"));
        cedit->setIconSize(QSize(18, 18));


        QPushButton* cdelete = new QPushButton(cnavbar);
        cdelete->setGeometry(500, 5, 40, 40);
        cdelete->setIcon(QIcon(":/images/images/trash_icon.svg"));

        wcontactbg->show();
    }   
    //QMessageBox::warning(this, "Warning", "Coś nie działa");

}
void QWMain::ShowAdd()
{
    // TODO!!!
}
void QWMain::BackMain()
{
    if (wcontactbg->isVisible())
    {
        wcontactbg->hide();
        navbar->show();
        wmain->show();
    }
}
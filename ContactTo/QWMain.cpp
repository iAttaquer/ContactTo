#include "QWMain.h"
#include <QSize>
QWMain::QWMain(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->setWindowTitle("ContactTo");
	this->setFixedSize(600, 450);

	// Navigation Bar
    navbar = new QWidget(this);
    navbar->setGeometry(QRect(0, 0, 600, 50));
    navbar->setStyleSheet(
        "align-items: center;"
		//"background-color: #9FAABF;"
		"background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #1C1F26, stop: 1 #1E1E1E);"
    );
    QHBoxLayout* nlayout = new QHBoxLayout(navbar);
    //nlayout->setStyleSheet("align-items: left;");
    QPushButton* main = new QPushButton();
    main->setText("Main");
    main->setFont(QFont("Poppins", 12, QFont::Bold));
    main->setFixedSize(QSize(100, 35));
    main->setStyleSheet("QPushButton {"
        "    color: #9FAABF;"
        "    background-color: #23272F;"
        "    border-radius: 12px;"
        "    transition: transform 0.2s;}"
        "QPushButton:hover {"
		"    color: #fff;"
        "    background-color: #2B303B;"
        "    transform: scale(1.1);"
        "}");
    connect(main, SIGNAL(clicked()), this, SLOT(ShowMain()));
    nlayout->addWidget(main);

    QPushButton* favourite = new QPushButton();
    favourite->setText("Favourite");
	favourite->setFont(QFont("Poppins", 12, QFont::Bold));
    favourite->setFixedSize(QSize(100, 35));
    favourite->setStyleSheet("QPushButton {"
        "    color: #9FAABF;"
        "    background-color: #23272F;"
        "    border-radius: 12px;}"
        "QPushButton:hover {"
        "    color: #fff;"
        "    background-color: #2B303B;"
        "    text-shadow: red -3px 0, cyan 3px 0;"  
        "}");
	connect(favourite, SIGNAL(clicked()), this, SLOT(ShowFavourite()));
    nlayout->addWidget(favourite);

    QPushButton* settings = new QPushButton();
    settings->setText("Settings");
	settings->setFont(QFont("Poppins", 12, QFont::Bold));
    settings->setFixedSize(QSize(100, 35));
    settings->setStyleSheet("QPushButton {"
        "    color: #9FAABF;"
        "    background-color: #23272F;"
        "    border-radius: 12px;}"
        "QPushButton:hover {"
        "    color: #fff;"
        "    background-color: #2B303B;"
        "}");
	connect(settings, SIGNAL(clicked()), this, SLOT(ShowSettings()));
    nlayout->addWidget(settings);

    // Main Widget
    wmain = new QWidget(this);
    wmain->setGeometry(QRect(0, 50, 600, 400));
    wmain->setStyleSheet("QPushButton{"
        "padding: 5px;"
        "margin: 5px;"
    "}");

    // infobar widget
    QWidget* infobar = new QWidget(wmain);
    infobar->setGeometry(0, 0, 600, 20);
    infobar->setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #1C1F26, stop: 1 #1E1E1E);");

    QHBoxLayout* ilayout = new QHBoxLayout(infobar);
    ilayout->setContentsMargins(2, 2, 2, 2);
    
    QLabel* iid = new QLabel("ID");
    iid->setMaximumWidth(90);
    iid->setContentsMargins(30, 0, 0, 0);
    iid->setAlignment(Qt::AlignHCenter);
    ilayout->addWidget(iid);

    QFrame* line1 = new QFrame(wmain);
    line1->setFrameShape(QFrame::VLine);
    line1->setFrameShadow(QFrame::Sunken);
    ilayout->addWidget(line1);

    QLabel* iname = new QLabel("Imie");
    iname->setAlignment(Qt::AlignHCenter);
    ilayout->addWidget(iname);

    QFrame* line2 = new QFrame(wmain);
    line2->setFrameShape(QFrame::VLine);
    line2->setFrameShadow(QFrame::Sunken);
    ilayout->addWidget(line2);

    QLabel* ilastname = new QLabel("Nazwisko");
    ilastname->setAlignment(Qt::AlignHCenter);
    ilayout->addWidget(ilastname);

    QFrame* line3 = new QFrame(wmain);
    line3->setFrameShape(QFrame::VLine);
    line3->setFrameShadow(QFrame::Sunken);
    ilayout->addWidget(line3);

    QLabel* inumber = new QLabel("Numer");
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
        QFrame* contactframe = new QFrame();
        contactframe->setFixedSize(550, 50);
        contactframe->setStyleSheet("QFrame {"
            "border-radius: 25px;"
            "background-color: red;"
        "}"
        "QFrame:hover {"
        "   background-color: white;"
        "}");
        //QPushButton* button = new QPushButton(QString("Przycisk %1").arg(i + 1));
        wmainlayout->addWidget(contactframe);

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
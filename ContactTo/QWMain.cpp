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
            "   color: #23272F;"
            "   border-radius: 25px;"
            "   background-color: #23272F;"
            "}"
            "QPushButton:hover {"
            "   color: #2D323D;"
            "   background-color: #2B303B;"
            "}"
            "QLabel {"
            "   font-family: Poppins;"
            "   font-size: 10pt;"
            "   background-color: #333742;"
            "   border-radius: 8px;"
            "   color: #B8C3D9;"
            "   text-align: center;"
            "   qproperty-alignment: AlignCenter;"
            "}"
            "QLabel:hover {"
            "   background-color: #333742;"
            "   color: #B8C3D9;"
            "}"
        );
        connect(contactframe, SIGNAL(clicked()), this, SLOT(ShowContact()));
        wmainlayout->addWidget(contactframe);
        QLabel* cid = new QLabel(contactframe);
        cid->setText(QString("%1").arg(i+1));
        cid->setGeometry(25, 15, 40, 20);
        QLabel* cfirstname = new QLabel(contactframe);
        cfirstname->setText("Imie");
        cfirstname->setGeometry(85, 15, 140, 20);
        QLabel* clastname = new QLabel(contactframe);
        clastname->setText("Nazwisko");
        clastname->setGeometry(240, 15, 140, 20);
        QLabel* cnumber = new QLabel(contactframe);
        cnumber->setText("Numer");
        cnumber->setGeometry(400, 15, 120, 20);
    }
    wmainscroll->setWidget(scontainer);

    // Favourite Widget
    wfavourite = new QWidget(this);
    wfavourite->setGeometry(QRect(0, 50, 600, 400));
    wfavourite->setStyleSheet("background-color: rgb(0, 0, 255)");
    wfavourite->hide();

    // Add Widget
    createwadd();

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
        "background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #1C1F26, stop: 1 #1E1E1E);"
        "}"
        "QPushButton {"
        "   max-width: 110px;"
        "   min-width: 110px;"
        "   max-height: 35px;"
        "   min-height: 35px;"
        "   font-family: Poppins;"
        "   font-size: 12pt;"
        "   font-weight: bold;"
        "   color: #9FAABF;"
        "   background-color: #23272F;"
        "   border-radius: 12px;}"
        "QPushButton:hover {"
        "   color: #fff;"
        "   background-color: #2B303B;"
        "}");
    QHBoxLayout* nlayout = new QHBoxLayout(navbar);

    QPushButton* main = new QPushButton();
    main->setIcon(QIcon(":/images/images/mainbook_icon.svg"));
    main->setText(" Main");
    connect(main, SIGNAL(clicked()), this, SLOT(ShowMain()));
    nlayout->addWidget(main);

    QPushButton* favourite = new QPushButton();
    favourite->setIcon(QIcon(":/images/images/star_icon.svg"));
    favourite->setIconSize(QSize(18, 18));
    favourite->setText(" Favourite");
    connect(favourite, SIGNAL(clicked()), this, SLOT(ShowFavourite()));
    nlayout->addWidget(favourite);

    QPushButton* add = new QPushButton();
    add->setIcon(QIcon(":/images/images/plus_icon.svg"));
    add->setText(" Add");
    connect(add, SIGNAL(clicked()), this, SLOT(ShowAdd()));
    nlayout->addWidget(add);

    QPushButton* settings = new QPushButton();
    settings->setIcon(QIcon(":/images/images/settings_icon.svg"));
    settings->setText(" Settings");
    connect(settings, SIGNAL(clicked()), this, SLOT(ShowSettings()));
    nlayout->addWidget(settings);
}
void QWMain::createwadd()
{
    waddbg = new QWidget(this);
    waddbg->setGeometry(QRect(0, 50, 600, 400));
    waddbg->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #1C1F26, stop: 1 #1E1E1E);");
    QWidget* wadd = new QWidget(waddbg);
    wadd->setGeometry(25, 15, 550, 360);
    wadd->setStyleSheet(
        "QWidget {"
        "background-color: #23272F;"
        "border-radius: 20px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #2B303B;"
        "}"
    );
    QFrame* anavbar = new QFrame(wadd);
    anavbar->setFixedSize(550, 50);

    QPushButton* asave = new QPushButton(anavbar);
    asave->setGeometry(500, 5, 40, 40);
    asave->setIcon(QIcon(":/images/images/save_icon.svg"));
    asave->setIconSize(QSize(20, 20));

    QFrame* alayout = new QFrame(wadd);
    alayout->setGeometry(0, 50, 550, 300);
    alayout->setStyleSheet(
        "QFrame {"
        "   background-color: #23272F;"
        "   font-family: Poppins;"
        "   font-size: 10pt;"
        "}"
        "QLabel {"
        "   color: #9FAABF;"
        "   text-align: center;"
        "   qproperty-alignment: AlignCenter;"
        "}"
        "QPushButton {"
        "   font-family: Poppins;"
        "   font-size: 10pt;"
        "   background-color: #333742;"
        "   border-radius: 12px;"
        "}"
        "QLineEdit {"
        "   font-family: Poppins;"
        "   font-size: 10pt;"
        "   text-align: center;"
        "   qproperty-alignment: AlignCenter;"
        "   background-color: #333742;"
        "   border-radius: 12px;"
        "}"
    );
    QLabel* afirstnamelabel = new QLabel(alayout);
    afirstnamelabel->setText("Firstname");
    afirstnamelabel->setGeometry(20, 0, 150, 20);

    QLabel* alastnamelabel = new QLabel(alayout);
    alastnamelabel->setText("Lastname");
    alastnamelabel->setGeometry(200, 0, 150, 20);

    QLabel* anicknamelabel = new QLabel(alayout);
    anicknamelabel->setText("Nickname");
    anicknamelabel->setGeometry(380, 0, 150, 20);

    /*QLabel* aidlabel = new QLabel(alayout);
    aidlabel->setText("ID");
    aidlabel->setGeometry(30, 80, 40, 20);*/

    QLabel* anumberlabel = new QLabel(alayout);
    anumberlabel->setText("Phone Number");
    anumberlabel->setGeometry(95, 80, 150, 20);

    QLabel* ahomenumberlabel = new QLabel(alayout);
    ahomenumberlabel->setText("Home Number");
    ahomenumberlabel->setGeometry(305, 80, 150, 20);

    QLabel* aemaillabel = new QLabel(alayout);
    aemaillabel->setText("Email");
    aemaillabel->setGeometry(225, 160, 100, 20);

    QLabel* acompanylabel = new QLabel(alayout);
    acompanylabel->setText("Company");
    acompanylabel->setGeometry(80, 240, 150, 20);

    QLabel* apositionlabel = new QLabel(alayout);
    apositionlabel->setText("Position");
    apositionlabel->setGeometry(320, 240, 150, 20);

    //data
    QLineEdit* afirstname = new QLineEdit(alayout);
    afirstname->setPlaceholderText("Jan");
    afirstname->setGeometry(20, 21, 150, 25);

    QLineEdit* alastname = new QLineEdit(alayout);
    alastname->setPlaceholderText("Kowalski");
    alastname->setGeometry(200, 21, 150, 25);

    QLineEdit* anickname = new QLineEdit(alayout);
    anickname->setPlaceholderText("Jasiek");
    anickname->setGeometry(380, 21, 150, 25);

    /*QPushButton* aid = new QPushButton(alayout);
    aid->setText("id");
    aid->setGeometry(30, 101, 40, 25);*/

    QLineEdit* anumber = new QLineEdit(alayout);
    anumber->setPlaceholderText("123456789");
    anumber->setGeometry(95, 101, 150, 25);

    QLineEdit* ahomenumber = new QLineEdit(alayout);
    ahomenumber->setPlaceholderText("987654321");
    ahomenumber->setGeometry(305, 101, 150, 25);

    QLineEdit* aemail = new QLineEdit(alayout);
    aemail->setPlaceholderText("example@mail.com");
    aemail->setGeometry(150, 181, 250, 25);

    QLineEdit* acompany = new QLineEdit(alayout);
    acompany->setPlaceholderText("company name");
    acompany->setGeometry(55, 261, 200, 25);

    QLineEdit* aposition = new QLineEdit(alayout);
    aposition->setPlaceholderText("boss");
    aposition->setGeometry(295, 261, 200, 25);

    waddbg->hide();
}
void QWMain::ShowMain()
{
    if (!wmain->isVisible())
    {
		wfavourite->hide();
        waddbg->hide();
        wsettings->hide();
		wmain->show();
    }
}
void QWMain::ShowFavourite()
{
    if (!wfavourite->isVisible())
    {
		wmain->hide();
        waddbg->hide();
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
        waddbg->hide();
		wsettings->show();
    }
}
void QWMain::ShowAdd()
{
    if (!waddbg->isVisible())
    {
        wmain->hide();
        wfavourite->hide();
        wsettings->hide();
        waddbg->show();
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
    if (!wcontactbg)
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
            "}"
            "QPushButton {"
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
        connect(cedit, SIGNAL(clicked()), this, SLOT(ShowEdit()));

        QPushButton* cdelete = new QPushButton(cnavbar);
        cdelete->setGeometry(500, 5, 40, 40);
        cdelete->setIcon(QIcon(":/images/images/trash_icon.svg"));
        connect(cdelete, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));// test

        QFrame* clayout = new QFrame(wcontact);
        clayout->setGeometry(0, 50, 550, 350);
        clayout->setStyleSheet(
            "QFrame {"
            "background-color: #23272F;"
            "}"
            "QLabel {"
            "   color: #9FAABF;"
            "   font-family: Poppins;"
            "   font-size: 10pt;"
            "   text-align: center;"
            "   qproperty-alignment: AlignCenter;"
            "}"
            "QPushButton {"
            "   font-family: Poppins;"
            "   font-size: 10pt;"
            "   background-color: #333742;"
            "   border-radius: 12px;"
            "}"
        );
        QLabel* cfirstnamelabel = new QLabel(clayout);
        cfirstnamelabel->setText("Firstname");
        cfirstnamelabel->setGeometry(20, 15, 150, 20);

        QLabel* clastnamelabel = new QLabel(clayout);
        clastnamelabel->setText("Lastname");
        clastnamelabel->setGeometry(200, 15, 150, 20);

        QLabel* cnicknamelabel = new QLabel(clayout);
        cnicknamelabel->setText("Nickname");
        cnicknamelabel->setGeometry(380, 15, 150, 20);

        QLabel* cidlabel = new QLabel(clayout);
        cidlabel->setText("ID");
        cidlabel->setGeometry(30, 95, 40, 20);

        QLabel* cnumberlabel = new QLabel(clayout);
        cnumberlabel->setText("Phone Number");
        cnumberlabel->setGeometry(130, 95, 150, 20);

        QLabel* chomenumberlabel = new QLabel(clayout);
        chomenumberlabel->setText("Home Number");
        chomenumberlabel->setGeometry(340, 95, 150, 20);

        QLabel* cemaillabel = new QLabel(clayout);
        cemaillabel->setText("Email");
        cemaillabel->setGeometry(225, 175, 100, 20);

        QLabel* ccompanylabel = new QLabel(clayout);
        ccompanylabel->setText("Company");
        ccompanylabel->setGeometry(80, 255, 150, 20);

        QLabel* cpositionlabel = new QLabel(clayout);
        cpositionlabel->setText("Position");
        cpositionlabel->setGeometry(320, 255, 150, 20);

        // data
        QPushButton* cfirstname = new QPushButton(clayout);
        cfirstname->setText("Imie");
        cfirstname->setGeometry(20, 36, 150, 25);
        
        QPushButton* clastname = new QPushButton(clayout);
        clastname->setText("Nazwisko");
        clastname->setGeometry(200, 36, 150, 25);

        QPushButton* cnickname = new QPushButton(clayout);
        cnickname->setText("Pseudonim");
        cnickname->setGeometry(380, 36, 150, 25);

        QPushButton* cid = new QPushButton(clayout);
        cid->setText("id");
        cid->setGeometry(30, 116, 40, 25);

        QPushButton* cnumber = new QPushButton(clayout);
        cnumber->setText("numer");
        cnumber->setGeometry(130, 116, 150, 25);

        QPushButton* chomenumber = new QPushButton(clayout);
        chomenumber->setText("homenumber");
        chomenumber->setGeometry(340, 116, 150, 25);

        QPushButton* cemail = new QPushButton(clayout);
        cemail->setText("email");
        cemail->setGeometry(150, 196, 250, 25);

        QPushButton* ccompany = new QPushButton(clayout);
        ccompany->setText("company");
        ccompany->setGeometry(55, 276, 200, 25);

        QPushButton* cposition = new QPushButton(clayout);
        cposition->setText("position");
        cposition->setGeometry(295, 276, 200, 25);

        wcontactbg->show();
    }   
    //QMessageBox::warning(this, "Warning", "Coś nie działa");

}
void QWMain::ShowEdit()
{
    if (wcontactbg->isVisible())
    {
        wcontactbg->hide();
    }
    if (!weditbg)
    {
        weditbg = new QWidget(this);
        weditbg->setGeometry(0, 0, 600, 450);
        weditbg->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #1C1F26, stop: 1 #1E1E1E);");
        QWidget* wedit = new QWidget(weditbg);
        wedit->setGeometry(25, 25, 550, 400);
        wedit->setStyleSheet(
            "QWidget {"
            "background-color: #23272F;"
            "border-radius: 20px;"
            "}"
            "QPushButton:hover {"
            "   background-color: #2B303B;"
            "}"
        );
        QFrame* enavbar = new QFrame(wedit);
        enavbar->setFixedSize(550, 50);

        QPushButton* eback = new QPushButton(enavbar);
        eback->setGeometry(10, 5, 40, 40);
        eback->setIcon(QIcon(":/images/images/back_icon.svg"));
        eback->setIconSize(QSize(20, 20));
        connect(eback, SIGNAL(clicked()), this, SLOT(BackContact()));

        QPushButton* esave = new QPushButton(enavbar);
        esave->setGeometry(500, 5, 40, 40);
        esave->setIcon(QIcon(":/images/images/save_icon.svg"));
        esave->setIconSize(QSize(20, 20));

        QFrame* elayout = new QFrame(wedit);
        elayout->setGeometry(0, 50, 550, 350);
        elayout->setStyleSheet(
            "QFrame {"
            "   background-color: #23272F;"
            "   font-family: Poppins;"
            "   font-size: 10pt;"
            "}"
            "QLabel {"
            "   color: #9FAABF;"
            "   text-align: center;"
            "   qproperty-alignment: AlignCenter;"
            "}"
            "QPushButton {"
            "   font-family: Poppins;"
            "   font-size: 10pt;"
            "   background-color: #333742;"
            "   border-radius: 12px;"
            "}"
            "QLineEdit {"
            "   font-family: Poppins;"
            "   font-size: 10pt;"
            "   text-align: center;"
            "   qproperty-alignment: AlignCenter;"
            "   background-color: #333742;"
            "   border-radius: 12px;"
            "}"
        );
        QLabel* efirstnamelabel = new QLabel(elayout);
        efirstnamelabel->setText("Firstname");
        efirstnamelabel->setGeometry(20, 15, 150, 20);
           
        QLabel* elastnamelabel = new QLabel(elayout);
        elastnamelabel->setText("Lastname");
        elastnamelabel->setGeometry(200, 15, 150, 20);

        QLabel* enicknamelabel = new QLabel(elayout);
        enicknamelabel->setText("Nickname");
        enicknamelabel->setGeometry(380, 15, 150, 20);

        QLabel* eidlabel = new QLabel(elayout);
        eidlabel->setText("ID");
        eidlabel->setGeometry(30, 95, 40, 20);

        QLabel* enumberlabel = new QLabel(elayout);
        enumberlabel->setText("Phone Number");
        enumberlabel->setGeometry(130, 95, 150, 20);

        QLabel* ehomenumberlabel = new QLabel(elayout);
        ehomenumberlabel->setText("Home Number");
        ehomenumberlabel->setGeometry(340, 95, 150, 20);

        QLabel* eemaillabel = new QLabel(elayout);
        eemaillabel->setText("Email");
        eemaillabel->setGeometry(225, 175, 100, 20);

        QLabel* ecompanylabel = new QLabel(elayout);
        ecompanylabel->setText("Company");
        ecompanylabel->setGeometry(80, 255, 150, 20);

        QLabel* epositionlabel = new QLabel(elayout);
        epositionlabel->setText("Position");
        epositionlabel->setGeometry(320, 255, 150, 20);

         //data
        QLineEdit* efirstname = new QLineEdit(elayout);
        efirstname->setPlaceholderText("Jan");
        efirstname->setGeometry(20, 36, 150, 25);

        QLineEdit* elastname = new QLineEdit(elayout);
        elastname->setPlaceholderText("Kowalski");
        elastname->setGeometry(200, 36, 150, 25);

        QLineEdit* enickname = new QLineEdit(elayout);
        enickname->setPlaceholderText("Jasiek");
        enickname->setGeometry(380, 36, 150, 25);

        QPushButton* eid = new QPushButton(elayout);
        eid->setText("id");
        eid->setGeometry(30, 116, 40, 25);

        QLineEdit* enumber = new QLineEdit(elayout);
        enumber->setPlaceholderText("123456789");
        enumber->setGeometry(130, 116, 150, 25);

        QLineEdit* ehomenumber = new QLineEdit(elayout);
        ehomenumber->setPlaceholderText("987654321");
        ehomenumber->setGeometry(340, 116, 150, 25);

        QLineEdit* eemail = new QLineEdit(elayout);
        eemail->setPlaceholderText("example@mail.com");
        eemail->setGeometry(150, 196, 250, 25);

        QLineEdit* ecompany = new QLineEdit(elayout);
        ecompany->setPlaceholderText("company name");
        ecompany->setGeometry(55, 276, 200, 25);

        QLineEdit* eposition = new QLineEdit(elayout);
        eposition->setPlaceholderText("position");
        eposition->setGeometry(295, 276, 200, 25);
        
        weditbg->show();
    }

}
void QWMain::BackMain()
{
    if (wcontactbg->isVisible())
    {
        delete wcontactbg;
        wcontactbg = nullptr;
        navbar->show();
        wmain->show();
    }
}

void QWMain::BackContact()
{
    if (weditbg->isVisible())
    {
        delete weditbg;
        weditbg = nullptr;
        wcontactbg->show();
    }
}
//test
void QWMain::on_pushButton_clicked()
{
    try {
        pqxx::connection pgConnection("host=localhost dbname=postgres user=postgres password=postgres \
             hostaddr=127.0.0.1 port=5432");
        if (pgConnection.is_open()) {
            //std::cout << "Connection success" << std::endl;
            //label->setText("Connection success");
            QMessageBox::warning(this, "Warning", "Coś działa");
        }
        else {
            //std::cout << "Connection failed" << std::endl;
            //label->setText("Connection failed");
            QMessageBox::warning(this, "Warning", "Coś nie działa");
        }
    }
    catch (const std::exception& ex) {
        //std::cout << "DB failed: " << ex.what() << std::endl;
        //label->setText("DB failed: " + QString::fromStdString(ex.what()));
        QMessageBox::warning(this, "Warning", "Coś nie działa" + QString::fromStdString(ex.what()));
    }
}
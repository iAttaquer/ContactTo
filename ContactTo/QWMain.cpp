#include "QWMain.h"
#include <QSize>
#include <QtWidgets/QMessageBox>
#include <iostream>
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
    createlist();

    // Favourite Widget
    wfavourite = new QWidget(this);
    wfavourite->setGeometry(QRect(0, 50, 600, 400));
    wfavourite->setStyleSheet("background-color: rgb(0, 0, 255)");
    wfavourite->hide();

    // Add Widget
    createwadd();

	// Settings Widget
    createsettings();
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
    afirstname->setMaxLength(20);
    afirstname->setGeometry(20, 21, 150, 25);

    QLineEdit* alastname = new QLineEdit(alayout);
    alastname->setPlaceholderText("Kowalski");
    alastname->setMaxLength(30);
    alastname->setGeometry(200, 21, 150, 25);

    QLineEdit* anickname = new QLineEdit(alayout);
    anickname->setPlaceholderText("Jasiek");
    anickname->setMaxLength(20);
    anickname->setGeometry(380, 21, 150, 25);

    QLineEdit* anumber = new QLineEdit(alayout);
    anumber->setPlaceholderText("123456789");
    anumber->setMaxLength(15);
    anumber->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]*")));
    anumber->setGeometry(95, 101, 150, 25);

    QLineEdit* ahomenumber = new QLineEdit(alayout);
    ahomenumber->setPlaceholderText("987654321");
    ahomenumber->setMaxLength(15);
    ahomenumber->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]*")));
    ahomenumber->setGeometry(305, 101, 150, 25);

    QLineEdit* aemail = new QLineEdit(alayout);
    aemail->setPlaceholderText("example@mail.com");
    aemail->setMaxLength(30);
    aemail->setGeometry(150, 181, 250, 25);

    QLineEdit* acompany = new QLineEdit(alayout);
    acompany->setPlaceholderText("company name");
    acompany->setMaxLength(30);
    acompany->setGeometry(55, 261, 200, 25);

    QLineEdit* aposition = new QLineEdit(alayout);
    aposition->setPlaceholderText("boss");
    aposition->setMaxLength(20);
    aposition->setGeometry(295, 261, 200, 25);

    QPushButton* asave = new QPushButton(anavbar);
    asave->setGeometry(500, 5, 40, 40);
    asave->setIcon(QIcon(":/images/images/save_icon.svg"));
    asave->setIconSize(QSize(20, 20));
    connect(asave, &QPushButton::clicked, this, [=]() {
        FullContact contact(
            afirstname->text().toStdString(),
            alastname->text().toStdString(),
            anumber->text().toStdString(),
            ahomenumber->text().toStdString(),
            acompany->text().toStdString(),
            aposition->text().toStdString(),
            aemail->text().toStdString(),
            anickname->text().toStdString()
        );
        AddContact(contact);
    });
    waddbg->hide();
}
void QWMain::createlist()
{
    if (wmainscroll)
        delete wmainscroll;
    wmainscroll = new QScrollArea(wmain);
    wmainscroll->setGeometry(QRect(0, 20, 600, 380));
    wmainscroll->setWidgetResizable(true);

    QWidget* scontainer = new QWidget;
    scontainer->setGeometry(QRect(0, 0, 600, 380));
    scontainer->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #1C1F26, stop: 1 #1E1E1E);");
    QVBoxLayout* wmainlayout = new QVBoxLayout(scontainer);
    wmainlayout->setContentsMargins(15, 10, 15, 10);
    wmainlayout->setSpacing(10);
    wmainlayout->setAlignment(Qt::AlignTop);

    int n = pg.Count();
    std::vector<Contact> contacts = pg.loadShortInfo();

    for (int i = 0; i < n; i++)
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
        int id = contacts[i].id;
        connect(contactframe, &QPushButton::clicked, this, [=]() {ShowContact(id); });
        wmainlayout->addWidget(contactframe);
        QLabel* cid = new QLabel(contactframe);
        cid->setText(QString::number(contacts[i].id));
        cid->setGeometry(25, 15, 40, 20);
        QLabel* cfirstname = new QLabel(contactframe);
        cfirstname->setText(QString::fromStdString(contacts[i].firstname));
        cfirstname->setGeometry(85, 15, 140, 20);
        QLabel* clastname = new QLabel(contactframe);
        clastname->setText(QString::fromStdString(contacts[i].lastname));
        clastname->setGeometry(240, 15, 140, 20);
        QLabel* cnumber = new QLabel(contactframe);
        cnumber->setText(QString::fromStdString(contacts[i].number));
        cnumber->setGeometry(400, 15, 120, 20);
    }
    wmainscroll->setWidget(scontainer);
    wmainscroll->show();
}
void QWMain::createsettings()
{
    wsettingsbg = new QWidget(this);
    wsettingsbg->setGeometry(QRect(0, 50, 600, 400));
    wsettingsbg->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #1C1F26, stop: 1 #1E1E1E);");
    QWidget* wsettings = new QWidget(wsettingsbg);
    wsettings->setGeometry(25, 15, 550, 360);
    wsettings->setStyleSheet(
        "QWidget {"
        "background-color: #23272F;"
        "border-radius: 20px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #2B303B;"
        "}"
    );
    QFrame* snavbar = new QFrame(wsettings);
    snavbar->setFixedSize(550, 50);

    QFrame* slayout = new QFrame(wsettings);
    slayout->setGeometry(0, 50, 550, 300);
    slayout->setStyleSheet(
        "QFrame {"
        "   background-color: #23272F;"
        "   font-family: Poppins;"
        "   font-size: 10pt;"
        "}"
        "QLabel {"
        "   color: #9FAABF;"
        "   text-align: center;"
        "   qproperty-alignment: 'AlignVCenter | AlignRight';"
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
    QLabel* shostlabel = new QLabel(slayout);
    shostlabel->setText("Host: ");
    shostlabel->setGeometry(60, 10, 150, 25);
    
    QLabel* sdbnamelabel = new QLabel(slayout);
    sdbnamelabel->setText("Database name: ");
    sdbnamelabel->setGeometry(60, 60, 150, 25);

    QLabel* suserlabel = new QLabel(slayout);
    suserlabel->setText("User: ");
    suserlabel->setGeometry(60, 110, 150, 25);

    QLabel* spasswordlabel = new QLabel(slayout);
    spasswordlabel->setText("Password: ");
    spasswordlabel->setGeometry(60, 160, 150, 25);

    QLabel* shostaddrlabel = new QLabel(slayout);
    shostaddrlabel->setText("Host address: ");
    shostaddrlabel->setGeometry(60, 210, 150, 25);

    QLabel* sportlabel = new QLabel(slayout);
    sportlabel->setText("Port: ");
    sportlabel->setGeometry(60, 260, 150, 25);

    // data
    QLineEdit* shost = new QLineEdit(slayout);
    shost->setPlaceholderText("localhost");
    shost->setText("localhost");
    shost->setMaxLength(30);
    shost->setGeometry(210, 10, 200, 25);

    QLineEdit* sdbname = new QLineEdit(slayout);
    sdbname->setPlaceholderText("postgres");
    sdbname->setText("postgres");
    sdbname->setMaxLength(30);
    sdbname->setGeometry(210, 60, 200, 25);

    QLineEdit* suser = new QLineEdit(slayout);
    suser->setPlaceholderText("postgres");
    suser->setText("postgres");
    suser->setMaxLength(30);
    suser->setGeometry(210, 110, 200, 25);

    QLineEdit* spassword = new QLineEdit(slayout);
    spassword->setPlaceholderText("postgres");
    spassword->setText("postgres");
    spassword->setMaxLength(30);
    spassword->setGeometry(210, 160, 200, 25);

    QLineEdit* shostaddr = new QLineEdit(slayout);
    shostaddr->setPlaceholderText("127.0.0.1");
    shostaddr->setText("127.0.0.1");
    shostaddr->setMaxLength(30);
    shostaddr->setGeometry(210, 210, 200, 25);

    QLineEdit* sport = new QLineEdit(slayout);
    sport->setPlaceholderText("5432");
    sport->setText("5432");
    sport->setMaxLength(30);
    sport->setGeometry(210, 260, 200, 25);

    QPushButton* ssave = new QPushButton(snavbar);
    ssave->setGeometry(500, 5, 40, 40);
    ssave->setIcon(QIcon(":/images/images/save_icon.svg"));
    ssave->setIconSize(QSize(20, 20));
    connect(ssave, &QPushButton::clicked, this, [=]() {
        pg.setSettings(
            shost->text().toStdString(),
            sdbname->text().toStdString(),
            suser->text().toStdString(),
            spassword->text().toStdString(),
            shostaddr->text().toStdString(),
            sport->text().toStdString()
        );
        QMessageBox::information(this, "Success!", "Settings changed!");
        });
    
    wsettingsbg->hide();
}
void QWMain::ShowMain()
{
    if (!wmain->isVisible())
    {
		wfavourite->hide();
        waddbg->hide();
        wsettingsbg->hide();
		wmain->show();
        createlist();
    }
}
void QWMain::ShowFavourite()
{
    if (!wfavourite->isVisible())
    {
		wmain->hide();
        waddbg->hide();
		wsettingsbg->hide();
		wfavourite->show();
    }
}
void QWMain::ShowSettings()
{
    if (!wsettingsbg->isVisible())
    {
        wmain->hide();
		wfavourite->hide();
        waddbg->hide();
		wsettingsbg->show();
    }
}
void QWMain::ShowAdd()
{
    if (!waddbg->isVisible())
    {
        wmain->hide();
        wfavourite->hide();
        wsettingsbg->hide();
        waddbg->show();
    }
}
void QWMain::ShowContact(int id)
{
    FullContact contact = pg.loadAllInfo(id);
    if (contact.firstname.empty() && contact.number.empty()) return;
    
    if (wmain->isVisible())
    {
        wmain->hide();
    }
    if (navbar->isVisible())
    {
        navbar->hide();
    }
    if (wcontactbg)
        delete wcontactbg;
   
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
    cfirstname->setText(QString::fromStdString(contact.firstname));
    cfirstname->setGeometry(20, 36, 150, 25);
        
    QPushButton* clastname = new QPushButton(clayout);
    clastname->setText(QString::fromStdString(contact.lastname));
    clastname->setGeometry(200, 36, 150, 25);

    QPushButton* cnickname = new QPushButton(clayout);
    cnickname->setText(QString::fromStdString(contact.nickname));
    cnickname->setGeometry(380, 36, 150, 25);

    QPushButton* cid = new QPushButton(clayout);
    cid->setText(QString::number(contact.id));
    cid->setGeometry(30, 116, 40, 25);

    QPushButton* cnumber = new QPushButton(clayout);
    cnumber->setText(QString::fromStdString(contact.number));
    cnumber->setGeometry(130, 116, 150, 25);

    QPushButton* chomenumber = new QPushButton(clayout);
    chomenumber->setText(QString::fromStdString(contact.homenumber));
    chomenumber->setGeometry(340, 116, 150, 25);

    QPushButton* cemail = new QPushButton(clayout);
    cemail->setText(QString::fromStdString(contact.email));
    cemail->setGeometry(150, 196, 250, 25);

    QPushButton* ccompany = new QPushButton(clayout);
    ccompany->setText(QString::fromStdString(contact.company));
    ccompany->setGeometry(55, 276, 200, 25);

    QPushButton* cposition = new QPushButton(clayout);
    cposition->setText(QString::fromStdString(contact.position));
    cposition->setGeometry(295, 276, 200, 25);

    QPushButton* cedit = new QPushButton(cnavbar);
    cedit->setGeometry(450, 5, 40, 40);
    cedit->setIcon(QIcon(":/images/images/edit_icon.svg"));
    cedit->setIconSize(QSize(18, 18));
    connect(cedit, &QPushButton::clicked, this, [=]() {ShowEdit(contact); });

    QPushButton* cdelete = new QPushButton(cnavbar);
    cdelete->setGeometry(500, 5, 40, 40);
    cdelete->setIcon(QIcon(":/images/images/trash_icon.svg"));
    connect(cdelete, &QPushButton::clicked, this, [=]() {
        DeleteContact(contact.id);
        });

    wcontactbg->show();
    
}
void QWMain::ShowEdit(FullContact c)
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
        efirstname->setText(QString::fromStdString(c.firstname));
        efirstname->setPlaceholderText("Jan");
        efirstname->setMaxLength(20);
        efirstname->setGeometry(20, 36, 150, 25);

        QLineEdit* elastname = new QLineEdit(elayout);
        elastname->setText(QString::fromStdString(c.lastname));
        elastname->setPlaceholderText("Kowalski");
        elastname->setMaxLength(30);
        elastname->setGeometry(200, 36, 150, 25);

        QLineEdit* enickname = new QLineEdit(elayout);
        enickname->setText(QString::fromStdString(c.nickname));
        enickname->setPlaceholderText("Jasiek");
        enickname->setMaxLength(20);
        enickname->setGeometry(380, 36, 150, 25);

        QPushButton* eid = new QPushButton(elayout);
        eid->setText(QString::number(c.id));
        eid->setGeometry(30, 116, 40, 25);

        QLineEdit* enumber = new QLineEdit(elayout);
        enumber->setText(QString::fromStdString(c.number));
        enumber->setPlaceholderText("123456789");
        enumber->setMaxLength(15);
        enumber->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]*")));
        enumber->setGeometry(130, 116, 150, 25);

        QLineEdit* ehomenumber = new QLineEdit(elayout);
        ehomenumber->setText(QString::fromStdString(c.homenumber));
        ehomenumber->setPlaceholderText("987654321");
        ehomenumber->setMaxLength(15);
        ehomenumber->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]*")));
        ehomenumber->setGeometry(340, 116, 150, 25);

        QLineEdit* eemail = new QLineEdit(elayout);
        eemail->setText(QString::fromStdString(c.email));
        eemail->setPlaceholderText("example@mail.com");
        eemail->setMaxLength(30);
        eemail->setGeometry(150, 196, 250, 25);

        QLineEdit* ecompany = new QLineEdit(elayout);
        ecompany->setText(QString::fromStdString(c.company));
        ecompany->setPlaceholderText("company name");
        ecompany->setMaxLength(30);
        ecompany->setGeometry(55, 276, 200, 25);

        QLineEdit* eposition = new QLineEdit(elayout);
        eposition->setText(QString::fromStdString(c.position));
        eposition->setPlaceholderText("position");
        eposition->setMaxLength(20);
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
        createlist();
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
void QWMain::AddContact(FullContact c)
{
    if (c.firstname.size() == 0 && c.number.size() == 0)
    {
        QMessageBox::warning(this, "Error!", "Concact needs firstname and phone number!");
    }
    else if (pg.Is(c))
    {
        QMessageBox::warning(this, "Error!", "Contact already exist!");
    }
    else if (pg.Add(c))
    {
        QMessageBox::information(this, "Success!", "Contact Added!");
    }
    
}
void QWMain::DeleteContact(int id)
{
    if (pg.Delete(id))
    {
        QMessageBox::information(this, "Success!", "Contact Deleted!");
        BackMain();
    }
    else {
        QMessageBox::warning(this, "Error!", "Contact has not been deleted!");
    }
}
//test
void QWMain::on_pushButton_clicked()
{
    QMessageBox::warning(this, "Warning", QString::number(pg.Delete(12)));
    pg.loadShortInfo();
}
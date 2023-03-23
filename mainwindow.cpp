#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QWidget>
#include <QGridLayout>
#include <clickableimage.h>
#include <QMouseEvent>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto* widget = new QWidget();
    auto* layout =new QGridLayout();
    setCentralWidget(widget);
    widget->setLayout(layout);





    QString butName = *new QString("cookieClick");
   /* QIcon icon = *new QIcon(iconPix);
    cookieButton = new QPushButton(icon,butName,parent);*/
    //  cookieButton = new QPushButton("toto test",parent);
   //   layout->addWidget(cookieButton);

   //Image clickable du cookie
   QPixmap iconPix("/home/redha/Bureau/but/s4/c++/qt/CookieClicker/cookieImg.png");
   iconPix.scaled(50,50);
   ClickableImage* cookieBut = new ClickableImage(butName,widget);
   cookieBut->setPixmap(iconPix);
   cookieBut->resize(1000,1000);

   //Gestion du click sur le cookie
   connect(cookieBut,&ClickableImage::clicked,this,&MainWindow::cookieClicked);

   //Affichage du nombre de cookie
   cookieNumber = new QLabel(widget);
   cookieNumber->setText(QString::number(cookie));


   //Gestion des cookies passif (cookiePassif invoqué toutes les secondes)
   QTimer *timer = new QTimer(this);
   connect(timer, &QTimer::timeout, this,&MainWindow::cookiePassif );
   timer->start(1000);









}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cookieClicked(){
    cookie+=1;
    cookieNumber->setText(QString::number(cookie));
}

void MainWindow::cookiePassif(){
    cookie+=cookiePass;
    cookieNumber->setText(QString::number(cookie));
}


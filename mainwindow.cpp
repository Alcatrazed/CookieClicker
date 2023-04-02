#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QWidget>
#include <QGridLayout>
#include <clickableimage.h>
#include <QMouseEvent>
#include <QTimer>
#include <QFont>
#include <shop.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto* widget = new QWidget();
    auto* layout =new QHBoxLayout();
    setCentralWidget(widget);
    widget->setLayout(layout);





    QString butName = *new QString("cookieClick");

    //PARTIE GAUCHE-------------------------------------------------------------------------------------


   //Affichage du nombre de cookie
   cookieNumber = new QLabel();
   cookieNumber->setText(QString::number(cookie));
   cookieNumber->setAlignment(Qt::AlignCenter);

   //Affichage des cookiePass
   cookieStats = new QLabel();
   cookieStats->setText("par seconde: "+QString::number(cookiePass));
   cookieStats->setAlignment(Qt::AlignCenter);




   QFont font = cookieNumber->font();
   font.setBold(true);
   font.setPointSize(40);
   cookieNumber->setFont(font);

   //Image clickable du cookie
   QPixmap iconPix("/home/redha/Bureau/but/s4/c++/qt/CookieClicker/cookieImg.png");
   iconPix.scaled(50,50);
   ClickableImage* cookieBut = new ClickableImage(butName);
   cookieBut->setPixmap(iconPix);
   cookieBut->resize(750,750);
//   cookieBut->move(25,100);


   auto* layoutCookie = new QVBoxLayout();
   layoutCookie->addWidget(cookieNumber);
   layoutCookie->addWidget(cookieStats);
   layoutCookie->addWidget(cookieBut);
   layoutCookie->addSpacerItem(new QSpacerItem(0,0, QSizePolicy::Fixed,QSizePolicy::Expanding));



   //Gestion du click sur le cookie
   connect(cookieBut,&ClickableImage::clicked,this,&MainWindow::CookieClicked);



   layout->addLayout(layoutCookie);





   //Gestion des cookies passif (cookiePassif invoqué toutes les secondes)
   QTimer *timer = new QTimer(this);
   connect(timer, &QTimer::timeout, this,&MainWindow::CookiePassif );
   timer->start(1000);




   //Shop
   const QSize btnSize = QSize(50, 30);
   auto*  layoutShop =new QVBoxLayout();
   Shop* shop = new Shop("Cook",25,0.2,btnSize,this);
   connect(shop, &Shop::Achat, this,&MainWindow::Buy );


   Shop* shop2 = new Shop("Four",50,0.8,btnSize,this);
   connect(shop2, &Shop::Achat, this,&MainWindow::Buy );


   layoutShop->addWidget(shop);
   layoutShop->addWidget(shop2);
   layoutShop->addStretch();



   layout->addLayout(layoutShop);












}

bool MainWindow::Buy(double shopPrice,double boost){

    if(shopPrice>cookie){
        return false;
    }
    cookie-=shopPrice;
    cookieNumber->setText(QString::number(cookie));
    cookiePass+=boost;
    cookieStats->setText("par seconde: "+QString::number(cookiePass));
    return true;
}





void MainWindow::CookieClicked(){
    cookie+=1;

    cookieNumber->setText(QString::number(cookie));
}

void MainWindow::CookiePassif(){
    cookie+=cookiePass;
    cookieNumber->setText(QString::number(cookie));
}

int MainWindow::CalculeCookie(){
    //en javascript
   /* const lookup = [
        { value: 1, symbol: "" },
        { value: 1e3, symbol: "k" },
        { value: 1e6, symbol: "M" },
        { value: 1e9, symbol: "G" },
        { value: 1e12, symbol: "T" },
        { value: 1e15, symbol: "P" },
        { value: 1e18, symbol: "E" }
      ];
      const rx = /\.0+$|(\.[0-9]*[1-9])0+$/;
      var item = lookup.slice().reverse().find(function(item) {
        return num >= item.value;
      });
      return item ? (num / item.value).toFixed(digits).replace(rx, "$1") + item.symbol : "0";
    */

}

MainWindow::~MainWindow()
{
    delete ui;
}


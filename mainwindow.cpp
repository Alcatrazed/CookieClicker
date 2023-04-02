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
   const QSize btnSize = QSize(60, 50);
   auto*  layoutShop =new QVBoxLayout();
   Shop* shop1 = new Shop("Spatulles",25,0.2,btnSize,this);
   connect(shop1, &Shop::Achat, this,&MainWindow::Buy );

   Shop* shop2 = new Shop("Grille Pain",50,0.6,btnSize,this);
   connect(shop2, &Shop::Achat, this,&MainWindow::Buy );

   Shop* shop3 = new Shop("Plaque de cuisson",80,1,btnSize,this);
   connect(shop3, &Shop::Achat, this,&MainWindow::Buy );

   Shop* shop4 = new Shop("Four",110,1.5,btnSize,this);
   connect(shop4, &Shop::Achat, this,&MainWindow::Buy );

   Shop* shop5 = new Shop("Tapis roulant",150,2,btnSize,this);
   connect(shop5, &Shop::Achat, this,&MainWindow::Buy );

   Shop* shop6 = new Shop("Usine",200,4,btnSize,this);
   connect(shop6, &Shop::Achat, this,&MainWindow::Buy );

   Shop* shop7 = new Shop("Multi national",300,6,btnSize,this);
   connect(shop7, &Shop::Achat, this,&MainWindow::Buy );

   Shop* shop8 = new Shop("Monopole",350,8,btnSize,this);
   connect(shop8, &Shop::Achat, this,&MainWindow::Buy );

   Shop* shop9 = new Shop("MEGA-FOUR",400,10,btnSize,this);
   connect(shop9, &Shop::Achat, this,&MainWindow::Buy );


   layoutShop->addWidget(shop1);
   layoutShop->addWidget(shop2);
   layoutShop->addWidget(shop3);
   layoutShop->addWidget(shop4);
   layoutShop->addWidget(shop5);
   layoutShop->addWidget(shop6);
   layoutShop->addWidget(shop7);
   layoutShop->addWidget(shop8);
   layoutShop->addWidget(shop9);
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


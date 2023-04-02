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
    auto* layoutCookie = new QVBoxLayout();

   //Affichage du nombre de cookie
   cookieNumber = new QLabel();
   cookieNumber->setText(QString::number(cookie));
   cookieNumber->setAlignment(Qt::AlignCenter);


   layoutCookie->addWidget(cookieNumber);

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
   layoutCookie->addWidget(cookieBut);
   layoutCookie->addSpacerItem(new QSpacerItem(0,0, QSizePolicy::Fixed,QSizePolicy::Expanding));



   //Gestion du click sur le cookie
   connect(cookieBut,&ClickableImage::clicked,this,&MainWindow::cookieClicked);



   layout->addLayout(layoutCookie);





   //Gestion des cookies passif (cookiePassif invoqué toutes les secondes)
   QTimer *timer = new QTimer(this);
   connect(timer, &QTimer::timeout, this,&MainWindow::cookiePassif );
   timer->start(1000);




   //Shop
   const QSize btnSize = QSize(50, 30);
   auto*  layoutShop =new QVBoxLayout();
   Shop* shop = new Shop("Cook",25,btnSize,widget);


   Shop* shop2 = new Shop("Four",50,btnSize,widget);

   shop->show();
   layoutShop->addWidget(shop);
   layoutShop->addWidget(shop2);

   layoutShop->addStretch();
   layout->addLayout(layoutShop);












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

int MainWindow::calculeCookie(){
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


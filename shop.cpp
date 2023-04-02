#include "shop.h"
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QMessageBox>

Shop::Shop(QString shopName,double shopPrix,double boost,QSize shopBtnSize, QWidget *parent): QWidget(parent)
{

    shopPrice=shopPrix;
    this->boost=boost;


    //bout d'achat
    shopBtn = new QPushButton("Achat");
    shopBtn->setFixedSize(shopBtnSize);


    // label du nom
    auto* shopLabel = new QLabel();
    shopLabel->setText(shopName);


    //label du prix
    shopPriceLabel = new QLabel();
    shopPriceLabel->setText(QString::number(shopPrice)+" cookies");





    auto* layout =new QHBoxLayout(this);
    layout->addWidget(shopBtn);
    layout->addWidget(shopLabel);
    layout->addWidget(shopPriceLabel);
    layout->addStretch();

    connect(shopBtn,&QAbstractButton::clicked,this,&Shop::BtnClicked);
}

void Shop::BtnClicked(){
    if(emit Achat(shopPrice,boost)){
        shopPrice= shopPrice*1.2;
        shopPriceLabel->setText(QString::number(shopPrice)+" cookies");
    }
    QMessageBox alert;
    alert.setText("Pas assez de cookies !!");
    alert.exec();


}


Shop::~Shop()
{
    delete this;
}

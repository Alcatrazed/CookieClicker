#include "shop.h"
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

Shop::Shop(QString shopName,double shopPrix,QSize shopBtnSize, QWidget *parent): QWidget(parent)
{

    shopPrice=shopPrix;


    QPushButton *shopBtn = new QPushButton("Achat");
    shopBtn->setFixedSize(shopBtnSize);

    auto* shopLabel = new QLabel();
    shopLabel->setText(shopName);
//    shopLabel->setFixedSize(,8);


    shopPriceLabel = new QLabel();
    shopPriceLabel->setText(QString::number(shopPrice)+" cookies");
//    shopPriceLabel->setFixedSize(3,3);




    auto* layout =new QHBoxLayout(this);
    layout->addWidget(shopBtn);
    layout->addWidget(shopLabel);
    layout->addWidget(shopPriceLabel);
    layout->addStretch();

    connect(shopBtn,&QAbstractButton::clicked,this,&Shop::BtnClicked);
}

void Shop::BtnClicked(){
    shopPrice= shopPrice*1.2;
    shopPriceLabel->setText(QString::number(shopPrice)+" cookies");


}

Shop::~Shop()
{
    delete this;
}

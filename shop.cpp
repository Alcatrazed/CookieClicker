#include "shop.h"
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

Shop::Shop(QString shopName,double shopPrice,QSize shopBtnSize, QWidget *parent): QWidget(parent)
{

//    auto* layout =new QHBoxLayout;

    QPushButton *shop = new QPushButton("Achat");
    shop->setFixedSize(shopBtnSize);

    auto* shopLabel = new QLabel();
    shopLabel->setText(shopName+"  "+QString::number(shopPrice));

    shopLabel->resize(1000,250);


//    layout->addWidget(shop);
//    layout->addWidget(shopLabel);

}

Shop::~Shop()
{
    delete this;
}

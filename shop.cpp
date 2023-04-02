#include "shop.h"
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QMessageBox>

Shop::Shop(QString shopName,double shopPrix,double boost,QSize shopBtnSize, QWidget *parent): QWidget(parent)
{

    this->shopName=shopName;
    shopPrice=shopPrix;
    this->boost=boost;



    //bout d'achat
    shopBtn = new QPushButton("Achat");
    shopBtn->setFixedSize(shopBtnSize);

    auto* infoBtn= new QPushButton("Info");
    infoBtn->setFixedSize(shopBtnSize);

    // label du nom
    auto* shopLabel = new QLabel();
    shopLabel->setText(shopName);

    //label du prix
    shopPriceLabel = new QLabel();
    shopPriceLabel->setText("prix: "+QString::number(shopPrice)+" cookies");

    QFont font = shopLabel->font();
    font.setBold(true);
    font.setPointSize(24);
    shopLabel->setFont(font);
//    shopPriceLabel->setFont(font);





    auto* layout =new QHBoxLayout(this);
    layout->addWidget(shopBtn);
    layout->addWidget(shopLabel);
    layout->addWidget(shopPriceLabel);
    layout->addWidget(infoBtn);
    layout->addStretch();

    connect(shopBtn,&QAbstractButton::clicked,this,&Shop::BtnClicked);
    connect(infoBtn,&QAbstractButton::clicked,this,&Shop::Info);

}

void Shop::BtnClicked(){
    if(emit Achat(shopPrice,boost)){
        shopPrice= shopPrice*1.2;
        shopPriceLabel->setText("prix: "+QString::number(shopPrice)+" cookies");
        cpt+=1;
        return;
    }
    QMessageBox alert;
    alert.setText("Pas assez de cookies !!");
    alert.exec();
}

void Shop::Info(){
    QMessageBox alert;
    alert.setText("effet: +"+QString::number(boost)+" cookies par seconde<br/>"
                  +QString::number(cpt)+" "+shopName+" = "+QString::number(boost*cpt));
    alert.exec();
}


Shop::~Shop()
{
    delete this;
}

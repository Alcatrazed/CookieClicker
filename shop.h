#ifndef SHOP_H
#define SHOP_H

#include "qlabel.h"
#include <QObject>
#include <QWidget>

class Shop: public QWidget
{
     Q_OBJECT

public:
    Shop(QString shopName,double shopPrice,QSize shopBtnSize, QWidget *parent = 0);
    ~Shop();
    double shopPrice;
    QLabel* shopPriceLabel;

    void BtnClicked();
signals:
    void Achat();
};

#endif // SHOP_H

#ifndef SHOP_H
#define SHOP_H

#include <QObject>
#include <QWidget>

class Shop: public QWidget
{
     Q_OBJECT
public:
    Shop(QString shopName,double shopPrice,QSize shopBtnSize, QWidget *parent = 0);
    ~Shop();
};

#endif // SHOP_H

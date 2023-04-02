#ifndef SHOP_H
#define SHOP_H

#include "qlabel.h"
#include "qpushbutton.h"
#include <QObject>
#include <QWidget>

class Shop: public QWidget
{
     Q_OBJECT

public:
    Shop(QString shopName,double shopPrice,double boost,QSize shopBtnSize, QWidget *parent = 0);
    ~Shop();
    double shopPrice;
    double boost;
    int cpt=0;
    QString shopName;
    QLabel* shopPriceLabel;
    QPushButton* shopBtn;

    void BtnClicked();
    void Info();


signals:
    bool Achat(double shopPrice,double boost);

};

#endif // SHOP_H

#include "clickableimage.h"
#include <QLabel>

ClickableImage::ClickableImage(QString text, QWidget *parent): QLabel(text, parent)
{

/*
    QPixmap iconPix("/home/redha/Bureau/but/s4/c++/qt/CookieClicker/cookieImg.png");
    setPixmap(iconPix);*/

}

ClickableImage::~ClickableImage()
{
    delete this;
}

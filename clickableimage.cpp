#include "clickableimage.h"
#include <QLabel>

ClickableImage::ClickableImage(QString text, QWidget *parent): QLabel(text, parent)
{


}

ClickableImage::~ClickableImage()
{
    delete this;
}

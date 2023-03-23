#ifndef CLICKABLEIMAGE_H
#define CLICKABLEIMAGE_H

#include <QObject>
#include <QWidget>
#include <QLabel>

class ClickableImage: public QLabel
{
    Q_OBJECT
public:
   ClickableImage(QString text, QWidget *parent = 0);
   ~ClickableImage();
   void mousePressEvent(QMouseEvent *event) { emit clicked(); }

signals:
   void clicked();

};

#endif // CLICKABLEIMAGE_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QLabel *cookieNumber;
    QLabel *cookieStats;
    double cookie=0;
    double cookiePass=0;



    void CookieClicked();
    void CookiePassif();
    int CalculeCookie();
    bool Buy(double shopPrice,double boost);




private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

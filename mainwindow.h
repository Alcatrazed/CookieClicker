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
    double cookie=0;
    double cookiePass=0.5;



    void cookieClicked();
    void cookiePassif();
    int calculeCookie();



private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include <QDebug>
#include <QDesktopWidget>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QDesktopWidget* desktopWidget = qApp->desktop();
    QRect screenGeometry = desktopWidget->screenGeometry();
    int screenWidth = screenGeometry.width();
    int screenHeight = screenGeometry.height();
    //QPixmap yourPixmap("D:/image1");
    QPixmap yourPixmap(":/images/image1.jpg");
    QPixmap pixmapForSplash = yourPixmap.scaled(screenWidth, screenHeight);
   // QSplashScreen splash(pixmapForSplash);


    QSplashScreen *splash=new QSplashScreen();
    splash->setPixmap(pixmapForSplash);
    splash->show();
    MainWindow w;
    QDesktopWidget dw;
    QTimer::singleShot(4000,splash,SLOT(close()));
    QTimer::singleShot(4000,&w,SLOT(showFullScreen()));
    //w.show();
    qDebug()<<dw.width()<<","<<dw.size();
    //w.showFullScreen();

    return a.exec();
}

#include "mainwindowsingleton.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //set the app style sheet
    QFile file("../ForumClient/Devsion.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    qApp->setStyleSheet(styleSheet);
//    MainWindow w;
//    w.setWindowTitle("Forum POO");

//    w.setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint); //
//    w.showMaximized();
    MainWindowSingleton& w = MainWindowSingleton::getInstance();

    return a.exec();
}

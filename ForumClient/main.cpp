#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //set the app style sheet
    QFile file("C:/Users/andre/Desktop/Teorie/Anul 2 - Materiale/Qt Projects/ForumClient/Devsion.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    qApp->setStyleSheet(styleSheet);
    MainWindow w;
    w.setWindowTitle("Forum POO");

    w.show();
    return a.exec();
}

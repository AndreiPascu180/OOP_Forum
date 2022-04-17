#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include "client.h"
#include "others.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    Client *client = new Client("127.0.0.1",1234);
    Others *OthersTopicPage = new Others(this);


    ~MainWindow();

private slots:

    void LogOut();

    void on_LogInPage_LogIn_Button_clicked();

    void on_LogInPage_Cancel_Button_clicked();

    void on_Home_LogIn_Button_clicked();

    void on_Home_Guest_Button_clicked();

    void on_OtherTopics_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
};
#endif // MAINWINDOW_H

#ifndef OTHERS_H
#define OTHERS_H

#include <QWidget>
#include <QListWidget>
#include "client.h"
//#include "popupwindow.h"
namespace Ui {
class Others;
}

class Others : public QWidget
{
    Q_OBJECT

public:
    explicit Others(QWidget *parent = nullptr,Client* client = nullptr);
    QListWidget* getListWidget();
    Client* client_mostenit;
    void refresh_list();
    ~Others();

signals:
    void LogOut();
    void HomePage();

private slots:

    void on_LogOutButton_clicked();

    void on_HomePageButton_clicked();

    void on_NavigationButton_clicked();

    void on_AskQuestionButton_clicked();

    void on_Submit_clicked();

    void on_Cancel_clicked();

    void on_pushButton_clicked();

private:
    Ui::Others *ui;

};

#endif // OTHERS_H

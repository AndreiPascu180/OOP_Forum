#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->insertWidget(4,OthersTopicPage);
    ui->stackedWidget->setCurrentIndex(0);
    connect(OthersTopicPage,SIGNAL(LogOut()),this,SLOT(LogOut()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete client;
}

void MainWindow::LogOut()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_LogInPage_LogIn_Button_clicked()
{
    QString credentials= "1/"+ui->LineEdit_Username->text().toUtf8()+"/"+ui->LineEdit_Password->text().toUtf8();

    client->getSocket()->write(credentials.toUtf8());
}


void MainWindow::on_LogInPage_Cancel_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_Home_LogIn_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Home_Guest_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_OtherTopics_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
    //delete client;
}

void MainWindow::on_pushButton_2_clicked()
{
    client->getSocket()->write(ui->lineEdit_2->text().toUtf8());

}


void MainWindow::on_pushButton_clicked()
{
    this->close();
}


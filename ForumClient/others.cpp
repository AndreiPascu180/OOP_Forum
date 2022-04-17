#include "others.h"
#include "ui_others.h"

Others::Others(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Others)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

Others::~Others()
{
    delete ui;
}

void Others::on_pushButton_5_clicked()
{
    emit LogOut();
}


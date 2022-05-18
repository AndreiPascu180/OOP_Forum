#include "others.h"
#include "ui_others.h"

Others::Others(QWidget *parent,Client* client) :
    QWidget(parent),
    ui(new Ui::Others)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    client_mostenit = client;
}

QListWidget *Others::getListWidget()
{
    return ui->listWidget;
}

void Others::refresh_list()
{
    ui->listWidget->clear();

    QString message= "3|Other Topics";
    client_mostenit->getSocket()->write(message.toUtf8());
    client_mostenit->getSocket()->waitForBytesWritten();
    client_mostenit->getSocket()->waitForReadyRead();

    QStringList dataList = client_mostenit->getLastMsg();
    for(int i=2;i<dataList.value(1).toInt()*2+1;i+=2){
       ui->listWidget->addItem(dataList.value(i)+": "+dataList.value(i+1));
    }

    ui->stackedWidget->setCurrentIndex(0);
}

Others::~Others()
{
    delete ui;
}

void Others::on_LogOutButton_clicked()
{
    emit LogOut();
}


void Others::on_HomePageButton_clicked()
{
    emit HomePage();
}


void Others::on_NavigationButton_clicked()
{

}


void Others::on_AskQuestionButton_clicked()
{
//    PopupWindow dialog(nullptr,client_mostenit->getSocket(),client_mostenit->getUsername());
//    dialog.setModal(true);
//    dialog.exec();
    ui->stackedWidget->setCurrentIndex(1);
}

void Others::on_Submit_clicked()
{
    QString question_entered = "5|" + client_mostenit->getUsername()+"|Other Topics|" +ui->plainTextEdit->toPlainText();

    client_mostenit->getSocket()->write(question_entered.toUtf8());
    client_mostenit->getSocket()->waitForBytesWritten();
    client_mostenit->getSocket()->waitForReadyRead();

    //S-a inserat intrebarea

    refresh_list();
    //ne reintoarcem la contextul actual reincarcand informatia in lista de intrebari

}


void Others::on_Cancel_clicked()
{
    refresh_list();
}


void Others::on_pushButton_clicked()
{
    refresh_list();
}


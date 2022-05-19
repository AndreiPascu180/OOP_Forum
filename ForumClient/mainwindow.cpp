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
    connect(OthersTopicPage,SIGNAL(HomePage()),this,SLOT(HomePage()));
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

void MainWindow::HomePage()
{
    ui->stackedWidget->setCurrentIndex(3);  //pagina cu lista de topicuri
}

void MainWindow::MyProfile()
{
    ui->stackedWidget->setCurrentIndex(5); //pagina profilului
}

void MainWindow::on_LogInPage_LogIn_Button_clicked()
{
    QString tmp_pass = ui->LineEdit_Password->text();

    QString credentials= "1|"+ui->LineEdit_Username->text().toUtf8()+"|"+tmp_pass.toUtf8();

    client->getSocket()->write(credentials.toUtf8());
    client->getSocket()->waitForBytesWritten();
    client->getSocket()->waitForReadyRead();
    QString tmp_username = ui->LineEdit_Username->text();

    int lastRespCode = client->getLastMsg().value(0).toInt();
    qDebug() <<"\nS-a primit raspunsul la logare: " <<lastRespCode<<"\n";
    if (lastRespCode == 1){

        client->setUsername(tmp_username);
        ui->stackedWidget->setCurrentIndex(3);

    }
    else{
        QMessageBox::warning(this,"Login","Ati introdus credentiale gresite! Va rugam sa reincercati!");
    }
}


void MainWindow::on_LogInPage_Cancel_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_Home_LogIn_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Home_SignUp_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_Home_Guest_Button_clicked()
{
    client->setUsername("Guest");
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_OtherTopics_clicked()
{
    OthersTopicPage->getListWidget()->clear();

    QString message= "3|Other Topics";
    client->getSocket()->write(message.toUtf8());
    client->getSocket()->waitForBytesWritten();
    client->getSocket()->waitForReadyRead();

    QStringList dataList = client->getLastMsg();
    for(int i=2;i<dataList.value(1).toInt()*2+1;i+=2){
        OthersTopicPage->getListWidget()->addItem(dataList.value(i)+" |"+dataList.value(i+1));
    }

    ui->stackedWidget->setCurrentIndex(4);
    OthersTopicPage->getStackedWidget()->setCurrentIndex(0);
}


void MainWindow::on_LogOutButtonFromTopics_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_SignUpCancelButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_SignUpButton_clicked()
{
    QString tmp_username = ui->lineEdit_SignUp_username->text();
    QString tmp_pass = ui->lineEdit_SignUp_password->text();
    if(tmp_pass.contains(' ') || tmp_pass.contains('|')){
        QMessageBox::warning(this,"SignUp Password Error","Parola nu are voie sa contina spatii sau caracterul \"|\"");
    }
    QString credentials= "2|"+tmp_username.toUtf8()+"|"+tmp_pass.toUtf8()+"|"+ui->lineEdit_SignUp_email->text().toUtf8();
    client->getSocket()->write(credentials.toUtf8());
    client->getSocket()->waitForBytesWritten();
    client->getSocket()->waitForReadyRead();


    int lastRespCode = client->getLastMsg().value(0).toInt();
    qDebug() <<"\nS-a primit raspunsul la logare: " <<lastRespCode<<"\n";
    if (lastRespCode == 1){

        client->setUsername(tmp_username);
        ui->stackedWidget->setCurrentIndex(3);

    }
    else
        if(lastRespCode == 0)
            QMessageBox::warning(this,"Register","Username-ul ales deja exista! Va rugam sa alegeti altul!");
        else
            QMessageBox::warning(this,"ERROR","S-a produs o eroare la introducerea datelor!");

}


void MainWindow::on_MyProfileButtonFromTopics_clicked()
{

}


#include "database.h"
#include <QtCore>
#include<QCoreApplication>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

DataBase::DataBase()
{

}
void DataBase::ConnectDB()
{
      QString servername="localhost";
      QString dbname="ForumDatabase";
      QSqlDatabase db1 = QSqlDatabase::addDatabase("QODBC");
      db1.setConnectOptions();
      QString dsn=QString("DRIVER={SQL Server Native Client 11.0};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(servername,dbname);
      db1.setDatabaseName(dsn);
      if(db1.open())
      {
          qDebug()<<"Opened.\n";
          QSqlQuery qry;

          if(qry.exec("select * from [ForumDatabase].[dbo].Credentials"))
          {
                while(qry.next())
                {
                    qDebug()<<qry.value(1).toString();
                }
          }
          else
          {
              qDebug()<<"Error = "<<db.lastError().text();
          }


      }
      else
      {
          qDebug()<<"OPENED FAILED\n"<<db1.lastError().text();
          exit(0);
      }
      db1.close();
      this->db=db1;
}

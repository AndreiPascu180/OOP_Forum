#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
class DataBase
{
private:
    QSqlDatabase db;
public:
    DataBase();
    void ConnectDB();
    QSqlDatabase getDataBase(){return db;}
   // ~DataBase();
};

#endif // DATABASE_H

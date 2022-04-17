#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql/QSqlDatabase>
class DataBase
{
private:
    QSqlDatabase db;
public:
    DataBase();
    void ConnectDB();
};

#endif // DATABASE_H

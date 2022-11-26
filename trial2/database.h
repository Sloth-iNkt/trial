#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQueryModel>


class database
{
public:
    database();

private:
    QSqlDatabase m_db;
};

#endif // DATABASE_H

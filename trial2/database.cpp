#include "database.h"
#include <QDebug>
#include <QtSql>

//database::database()
//{
//    QSqlDatabase db;
//    db = QSqlDatabase::addDatabase("QSQLITE");
//    //    db.setDatabaseName("C:/Users/Hersey/school/pers/c++/trial/trial2/db.sqlite");
//    db.setDatabaseName("./sqlite.db");
//    if (!db.open()) {
//        qDebug() << "Problem!";
//    }

//    QSqlQuery qry(db);
//    qry.exec("PRAGMA foreign_keys = ON;");

    //    qry.exec("create table boxes "
    //             "(boxID integer primary key, "
    //             "boxName varchar(20), "
    //             "boxLocation varchar(30))");

//}

database::database(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(./sqlite.db);

    if (!m_db.open())
        qDebug() << "Error: connection with database fail";
    else
        qDebug() << "Database: connection ok";
}

//DbManager::~DbManager()
//{
//    if (m_db.isOpen())
//        m_db.close();
//}

//bool DbManager::isOpen() const
//{
//    return m_db.isOpen();
//}



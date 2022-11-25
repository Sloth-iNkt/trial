#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qDebug() << "start";

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("C:/Users/Hersey/school/pers/c++/trial/trial2/db.sqlite");
    db.setDatabaseName("./db.sqlite");
    if (!db.open()) {
        qDebug() << "Problem!";
    }

    QString query = "CREATE TABLE users ("
                    "ID integer primary key not null,"
                    "name VARCHAR(20) not null,"
                    "hashed_pass VARCHAR(20) not null);";
    QString query1 = "CREATE TABLE category ("
                    "ID integer PRIMARY KEY not null,"
                    "category VARCHAR(20) not null);";
    QString query2 = "CREATE TABLE questionsEasy ("
                     "ID integer primary key not null,"
                     "question VARCHAR(100) not null,"
                     "answer BOOLEAN not null,"
                     "owner_id integer not null,"
                     "FOREIGN KEY(owner_id) REFERENCES users(ID),"
                     "category_id integer not null,"
                     "FOREIGN KEY(category_id) REFERENCES category(ID));";
    QString query3 = "CREATE TABLE questionMedium ("
                     "ID integer primary not null,"
                     "question VARCHAR(100) not null,"
                     "option1 VARCHAR(100) not null,"
                     "option2 VARCHAR(100) not null,"
                     "option3 VARCHAR(100) not null,"
                     "option4 VARCHAR(100) not null,"
                     "answer VARCHAR(100) not null,"
                     "owner_id integer not null,"
                     "FOREIGN KEY(owner_id) REFERENCES users(ID),"
                     "category_id integer not null,"
                     "FOREIGN KEY(category_id) REFERENCES category(ID));";
    QString query4 = "CREATE TABLE questionHard ("
                     "ID integer primary key not null,"
                     "question VARCHAR(100) not null,"
                     "answer VARCHAR(100) not null,"
                     "owner_id integer not null,"
                     "FOREIGN KEY(owner_id) REFERENCES users(ID),"
                     "category_id integer not null,"
                     "FOREIGN KEY(category_id) REFERENCES category(ID));";
    QString query5 = "CREATE TABLE leaderboard ("
                     "ID integer primary key not null,"
                     "name VARCHAR(20) not null,"
                     "score integer not null);";

    QSqlQuery qry;
    if (!qry.exec(query)
            && !qry.exec(query1)
            && !qry.exec(query2)
            && !qry.exec(query3)
            && !qry.exec(query4)
            && !qry.exec(query5)) {
        qDebug() << "Table is not created";
    }

    qDebug() << "end";

    MainWindow w;
    w.show();
    return a.exec();
}

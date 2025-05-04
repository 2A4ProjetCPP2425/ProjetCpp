#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Football_project");
    db.setUserName("Hedi");
    db.setPassword("Hedi");

    if (db.open()) {
        test = true;
        qDebug() << "Connection successful";
    } else {
        qDebug() << "Error: " << db.lastError().text();
    }

    return test;
}

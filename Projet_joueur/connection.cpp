#include "connection.h"
#include <QDebug>
#include <QSqlError> // Added to define QSqlError

connection::connection() {}

bool connection::createconnection() {
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Football_project");
    db.setUserName("Hedi");
    db.setPassword("Hedi");
    qDebug() << "Attempting to connect to ODBC DSN: Football_project";
    if (db.open()) {
        qDebug() << "Database connected successfully";
        return true;
    } else {
        qDebug() << "Database connection failed:" << db.lastError().text();
        return false;
    }
}

void connection::closeconnection() {
    db.close();
}

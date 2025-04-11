#include "connection.h"

connection::connection() {}
bool connection::createconnection()
{
    db=QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("Football_project");
    db.setUserName("Hedi");
    db.setPassword("Hedi");
    if(db.open()) test=true;
    return test;
}
void connection::closeconnection(){db.close();}

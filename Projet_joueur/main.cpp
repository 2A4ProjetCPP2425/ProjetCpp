#include "mainwindow.h"
#include <QApplication>
#include "connection.h"
#include <QMessageBox>
#include "player.h"
#include "Joueur.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connection c;
    bool test=c.createconnection();
    MainWindow w;
    if(test)
    {
        w.show();

        QMessageBox::information(nullptr,QObject::tr("database is open"),
            QObject::tr("connection successful.\n"
                        "Click cancel to exit."),QMessageBox::Cancel);
    }
    else {
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
            QObject::tr("connection failed.\n"
                        "Click cancel to exit."),QMessageBox::Cancel);
    }

    return a.exec();
}

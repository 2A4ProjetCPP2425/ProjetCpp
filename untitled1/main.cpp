#include "stadewindow.h"
#include "connection.h"
#include <QMessageBox>
#include <QApplication>
#include <QFile>
#include <QRadioButton>
#include <QTextStream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Charger le fichier de style QSS à partir des ressources
    QFile file(":/styles/Perstfic.qss"); // Assurez-vous que Perstfic.qss est ajouté à resources.qrc
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream stream(&file);
        QString styleSheet = stream.readAll();
        a.setStyleSheet(styleSheet);
        file.close();
    } else {
        qDebug() << "Impossible d'ouvrir le fichier QSS.";
    }

    // Initialize database connection
    Connection c;
    if (!c.createconnect()) {
        QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                              QObject::tr("Failed to connect to database.\nClick Cancel to exit."),
                              QMessageBox::Cancel);
        return 1; // Early exit on database connection failure
    }

    // Show the main window
    StadeWindow w;
    w.show();
    QMessageBox::information(nullptr, QObject::tr("Database Open"),
                             QObject::tr("Connection successful.\nClick Cancel to exit."),
                             QMessageBox::Cancel);

    return a.exec(); // Start the event loop
}

#include "G_Tours.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connection conn; // Class name corrected to lowercase
    bool test = conn.createconnection(); // Method name corrected to createconnection()
    G_Tours w;

    if (test) {
        w.show();
        QMessageBox::information(nullptr, "Database Status",
                                 "Connection successful!", QMessageBox::Ok);
    } else {
        QMessageBox::critical(nullptr, "Database Error",
                              "Failed to connect to the database.", QMessageBox::Ok);
    }

    return a.exec();
}

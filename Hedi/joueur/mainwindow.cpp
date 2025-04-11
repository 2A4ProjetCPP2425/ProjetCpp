// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , joueurWindow(nullptr)
{
    ui->setupUi(this); // Setup the UI first
    QPixmap pix("C:/Users/hedie/OneDrive\\ -\\ ESPRIT/Documents/Projet_joueur/x.jpg");
    ui->label_pic->setPixmap(pix);
}




MainWindow::~MainWindow()
{
    delete ui;
    delete joueurWindow; // Suppression sécurisée (delete nullptr est autorisé)
}





void MainWindow::on_joueur_b_clicked()
{
    if (!joueurWindow) {
        joueurWindow = new joueur(this); // Création correcte
    }
    joueurWindow->show();
    joueurWindow->raise();
    joueurWindow->activateWindow();
}


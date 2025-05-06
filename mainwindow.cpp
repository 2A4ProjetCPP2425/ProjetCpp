#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , joueurWindow(nullptr)
    , equipeWindow(nullptr)
    , stadeWindow(nullptr)
    , toursWindow(nullptr) // Initialize toursWindow
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/hedie/OneDrive - ESPRIT/Documents/Projet_joueur/x.jpg");
    ui->label_pic->setPixmap(pix);

    arduinoManager = new ArduinoManager(this);
    if (!arduinoManager->connectArduino()) {
        qDebug() << "Arduino connection failed!";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete joueurWindow;
    delete equipeWindow;
    delete stadeWindow;
    delete toursWindow; // Clean up toursWindow
}

void MainWindow::on_joueur_b_clicked()
{
    if (!joueurWindow) {
        joueurWindow = new joueur(this);
    }
    joueurWindow->show();
    joueurWindow->raise();
    joueurWindow->activateWindow();
}

void MainWindow::on_equipe_b_clicked()
{
    if (!equipeWindow) {
        equipeWindow = new equipe_window(this);
    }
    equipeWindow->show();
    equipeWindow->raise();
    equipeWindow->activateWindow();
}

void MainWindow::on_Stade_b_clicked()
{
    if (!stadeWindow) {
        stadeWindow = new StadeWindow(this);
    }
    stadeWindow->show();
    stadeWindow->raise();
    stadeWindow->activateWindow();
    this->hide();
}

void MainWindow::switchBackToPlayer()
{
    this->show();
    if (stadeWindow) {
        stadeWindow->hide();
    }
}

void MainWindow::on_Tours_b_clicked()
{
    if (!toursWindow) {
        toursWindow = new G_Tours(this);
    }
    toursWindow->show();
    toursWindow->raise();
    toursWindow->activateWindow();
    this->hide(); // Hide the main window
}

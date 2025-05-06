#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "joueur.h"
#include "arduinomanager.h"
#include "equipe_window.h"
#include "stadewindow.h"
#include "G_Tours.h" // Include G_Tours header

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_joueur_b_clicked();
    void on_equipe_b_clicked();
    void on_Stade_b_clicked();
    void switchBackToPlayer();
    void on_Tours_b_clicked(); // Add slot for Tours_b

private:
    Ui::MainWindow *ui;
    joueur *joueurWindow;
    ArduinoManager *arduinoManager;
    equipe_window *equipeWindow;
    StadeWindow *stadeWindow;
    G_Tours *toursWindow; // Add pointer for G_Tours
};

#endif // MAINWINDOW_H

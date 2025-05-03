#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "joueur.h"
#include "arduinomanager.h"
#include "equipe_window.h"
#include "stadewindow.h"  // Include StadeWindow

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT  // Add this macro

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_joueur_b_clicked();
    void on_equipe_b_clicked();
    void on_Stade_b_clicked();
    void switchBackToPlayer();

private:
    Ui::MainWindow *ui;
    joueur *joueurWindow;
    ArduinoManager *arduinoManager;
    equipe_window *equipeWindow;
    StadeWindow *stadeWindow;
};

#endif // MAINWINDOW_H

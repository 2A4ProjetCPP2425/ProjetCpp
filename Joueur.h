// joueur.h
#ifndef JOUEUR_H
#define JOUEUR_H

#include <QDialog>
#include "player.h"

namespace Ui {
class joueur;
}

class joueur : public QDialog
{
    Q_OBJECT

public:
    explicit joueur(QWidget *parent = nullptr);
    ~joueur();

private slots:
    void on_button_ajout_clicked();
    void on_valider_recherche_clicked();


private:
    Ui::joueur *ui;
};

#endif // JOUEUR_H

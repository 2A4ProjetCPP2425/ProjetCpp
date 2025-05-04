#ifndef JOUEUR_H
#define JOUEUR_H

#include <QDialog>
#include "player.h"
#include <QLineEdit>

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
    void on_valider_suppression_clicked();
    void on_valider_modification_clicked();
    void AfficherListeJoueurs();
    void on_exportPdfButton_clicked();
    void updateBestPlayers(int tour, const QString &poste, QLineEdit *lineEdit);
    QString getPlayerName(int playerId);
    void updateRfidStatus(const QString &message);

private:
    Ui::joueur *ui;
    Player Etmp;
    QSqlQueryModel *model;
};

#endif // JOUEUR_H

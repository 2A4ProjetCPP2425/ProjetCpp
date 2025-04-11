// joueur.cpp
#include "joueur.h"
#include "player.h"
#include "ui_joueur.h"
#include <QMessageBox>
#include <QSqlQuery>

joueur::joueur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::joueur)
{
    ui->setupUi(this);
}

joueur::~joueur()
{
    delete ui;
}

void joueur::on_button_ajout_clicked()
{
    bool ok;
    int id = ui->ID_joueur2->text().toInt(&ok);
    if(!ok) {
        QMessageBox::warning(this, "Erreur", "ID invalide");
        return;
    }

    Player newPlayer(id, ui->Nom2->text(), ui->Prenom2->text(), ui->Age2->text().toInt(),
                     ui->Poste2->text(), ui->Equipe_Actuelle2->text(), ui->Nationalite2->text());

    if(newPlayer.ajouter()) {
        QMessageBox::information(this, "Succès", "Joueur ajouté !");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout");
    }
}

void joueur::on_valider_recherche_clicked()
{
    int id = ui->Recherche->text().toInt();
    QSqlQuery query;
    query.prepare("SELECT * FROM JOUEUR WHERE ID_JOUEUR = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        ui->ID_joueur->setText(query.value("ID_JOUEUR").toString());
        ui->Nationalite->setText(query.value("NATIONALITE").toString());
        ui->Nom->setText(query.value("NOM").toString());
        ui->Prenom->setText(query.value("PRENOM").toString());
        ui->Poste->setText(query.value("POSTE").toString());
        ui->Equipe_Actuelle->setText(query.value("EQUIPE_ACTUEL").toString());
        ui->Age->setText(query.value("AGE").toString());
    } else {
        QMessageBox::warning(this, "Erreur", "Joueur introuvable");
    }
}


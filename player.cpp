#include "player.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include "Joueur.h"

Player::Player() : id(0), age(0) {}
//a
Player::Player(int id, QString nom, QString prenom, int age,
               QString poste, QString equipe, QString nationalite, QString rfid_uid) :
    id(id), nom(nom), prenom(prenom), age(age),
    poste(poste), equipe(equipe), nationalite(nationalite), rfid_uid(rfid_uid) {}
bool Player::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO JOUEUR (ID_JOUEUR, NOM, PRENOM, AGE, POSTE, EQUIPE_ACTUEL, NATIONALITE, RFID_UID) "
                  "VALUES (:id, :nom, :prenom, :age, :poste, :equipe, :nationalite, :rfid)");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":age", age);
    query.bindValue(":poste", poste);
    query.bindValue(":equipe", equipe);
    query.bindValue(":nationalite", nationalite);
    if (rfid_uid.isEmpty()) {
        query.bindValue(":rfid", QVariant());
    } else {
        query.bindValue(":rfid", rfid_uid);
    }
    return query.exec();
}
bool Player::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM JOUEUR WHERE ID_JOUEUR = :id");
    query.bindValue(":id", id);
    return query.exec();
}

QSqlQueryModel* Player::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_JOUEUR, NOM, PRENOM, POSTE FROM JOUEUR");
    return model;
}

bool Player::modifier(int id, QString equipe_actuelle, int nb_matches, int nb_buts, int nb_passes, int nb_cleansheet, int age,
                      bool updateEquipe, bool updateMatches, bool updateButs, bool updatePasses, bool updateCleansheet, bool updateAge)
{
    QSqlQuery query;
    QString queryString = "UPDATE JOUEUR SET ";

    if (updateEquipe) queryString += "EQUIPE_ACTUEL = :equipe_actuelle, ";
    if (updateMatches) queryString += "NB_MATCHES = :nb_matches, ";
    if (updateButs) queryString += "NB_BUTS = :nb_buts, ";
    if (updatePasses) queryString += "NB_PASSES = :nb_passes, ";
    if (updateCleansheet) queryString += "NB_CLEANSHEET = :nb_cleansheet, ";
    if (updateAge) queryString += "AGE = :age, ";

    queryString.chop(2);
    queryString += " WHERE ID_JOUEUR = :id";

    query.prepare(queryString);
    if (updateEquipe) query.bindValue(":equipe_actuelle", equipe_actuelle);
    if (updateMatches) query.bindValue(":nb_matches", nb_matches);
    if (updateButs) query.bindValue(":nb_buts", nb_buts);
    if (updatePasses) query.bindValue(":nb_passes", nb_passes);
    if (updateCleansheet) query.bindValue(":nb_cleansheet", nb_cleansheet);
    if (updateAge) query.bindValue(":age", age);
    query.bindValue(":id", id);

    return query.exec();
}

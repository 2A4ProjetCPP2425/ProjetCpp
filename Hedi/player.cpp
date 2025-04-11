
// player.cpp
#include "player.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include "Joueur.h"

Player::Player() : id(0), age(0) {}

Player::Player(int id, QString nom, QString prenom, int age,
               QString poste, QString equipe, QString nationalite) :
    id(id), nom(nom), prenom(prenom), age(age),
    poste(poste), equipe(equipe), nationalite(nationalite) {}

bool Player::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO JOUEUR (ID_JOUEUR, NOM, PRENOM, AGE, POSTE, EQUIPE_ACTUEL, NATIONALITE) "
                  "VALUES (:id, :nom, :prenom, :age, :poste, :equipe, :nationalite)");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":age", age);
    query.bindValue(":poste", poste);
    query.bindValue(":equipe", equipe);
    query.bindValue(":nationalite", nationalite);
    return query.exec();
}

QSqlQueryModel* Player::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM JOUEUR");
    return model;
}

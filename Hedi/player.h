
// player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Player
{
public:
    Player();
    Player(int id, QString nom, QString prenom, int age, QString poste,
           QString equipe, QString nationalite);

    bool ajouter();
    static QSqlQueryModel* afficher();

private:
    int id;
    QString nom;
    QString prenom;
    int age;
    QString poste;
    QString equipe;
    QString nationalite;
};

#endif // PLAYER_H

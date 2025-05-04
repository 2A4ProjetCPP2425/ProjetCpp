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
           QString equipe, QString nationalite, QString rfid_uid = "");

    bool ajouter();
    static QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int id, QString equipe_actuelle, int nb_matches, int nb_buts, int nb_passes, int nb_cleansheet, int age,
                  bool updateEquipe, bool updateMatches, bool updateButs, bool updatePasses, bool updateCleansheet, bool updateAge);

private:
    int id;
    QString nom;
    QString prenom;
    int age;
    QString poste;
    QString equipe;
    QString nationalite;
    QString rfid_uid;
};

#endif // PLAYER_H

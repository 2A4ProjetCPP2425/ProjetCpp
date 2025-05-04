#ifndef STADE_H
#define STADE_H

#include <QString>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QMap>

class Stade {
public:
    Stade();
    Stade(int id, QString nom_stade, int capacite, QString localisation, QString statut);
    Stade(QString nom_stade, int capacite, QString localisation, QString statut);

    // Getter methods
    int getID() const;
    QString getNomStade() const;
    int getCapacite() const;
    QString getLocalisation() const;
    QString getStatut() const;

    // Setter methods
    void setID(int id);
    void setNomStade(QString nom_stade);
    void setCapacite(int capacite);
    void setLocalisation(QString localisation);
    void setStatut(QString statut);

    // Database operations
    bool ajouter();
    QAbstractItemModel* afficher();
    bool supprimer(int id);
    bool modifier(int id);
    static QSqlQueryModel* rechercherParNom(QString nom);
    QSqlQueryModel* Tri(QString cls, QString champ);
    QMap<QString, int> getStadiumsPerLocation();

private:
    int id;
    QString nom_stade;
    int capacite;
    QString localisation;
    QString statut;
};

#endif // STADE_H

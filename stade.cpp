#include "stade.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QIcon>
#include <QFile>
#include <QStandardItemModel>

// Constructors
Stade::Stade() {}

Stade::Stade(int id, QString nom_stade, int capacite, QString localisation, QString statut)
    : id(id), nom_stade(nom_stade), capacite(capacite), localisation(localisation), statut(statut) {}

Stade::Stade(QString nom_stade, int capacite, QString localisation, QString statut)
    : nom_stade(nom_stade), capacite(capacite), localisation(localisation), statut(statut) {}

// Getters
int Stade::getID() const {
    return id;
}

QString Stade::getNomStade() const {
    return nom_stade;
}

int Stade::getCapacite() const {
    return capacite;
}

QString Stade::getLocalisation() const {
    return localisation;
}

QString Stade::getStatut() const {
    return statut;
}

// Setters
void Stade::setID(int id) {
    this->id = id;
}

void Stade::setNomStade(QString nom_stade) {
    this->nom_stade = nom_stade;
}

void Stade::setCapacite(int capacite) {
    this->capacite = capacite;
}

void Stade::setLocalisation(QString localisation) {
    this->localisation = localisation;
}

void Stade::setStatut(QString statut) {
    this->statut = statut;
}

// Database operations
bool Stade::ajouter() {
    QSqlQuery query;

    query.prepare("INSERT INTO stade (nom_stade, capacite, localisation, statut) "
                  "VALUES (:nom_stade, :capacite, :localisation, :statut)");

    query.bindValue(":nom_stade", nom_stade);
    query.bindValue(":capacite", capacite);
    query.bindValue(":localisation", localisation);
    query.bindValue(":statut", statut);

    return query.exec();
}

QAbstractItemModel* Stade::afficher() {
    // Create standard item model instead of SQL model
    QStandardItemModel *model = new QStandardItemModel();

    // Set headers
    model->setHorizontalHeaderLabels({"ID", "Nom du Stade", "Capacité", "Localisation", "Statut", "Calendrier"});

    // Load data from database
    QSqlQuery query("SELECT id_stade, nom_stade, capacite, localisation, statut FROM stade ORDER BY id_stade");
    while (query.next()) {
        QList<QStandardItem*> rowItems;

        // Add regular data columns
        for (int col = 0; col < 5; ++col) {
            rowItems << new QStandardItem(query.value(col).toString());
        }

        // Add icon column
        QStandardItem *iconItem = new QStandardItem();
        iconItem->setIcon(QIcon(":/images/images/icon.png"));
        iconItem->setToolTip("View Calendar");
        rowItems << iconItem;

        model->appendRow(rowItems);
    }

    return model;
}

bool Stade::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM stade WHERE id_stade = :id");
    query.bindValue(":id", id);
    return query.exec();
}

bool Stade::modifier(int id) {
    QSqlQuery query;

    query.prepare("UPDATE stade SET nom_stade = :nom_stade, capacite = :capacite, "
                  "localisation = :localisation, statut = :statut WHERE id_stade = :id");
    query.bindValue(":id", id);
    query.bindValue(":nom_stade", nom_stade);
    query.bindValue(":capacite", capacite);
    query.bindValue(":localisation", localisation);
    query.bindValue(":statut", statut);

    return query.exec();
}

QSqlQueryModel* Stade::rechercherParNom(QString terme) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT id_stade AS id, nom_stade, capacite, localisation, statut FROM stade WHERE nom_stade LIKE :terme");
    query.bindValue(":terme", "%" + terme + "%");

    if (query.exec()) {
        model->setQuery(query);
    } else {
        qDebug() << "Failed to execute search query:" << query.lastError().text();
    }

    return model;
}

QSqlQueryModel* Stade::Tri(QString cls, QString champ) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QString queryString = "SELECT * FROM stade ORDER BY " + champ + " " + cls;
    QSqlQuery query;
    query.prepare(queryString);
    query.exec();
    model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_STADE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_STADE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CAPACITE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("LOCALISATION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("STATUT"));

    return model;
}
QMap<QString, int> Stade::getStadiumsPerLocation() {
    QMap<QString, int> locationCounts;

    QSqlQuery query;
    query.prepare("SELECT localisation, COUNT(*) as count "
                  "FROM stade "
                  "GROUP BY localisation "
                  "ORDER BY count DESC");

    if (query.exec()) {
        while (query.next()) {
            QString location = query.value("localisation").toString();
            int count = query.value("count").toInt();
            locationCounts.insert(location, count);
        }
    } else {
        qDebug() << "Location stats query error:" << query.lastError().text();
    }

    return locationCounts;
}

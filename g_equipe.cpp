#include "g_equipe.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>
#include <random>

g_equipe::g_equipe(connection& conn, QObject *parent) : QObject(parent), conn(conn) {
}

g_equipe::~g_equipe() {
}

bool g_equipe::addEquipe(int id, const QString& nom, int participations, int tot_matches, double moy_buts, const QString& buteur, const QString& classe) {
    QSqlQuery query;
    query.prepare("INSERT INTO HEDI.EQUIPE (ID_EQUIPE, NOM_EQUIPE, PARTICIPATIONS, TOT_MATCHES, MOY_BUTS, BUTTEUR, CLASSE) "
                  "VALUES (:id, :nom, :participations, :tot_matches, :moy_buts, :buteur, :classe)");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":participations", participations);
    query.bindValue(":tot_matches", tot_matches);
    query.bindValue(":moy_buts", moy_buts);
    query.bindValue(":buteur", buteur);
    query.bindValue(":classe", classe);

    if (query.exec()) {
        QMessageBox::information(nullptr, "Succès", "Équipe ajoutée avec succès !");
        return true;
    } else {
        QMessageBox::critical(nullptr, "Erreur", "Échec de l'ajout : " + query.lastError().text());
        return false;
    }
}

bool g_equipe::modifyEquipe(int id, int participations, int tot_matches, double moy_buts, const QString& buteur, const QString& classe) {
    QSqlQuery query;
    query.prepare("UPDATE HEDI.EQUIPE SET PARTICIPATIONS = :participations, TOT_MATCHES = :tot_matches, "
                  "MOY_BUTS = :moy_buts, BUTTEUR = :buteur, CLASSE = :classe WHERE ID_EQUIPE = :id");
    query.bindValue(":participations", participations);
    query.bindValue(":tot_matches", tot_matches);
    query.bindValue(":moy_buts", moy_buts);
    query.bindValue(":buteur", buteur);
    query.bindValue(":classe", classe);
    query.bindValue(":id", id);

    if (query.exec()) {
        QMessageBox::information(nullptr, "Succès", "Équipe modifiée avec succès !");
        return true;
    } else {
        QMessageBox::critical(nullptr, "Erreur", "Échec de la modification : " + query.lastError().text());
        return false;
    }
}

bool g_equipe::modifier(int id, int participations, int tot_matches, double moy_buts, const QString& buteur, const QString& classe,
                        bool updateParticipations, bool updateTotMatches, bool updateMoyButs, bool updateButeur, bool updateClasse) {
    QSqlQuery query;
    QString queryString = "UPDATE HEDI.EQUIPE SET ";

    if (updateParticipations) queryString += "PARTICIPATIONS = :participations, ";
    if (updateTotMatches) queryString += "TOT_MATCHES = :tot_matches, ";
    if (updateMoyButs) queryString += "MOY_BUTS = :moy_buts, ";
    if (updateButeur) queryString += "BUTTEUR = :buteur, ";
    if (updateClasse) queryString += "CLASSE = :classe, ";

    if (queryString.endsWith(", ")) {
        queryString.chop(2);
    } else {
        return false;
    }

    queryString += " WHERE ID_EQUIPE = :id";

    query.prepare(queryString);
    if (updateParticipations) query.bindValue(":participations", participations);
    if (updateTotMatches) query.bindValue(":tot_matches", tot_matches);
    if (updateMoyButs) query.bindValue(":moy_buts", moy_buts);
    if (updateButeur) query.bindValue(":buteur", buteur);
    if (updateClasse) query.bindValue(":classe", classe);
    query.bindValue(":id", id);

    if (query.exec()) {
        QMessageBox::information(nullptr, "Succès", "Équipe modifiée avec succès !");
        return true;
    } else {
        QMessageBox::critical(nullptr, "Erreur", "Échec de la modification : " + query.lastError().text());
        return false;
    }
}

bool g_equipe::deleteEquipe(const QString& searchText) {
    QSqlQuery query;
    bool isId = false;
    int id = searchText.toInt(&isId);
    if (isId) {
        query.prepare("DELETE FROM HEDI.EQUIPE WHERE ID_EQUIPE = :id");
        query.bindValue(":id", id);
    } else {
        query.prepare("DELETE FROM HEDI.EQUIPE WHERE NOM_EQUIPE = :nom");
        query.bindValue(":nom", searchText);
    }
    if (query.exec()) {
        QMessageBox::information(nullptr, "Succès", "Équipe supprimée avec succès !");
        return true;
    } else {
        QMessageBox::critical(nullptr, "Erreur", "Échec de la suppression : " + query.lastError().text());
        return false;
    }
}

QList<QVariantList> g_equipe::searchEquipes(const QString& text) {
    QList<QVariantList> results;
    QSqlQuery query;
    bool isId = false;
    int id = text.toInt(&isId);
    if (isId) {
        query.prepare("SELECT ID_EQUIPE, NOM_EQUIPE, PARTICIPATIONS, TOT_MATCHES, MOY_BUTS, BUTTEUR, CLASSE "
                      "FROM HEDI.EQUIPE WHERE ID_EQUIPE = :id");
        query.bindValue(":id", id);
    } else {
        query.prepare("SELECT ID_EQUIPE, NOM_EQUIPE, PARTICIPATIONS, TOT_MATCHES, MOY_BUTS, BUTTEUR, CLASSE "
                      "FROM HEDI.EQUIPE WHERE NOM_EQUIPE LIKE '%' || :nom || '%'");
        query.bindValue(":nom", text);
    }

    if (query.exec()) {
        while (query.next()) {
            QVariantList row;
            row << query.value(0) << query.value(1) << query.value(2)
                << query.value(3) << query.value(4) << query.value(5) << query.value(6);
            results.append(row);
        }
    } else {
        qDebug() << "Erreur lors de la recherche :" << query.lastError().text();
    }
    return results;
}

QList<QList<QVariantList>> g_equipe::performRandomDraw() {
    QList<QList<QVariantList>> groups(4);
    QHash<QString, QList<QVariantList>> classes;

    // Fetch teams
    QSqlQuery query("SELECT ID_EQUIPE, NOM_EQUIPE, CLASSE FROM HEDI.EQUIPE");
    while (query.next()) {
        QVariantList team;
        team << query.value(0) << query.value(1) << query.value(2);
        classes[query.value(2).toString()].append(team);
    }

    // Shuffle each class
    std::random_device rd;
    std::mt19937 rng(rd());
    QStringList classList = {"A", "B", "C", "D"};
    for (const QString& classe : classList) {
        auto& teams = classes[classe];
        std::shuffle(teams.begin(), teams.end(), rng);
    }

    // Distribute one team from each class to each group
    for (int i = 0; i < 4; ++i) {
        for (const QString& classe : classList) {
            if (!classes[classe].isEmpty()) {
                groups[i].append(classes[classe].takeFirst());
            }
        }
    }

    return groups;
}

#ifndef G_EQUIPE_H
#define G_EQUIPE_H

#include <QObject>
#include <QList>
#include "connection.h"

class g_equipe : public QObject {
    Q_OBJECT

public:
    explicit g_equipe(connection& conn, QObject *parent = nullptr);
    ~g_equipe();

    bool addEquipe(int id, const QString& nom, int participations, int tot_matches, double moy_buts, const QString& buteur, const QString& classe);
    bool modifyEquipe(int id, int participations, int tot_matches, double moy_buts, const QString& buteur, const QString& classe);
    bool modifier(int id, int participations, int tot_matches, double moy_buts, const QString& buteur, const QString& classe,
                  bool updateParticipations, bool updateTotMatches, bool updateMoyButs, bool updateButeur, bool updateClasse);
    bool deleteEquipe(const QString& searchText);
    QList<QList<QVariantList>> performRandomDraw();
    QList<QVariantList> searchEquipes(const QString& text);

private:
    connection& conn;
};

#endif // G_EQUIPE_H

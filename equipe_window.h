#ifndef EQUIPE_WINDOW_H
#define EQUIPE_WINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "g_equipe.h"
#include "connection.h"

namespace Ui {
class equipe_window;
}

class equipe_window : public QMainWindow {
    Q_OBJECT

public:
    explicit equipe_window(QWidget *parent = nullptr);
    ~equipe_window();

private slots:
    void on_valider_ajout_clicked();
    void on_valider_modifier_clicked();
    void on_Valider_supprimer_clicked();
    void on_recherche_textChanged(const QString &text);
    void on_fetch_equipe_clicked();
    void on_valider_recherche_clicked();
    void on_tirageSort_clicked();
    void on_tableHeader_doubleClicked(int logicalIndex);
    void on_PDF_clicked();

private:
    void refreshTable(const QString& orderBy = "");
    void populateModificationFields(int id, int participations, int tot_matches, double moy_buts, const QString& buteur, const QString& classe);
    double calculateTeamMarketValue(int teamId, QStringList& playerDetails);

    Ui::equipe_window *ui;
    connection conn;
    g_equipe* ge;
    QStandardItemModel* model;
    QStandardItemModel *modelGroup1;
    QStandardItemModel *modelGroup2;
    QStandardItemModel *modelGroup3;
    QStandardItemModel *modelGroup4;
    QStandardItemModel *joueursModel;
};

#endif // EQUIPE_WINDOW_H

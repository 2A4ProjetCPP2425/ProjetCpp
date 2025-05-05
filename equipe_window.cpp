#include "equipe_window.h"
#include "ui_equipe_window.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QRegularExpression>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QDateTime>

equipe_window::equipe_window(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::equipe_window),
    conn(),
    ge(nullptr),
    model(nullptr),
    joueursModel(new QStandardItemModel(this)) {
    ui->setupUi(this);

    // Establish the database connection
    if (!conn.createconnection()) {
        QSqlDatabase db = QSqlDatabase::database();
        QMessageBox::critical(this, "Erreur", "Connexion échouée: " + db.lastError().text());
        close();
        return;
    }

    ge = new g_equipe(conn, this);

    // Initialize group models
    modelGroup1 = new QStandardItemModel(this);
    modelGroup1->setColumnCount(3);
    modelGroup1->setHorizontalHeaderLabels({"ID", "Nom", "Classe"});
    ui->groupe1->setModel(modelGroup1);

    modelGroup2 = new QStandardItemModel(this);
    modelGroup2->setColumnCount(3);
    modelGroup2->setHorizontalHeaderLabels({"ID", "Nom", "Classe"});
    ui->groupe2->setModel(modelGroup2);

    modelGroup3 = new QStandardItemModel(this);
    modelGroup3->setColumnCount(3);
    modelGroup3->setHorizontalHeaderLabels({"ID", "Nom", "Classe"});
    ui->groupe3->setModel(modelGroup3);

    modelGroup4 = new QStandardItemModel(this);
    modelGroup4->setColumnCount(3);
    modelGroup4->setHorizontalHeaderLabels({"ID", "Nom", "Classe"});
    ui->groupe4->setModel(modelGroup4);

    // Initialize joueursList model
    joueursModel->setColumnCount(3);
    joueursModel->setHorizontalHeaderLabels({"ID", "Name", "Market Value"});
    ui->joueursList->setModel(joueursModel);
    ui->joueursList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->joueursList->horizontalHeader()->setStretchLastSection(true);
    ui->joueursList->setColumnWidth(0, 50); // ID column
    ui->joueursList->setColumnWidth(1, 150); // Name column

    // Connect the tirageSort button
    connect(ui->Tirageausort, &QPushButton::clicked, this, &equipe_window::on_tirageSort_clicked);

    // Set up the table view
    model = new QStandardItemModel(this);
    model->setColumnCount(7);
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, tr("Participations"));
    model->setHeaderData(3, Qt::Horizontal, tr("Tot Matches"));
    model->setHeaderData(4, Qt::Horizontal, tr("Moy Buts"));
    model->setHeaderData(5, Qt::Horizontal, tr("Buteur"));
    model->setHeaderData(6, Qt::Horizontal, tr("Classe"));
    ui->Liste_equipes->setModel(model);
    ui->Liste_equipes->setSortingEnabled(true);
    ui->Liste_equipes->horizontalHeader()->setSectionsClickable(true);

    // Connect double-click on header
    connect(ui->Liste_equipes->horizontalHeader(), &QHeaderView::sectionDoubleClicked, this, &equipe_window::on_tableHeader_doubleClicked);

    // Connect the PDF button
    connect(ui->PDF, &QPushButton::clicked, this, &equipe_window::on_PDF_clicked);

    refreshTable();

    connect(ui->valider_ajout, &QPushButton::clicked, this, &equipe_window::on_valider_ajout_clicked);
    connect(ui->valider_modifier, &QPushButton::clicked, this, &equipe_window::on_valider_modifier_clicked);
    connect(ui->Valider_supprimer, &QPushButton::clicked, this, &equipe_window::on_Valider_supprimer_clicked);
    connect(ui->recherche, &QLineEdit::textChanged, this, &equipe_window::on_recherche_textChanged);
    connect(ui->rechercher_button, &QPushButton::clicked, this, &equipe_window::on_valider_recherche_clicked);
}

equipe_window::~equipe_window() {
    conn.closeconnection();
    delete model;
    delete joueursModel;
    delete ge;
    delete ui;
}

void equipe_window::refreshTable(const QString& orderBy) {
    model->removeRows(0, model->rowCount());
    QSqlQuery query;
    QString queryString = "SELECT ID_EQUIPE, NOM_EQUIPE, PARTICIPATIONS, TOT_MATCHES, MOY_BUTS, BUTTEUR, CLASSE "
                          "FROM HEDI.EQUIPE";
    if (!orderBy.isEmpty()) {
        queryString += " ORDER BY " + orderBy;
    }
    query.prepare(queryString);

    if (query.exec()) {
        while (query.next()) {
            QList<QStandardItem*> items;
            items << new QStandardItem(query.value(0).toString())
                  << new QStandardItem(query.value(1).toString())
                  << new QStandardItem(query.value(2).toString())
                  << new QStandardItem(query.value(3).toString())
                  << new QStandardItem(query.value(4).toString())
                  << new QStandardItem(query.value(5).toString())
                  << new QStandardItem(query.value(6).toString());
            model->appendRow(items);
        }
    } else {
        QMessageBox::warning(this, "Erreur", "Erreur lors du chargement des données : " + query.lastError().text());
    }
}

void equipe_window::populateModificationFields(int id, int participations, int tot_matches, double moy_buts, const QString& buteur, const QString& classe) {
    ui->recherche->setText(QString::number(id));
    ui->participations_modif->setText(QString::number(participations));
    ui->Total_matches_modif->setText(QString::number(tot_matches));
    ui->Moyen_but_modif->setText(QString::number(moy_buts));
    ui->Buteur_modif->setText(buteur);
    ui->Classe_modif->setText(classe);
}

void equipe_window::on_tableHeader_doubleClicked(int logicalIndex) {
    QString column;
    switch (logicalIndex) {
    case 0: // ID
        column = "ID_EQUIPE";
        break;
    case 1: // Nom
        column = "NOM_EQUIPE";
        break;
    case 6: // Classe
        column = "CLASSE";
        break;
    default:
        return;
    }

    static QMap<int, Qt::SortOrder> sortOrder;
    Qt::SortOrder order = sortOrder.value(logicalIndex, Qt::AscendingOrder) == Qt::AscendingOrder ? Qt::DescendingOrder : Qt::AscendingOrder;
    sortOrder[logicalIndex] = order;

    QString orderBy = QString("%1 %2").arg(column, order == Qt::AscendingOrder ? "ASC" : "DESC");
    refreshTable(orderBy);
}

double equipe_window::calculateTeamMarketValue(int teamId, QStringList& playerDetails) {
    double totalMarketValue = 0.0;
    playerDetails.clear();
    QSqlQuery query;
    query.prepare("SELECT ID_JOUEUR, NOM, PRENOM, NB_BUTS, NB_PASSES, NB_CLEANSHEET, NB_MATCHES, AGE, POSTE "
                  "FROM JOUEUR WHERE ID_EQUIPE = :teamId");
    query.bindValue(":teamId", teamId);

    if (query.exec()) {
        while (query.next()) {
            int id_joueur = query.value("ID_JOUEUR").toInt();
            QString nom = query.value("NOM").toString();
            QString prenom = query.value("PRENOM").toString();
            int nb_buts = query.value("NB_BUTS").toInt();
            int nb_passes = query.value("NB_PASSES").toInt();
            int nb_cleansheet = query.value("NB_CLEANSHEET").toInt();
            int nb_matches = query.value("NB_MATCHES").toInt();
            int age = query.value("AGE").toInt();
            QString poste = query.value("POSTE").toString().toUpper();

            // Calculate A1 based on position (from Joueur.cpp)
            double but_percent, pass_percent, cleansheet_percent;
            if (poste == "ATTAQUANT") {
                but_percent = 0.7;
                pass_percent = 0.3;
                cleansheet_percent = 0.0;
            } else if (poste == "MILIEU") {
                but_percent = 0.3;
                pass_percent = 0.7;
                cleansheet_percent = 0.0;
            } else if (poste == "DEFENSEUR") {
                but_percent = 0.1;
                pass_percent = 0.05;
                cleansheet_percent = 0.85;
            } else if (poste == "GARDIEN") {
                but_percent = 0.05;
                pass_percent = 0.05;
                cleansheet_percent = 0.9;
            } else {
                but_percent = pass_percent = cleansheet_percent = 0.0;
            }

            double A1 = 0.0;
            if (nb_matches > 0) {
                double total = (nb_buts * but_percent) + (nb_passes * pass_percent) + (nb_cleansheet * cleansheet_percent);
                A1 = total / nb_matches;
            }

            // Apply age multiplier (from Joueur.cpp)
            double multiplier;
            if (age >= 16 && age <= 24) {
                multiplier = 1.7;
            } else if (age >= 25 && age <= 28) {
                multiplier = 1.4;
            } else if (age >= 29 && age <= 33) {
                multiplier = 1.1;
            } else if (age >= 34 && age <= 38) {
                multiplier = 0.8;
            } else if (age >= 39) {
                multiplier = 0.5;
            } else {
                multiplier = 0.0;
            }

            // Calculate player's market value
            double playerMarketValue = A1 * multiplier * 100000;
            totalMarketValue += playerMarketValue;

            // Add player details to the list
            playerDetails.append(QString::number(id_joueur));
            playerDetails.append(QString("%1 %2").arg(nom, prenom));
            playerDetails.append(QString("$%1").arg(playerMarketValue, 0, 'f', 2));
        }
    } else {
        QMessageBox::warning(this, "Erreur", "Erreur lors du calcul de la valeur marchande : " + query.lastError().text());
    }

    return totalMarketValue;
}

void equipe_window::on_PDF_clicked() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save PDF"), "", tr("PDF Files (*.pdf)"));
    if (fileName.isEmpty()) {
        return;
    }

    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive)) {
        fileName += ".pdf";
    }

    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize::A4);
    pdfWriter.setResolution(100);

    QPainter painter(&pdfWriter);
    painter.setRenderHint(QPainter::Antialiasing);

    const int margin = 50;
    const int tableWidth = pdfWriter.width() - 2 * margin;
    const int rowHeight = 50;
    const int colCount = model->columnCount();
    const int colWidth = tableWidth / colCount;

    QFont font("Arial", 10);
    painter.setFont(font);
    QFontMetrics fontMetrics(font);

    QString title = "Liste des Équipes";
    painter.drawText(margin, margin, title);
    int y = margin + fontMetrics.height() + 20;

    QStringList headers = {"ID", "Nom", "Participations", "Tot Matches", "Moy Buts", "Buteur", "Classe"};
    painter.setPen(QPen(Qt::black, 1));
    for (int col = 0; col < colCount; ++col) {
        int x = margin + col * colWidth;
        painter.drawRect(x, y, colWidth, rowHeight);
        painter.drawText(x + 5, y + rowHeight / 2 + fontMetrics.ascent() / 2, headers[col]);
    }
    y += rowHeight;

    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < colCount; ++col) {
            int x = margin + col * colWidth;
            QString text = model->data(model->index(row, col)).toString();
            painter.drawRect(x, y, colWidth, rowHeight);
            painter.drawText(x + 5, y + rowHeight / 2 + fontMetrics.ascent() / 2, text);
        }
        y += rowHeight;

        if (y > pdfWriter.height() - margin - rowHeight) {
            pdfWriter.newPage();
            y = margin;
            for (int col = 0; col < colCount; ++col) {
                int x = margin + col * colWidth;
                painter.drawRect(x, y, colWidth, rowHeight);
                painter.drawText(x + 5, y + rowHeight / 2 + fontMetrics.ascent() / 2, headers[col]);
            }
            y += rowHeight;
        }
    }

    painter.end();
    QMessageBox::information(this, "Succès", "PDF généré avec succès : " + fileName);
}

void equipe_window::on_tirageSort_clicked() {
    QSqlQuery countQuery;
    countQuery.prepare("SELECT COUNT(*) FROM HEDI.EQUIPE");
    if (countQuery.exec() && countQuery.next()) {
        int teamCount = countQuery.value(0).toInt();
        if (teamCount != 16) {
            QMessageBox::warning(this, "Erreur", "Il doit y avoir exactement 16 équipes pour le tirage.");
            return;
        }
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la vérification du nombre d'équipes: " + countQuery.lastError().text());
        return;
    }

    QSqlQuery classQuery;
    classQuery.prepare("SELECT CLASSE, COUNT(*) FROM HEDI.EQUIPE GROUP BY CLASSE");
    QHash<QString, int> classCounts;
    if (classQuery.exec()) {
        while (classQuery.next()) {
            classCounts[classQuery.value(0).toString()] = classQuery.value(1).toInt();
        }
    }
    QStringList requiredClasses = {"A", "B", "C", "D"};
    for (const QString& classe : requiredClasses) {
        if (classCounts.value(classe, 0) != 4) {
            QMessageBox::warning(this, "Erreur", QString("Il doit y avoir exactement 4 équipes dans la classe %1.").arg(classe));
            return;
        }
    }

    auto groups = ge->performRandomDraw();

    auto updateGroupModel = [](QStandardItemModel* model, const QList<QVariantList>& teams) {
        model->removeRows(0, model->rowCount());
        for (const auto& team : teams) {
            QList<QStandardItem*> items;
            items << new QStandardItem(team[0].toString());
            items << new QStandardItem(team[1].toString());
            items << new QStandardItem(team[2].toString());
            model->appendRow(items);
        }
    };

    updateGroupModel(modelGroup1, groups[0]);
    updateGroupModel(modelGroup2, groups[1]);
    updateGroupModel(modelGroup3, groups[2]);
    updateGroupModel(modelGroup4, groups[3]);
}

void equipe_window::on_fetch_equipe_clicked() {
    if (!ge) return;

    bool ok;
    int id = ui->recherche->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "ID invalide pour récupération");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT PARTICIPATIONS, TOT_MATCHES, MOY_BUTS, BUTTEUR, CLASSE FROM HEDI.EQUIPE WHERE ID_EQUIPE = :id");
    query.bindValue(":id", id);
    if (query.exec() && query.next()) {
        int participations = query.value(0).toInt();
        int tot_matches = query.value(1).toInt();
        double moy_buts = query.value(2).toDouble();
        QString buteur = query.value(3).toString();
        QString classe = query.value(4).toString();
        populateModificationFields(id, participations, tot_matches, moy_buts, buteur, classe);
    } else {
        QMessageBox::warning(this, "Erreur", "Cet ID n'existe pas ou erreur de requête");
    }
}

void equipe_window::on_valider_modifier_clicked() {
    if (!ge) return;

    bool ok;
    int id = ui->recherche->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "ID invalide pour modification");
        return;
    }

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT ID_EQUIPE FROM HEDI.EQUIPE WHERE ID_EQUIPE = :id");
    checkQuery.bindValue(":id", id);
    if (!checkQuery.exec() || !checkQuery.next()) {
        QMessageBox::warning(this, "Erreur", "Cet ID n'existe pas");
        return;
    }

    bool updateParticipations = !ui->participations_modif->text().isEmpty();
    int participations = updateParticipations ? ui->participations_modif->text().toInt(&ok) : 0;
    if (updateParticipations && (!ok || participations < 0)) {
        QMessageBox::warning(this, "Erreur", "Participations invalides");
        return;
    }

    bool updateTotMatches = !ui->Total_matches_modif->text().isEmpty();
    int tot_matches = updateTotMatches ? ui->Total_matches_modif->text().toInt(&ok) : 0;
    if (updateTotMatches && (!ok || tot_matches < 0)) {
        QMessageBox::warning(this, "Erreur", "Total matches invalide");
        return;
    }

    bool updateMoyButs = !ui->Moyen_but_modif->text().isEmpty();
    double moy_buts = updateMoyButs ? ui->Moyen_but_modif->text().toDouble(&ok) : 0.0;
    if (updateMoyButs && (!ok || moy_buts < 0)) {
        QMessageBox::warning(this, "Erreur", "Moyenne buts invalide");
        return;
    }

    bool updateButeur = !ui->Buteur_modif->text().isEmpty();
    QString buteur = updateButeur ? ui->Buteur_modif->text().trimmed() : "";
    if (updateButeur && buteur.length() > 20) {
        QMessageBox::warning(this, "Erreur", "Nom du buteur trop long");
        return;
    }

    bool updateClasse = !ui->Classe_modif->text().isEmpty();
    QString classe = updateClasse ? ui->Classe_modif->text().trimmed().toUpper() : "";
    if (updateClasse && !QStringList{"A", "B", "C", "D"}.contains(classe)) {
        QMessageBox::warning(this, "Erreur", "Classe invalide (doit être A, B, C ou D)");
        return;
    }

    QSqlQuery fetchQuery;
    fetchQuery.prepare("SELECT PARTICIPATIONS, TOT_MATCHES, MOY_BUTS, BUTTEUR, CLASSE FROM HEDI.EQUIPE WHERE ID_EQUIPE = :id");
    fetchQuery.bindValue(":id", id);
    if (!fetchQuery.exec() || !fetchQuery.next()) {
        QMessageBox::warning(this, "Erreur", "Erreur lors de la récupération des données actuelles");
        return;
    }

    if (!updateParticipations) participations = fetchQuery.value("PARTICIPATIONS").toInt();
    if (!updateTotMatches) tot_matches = fetchQuery.value("TOT_MATCHES").toInt();
    if (!updateMoyButs) moy_buts = fetchQuery.value("MOY_BUTS").toDouble();
    if (!updateButeur) buteur = fetchQuery.value("BUTTEUR").toString();
    if (!updateClasse) classe = fetchQuery.value("CLASSE").toString();

    if (ge->modifier(id, participations, tot_matches, moy_buts, buteur, classe,
                     updateParticipations, updateTotMatches, updateMoyButs, updateButeur, updateClasse)) {
        refreshTable();
        ui->participations_modif->clear();
        ui->Total_matches_modif->clear();
        ui->Moyen_but_modif->clear();
        ui->Buteur_modif->clear();
        ui->Classe_modif->clear();
        ui->recherche->clear();
        ui->valeurmarchande->clear();
        joueursModel->removeRows(0, joueursModel->rowCount());
    }
}

void equipe_window::on_valider_recherche_clicked() {
    QString searchText = ui->recherche->text().trimmed();
    if (searchText.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID ou un nom d'équipe");
        joueursModel->removeRows(0, joueursModel->rowCount());
        ui->valeurmarchande->clear();
        return;
    }

    QSqlQuery query;
    bool isId = false;
    int id = searchText.toInt(&isId);
    if (isId) {
        query.prepare("SELECT ID_EQUIPE, NOM_EQUIPE, PARTICIPATIONS, TOT_MATCHES, MOY_BUTS, BUTTEUR, CLASSE "
                      "FROM HEDI.EQUIPE WHERE ID_EQUIPE = :id");
        query.bindValue(":id", id);
    } else {
        query.prepare("SELECT ID_EQUIPE, NOM_EQUIPE, PARTICIPATIONS, TOT_MATCHES, MOY_BUTS, BUTTEUR, CLASSE "
                      "FROM HEDI.EQUIPE WHERE NOM_EQUIPE = :nom");
        query.bindValue(":nom", searchText);
    }

    if (query.exec() && query.next()) {
        int id = query.value("ID_EQUIPE").toInt();
        ui->recherche->setText(query.value("ID_EQUIPE").toString());
        ui->participations_modif->setText(query.value("PARTICIPATIONS").toString());
        ui->Total_matches_modif->setText(query.value("TOT_MATCHES").toString());
        ui->Moyen_but_modif->setText(query.value("MOY_BUTS").toString());
        ui->Buteur_modif->setText(query.value("BUTTEUR").toString());
        ui->Classe_modif->setText(query.value("CLASSE").toString());

        // Calculate and display team market value and player details
        QStringList playerDetails;
        double marketValue = calculateTeamMarketValue(id, playerDetails);
        ui->valeurmarchande->setText(QString("$%1").arg(marketValue, 0, 'f', 2));

        // Populate joueursModel with player details
        joueursModel->removeRows(0, joueursModel->rowCount());
        for (int i = 0; i < playerDetails.size(); i += 3) {
            QList<QStandardItem*> items;
            items << new QStandardItem(playerDetails[i]); // ID
            items << new QStandardItem(playerDetails[i + 1]); // Name
            items << new QStandardItem(playerDetails[i + 2]); // Market Value
            joueursModel->appendRow(items);
        }
    } else {
        QMessageBox::warning(this, "Erreur", "Équipe introuvable");
        ui->valeurmarchande->clear();
        joueursModel->removeRows(0, joueursModel->rowCount());
    }
}

void equipe_window::on_valider_ajout_clicked() {
    if (!ge) return;

    bool ok;
    int id = ui->id_equ->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "ID invalide");
        return;
    }

    QString nom = ui->Nom_eq->text().trimmed();
    if (nom.isEmpty() || nom.length() > 20) {
        QMessageBox::warning(this, "Erreur", "Nom d'équipe invalide");
        return;
    }

    int participations = ui->Participation_ajout->text().toInt(&ok);
    if (!ok || participations < 0) {
        QMessageBox::warning(this, "Erreur", "Participations invalides");
        return;
    }

    int tot_matches = ui->tot_matchs_ajout->text().toInt(&ok);
    if (!ok || tot_matches < 0) {
        QMessageBox::warning(this, "Erreur", "Total matches invalide");
        return;
    }

    double moy_buts = ui->moy_buts_ajout->text().toDouble(&ok);
    if (!ok || moy_buts < 0) {
        QMessageBox::warning(this, "Erreur", "Moyenne buts invalide");
        return;
    }

    QString buteur = ui->buteur_ajout->text().trimmed();
    if (buteur.length() > 20) {
        QMessageBox::warning(this, "Erreur", "Nom du buteur trop long");
        return;
    }

    QString classe = ui->Classe_ajout->text().trimmed().toUpper();
    if (!QStringList{"A", "B", "C", "D"}.contains(classe)) {
        QMessageBox::warning(this, "Erreur", "Classe invalide (doit être A, B, C ou D)");
        return;
    }

    if (ge->addEquipe(id, nom, participations, tot_matches, moy_buts, buteur, classe)) {
        refreshTable();
        ui->id_equ->clear();
        ui->Nom_eq->clear();
        ui->Participation_ajout->clear();
        ui->tot_matchs_ajout->clear();
        ui->moy_buts_ajout->clear();
        ui->buteur_ajout->clear();
        ui->Classe_ajout->clear();
        ui->valeurmarchande->clear();
        joueursModel->removeRows(0, joueursModel->rowCount());
    }
}

void equipe_window::on_Valider_supprimer_clicked() {
    if (!ge) return;

    QString searchText = ui->recherche->text().trimmed();
    if (searchText.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID ou un nom d'équipe");
        return;
    }

    if (ge->deleteEquipe(searchText)) {
        refreshTable();
        ui->recherche->clear();
        ui->valeurmarchande->clear();
        joueursModel->removeRows(0, joueursModel->rowCount());
    }
}

void equipe_window::on_recherche_textChanged(const QString &text) {
    if (!ge) return;

    refreshTable();
}

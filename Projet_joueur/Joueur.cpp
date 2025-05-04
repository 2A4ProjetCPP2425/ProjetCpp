#include "player.h"
#include "Joueur.h"
#include "ui_joueur.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QFileDialog>
#include <QString>
#include <QVector>
#include <QPair>
#include <QPrinter>
#include <QPainter>
#include <QDebug>
#include <QSqlError>
#include "arduinomanager.h"

joueur::joueur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::joueur),
    model(new QSqlQueryModel())
{
    ui->setupUi(this);
    AfficherListeJoueurs();
    connect(ui->exportPdfButton, &QPushButton::clicked, this, &joueur::on_exportPdfButton_clicked);

    // Connect ArduinoManager signal
    ArduinoManager *arduinoManager = parent->findChild<ArduinoManager*>();
    if (arduinoManager) {
        connect(arduinoManager, &ArduinoManager::rfidStatusChanged, this, &joueur::updateRfidStatus);
    } else {
        ui->label_rfid_status->setText("Error: ArduinoManager not found");
    }

    // Set initial text and font for label_rfid_status
    ui->label_rfid_status->setText("RFID Status: Waiting for scan...");
    QFont labelFont("Arial", 12, QFont::Normal); // Set font size to 12
    ui->label_rfid_status->setFont(labelFont);

    // Remplir les LineEdits pour chaque tour
    // Round of 16 (16)
    updateBestPlayers(16, "GARDIEN", ui->bestG_inR16);
    updateBestPlayers(16, "DEFENSEUR", ui->bestD_inR16);
    updateBestPlayers(16, "MILIEU", ui->bestM_inR16);
    updateBestPlayers(16, "ATTAQUANT", ui->bestS_inR16);

    // Quarter-finals (8)
    updateBestPlayers(8, "GARDIEN", ui->bestG_inR8);
    updateBestPlayers(8, "DEFENSEUR", ui->bestD_inR8);
    updateBestPlayers(8, "MILIEU", ui->bestM_inR8);
    updateBestPlayers(8, "ATTAQUANT", ui->bestS_inR8);

    // Semi-finals (2)
    updateBestPlayers(2, "GARDIEN", ui->bestG_inR2);
    updateBestPlayers(2, "DEFENSEUR", ui->bestD_inR2);
    updateBestPlayers(2, "MILIEU", ui->bestM_inR2);
    updateBestPlayers(2, "ATTAQUANT", ui->bestS_inR2);

    // Final (1)
    updateBestPlayers(1, "GARDIEN", ui->bestG_inF);
    updateBestPlayers(1, "DEFENSEUR", ui->bestD_inF);
    updateBestPlayers(1, "MILIEU", ui->bestM_inF);
    updateBestPlayers(1, "ATTAQUANT", ui->bestS_inF);
}

joueur::~joueur()
{
    delete ui;
    delete model;
}

void joueur::updateRfidStatus(const QString &message)
{
    static QStringList currentScanMessages;

    // Detect start of a new scan
    if (message.startsWith("Received UID: ")) {
        currentScanMessages.clear();
        currentScanMessages.append(message);
        ui->label_rfid_status->setText(message); // Show UID immediately
    }
    // Append messages for the current scan
    else if (!currentScanMessages.isEmpty()) {
        currentScanMessages.append(message);
        ui->label_rfid_status->setText(currentScanMessages.join("\n"));
    }

    // Reset to initial state after scan completes
    if (message.startsWith("Sent: ")) {
        currentScanMessages.clear();
    }
}

void joueur::on_button_ajout_clicked()
{
    bool ok;
    int id = ui->ID_joueur2->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "ID invalide. Veuillez entrer un entier.");
        return;
    }

    QString nom = ui->Nom2->text().trimmed();
    QString prenom = ui->Prenom2->text().trimmed();
    QString equipe = ui->Equipe_Actuelle2->text().trimmed();
    QString nationalite = ui->Nationalite2->text().trimmed();
    QString poste = ui->Poste2->text().trimmed().toLower();
    int age = ui->Age2->text().toInt(&ok);

    // Vérification des champs vides
    if (nom.isEmpty() || prenom.isEmpty() || equipe.isEmpty() || nationalite.isEmpty() || poste.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
        return;
    }

    // Vérification de l'âge
    if (!ok || age <= 0) {
        QMessageBox::warning(this, "Erreur", "Âge invalide. Veuillez entrer un entier positif.");
        return;
    }

    // Vérification du poste
    QStringList postesValides = {"attaquant", "milieu", "defenseur", "gardien"};
    if (!postesValides.contains(poste, Qt::CaseInsensitive)) {
        QMessageBox::warning(this, "Erreur", "Poste invalide. Choisissez entre attaquant, milieu, defenseur ou gardien.");
        return;
    }

    Player newPlayer(id, nom, prenom, age, poste, equipe, nationalite);

    if (newPlayer.ajouter()) {
        QMessageBox::information(this, "Succès", "Joueur ajouté !");
        AfficherListeJoueurs(); // Rafraîchir la table après l'ajout
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout");
    }
}

void joueur::AfficherListeJoueurs()
{
    model->setQuery("SELECT ID_JOUEUR, NOM, PRENOM, POSTE FROM JOUEUR ORDER BY POSTE ASC, NOM ASC;");
    ui->tableView->setModel(model);
}

void joueur::on_valider_recherche_clicked()
{
    int id = ui->Recherche->text().toInt();
    QSqlQuery query;
    query.prepare("SELECT * FROM JOUEUR WHERE ID_JOUEUR = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        // Existing fields
        ui->ID_joueur->setText(query.value("ID_JOUEUR").toString());
        ui->Nationalite->setText(query.value("NATIONALITE").toString());
        ui->Nom->setText(query.value("NOM").toString());
        ui->Prenom->setText(query.value("PRENOM").toString());
        ui->Poste->setText(query.value("POSTE").toString());
        ui->Age->setText(query.value("AGE").toString());
        ui->equipe_actuelle->setText(query.value("EQUIPE_ACTUEL").toString());

        ui->Equipe_Actuelle->setText(query.value("EQUIPE_ACTUEL").toString());
        ui->nb_cleansheet->setText(query.value("NB_CLEANSHEET").toString());
        ui->nb_passes->setText(query.value("NB_PASSES").toString());
        ui->nb_matches->setText(query.value("NB_MATCHES").toString());
        ui->nb_buts->setText(query.value("NB_BUTS").toString());
        ui->age->setText(query.value("AGE").toString());

        // Extract values for calculation
        int nb_buts = query.value("NB_BUTS").toInt();
        int nb_passes = query.value("NB_PASSES").toInt();
        int nb_cleansheet = query.value("NB_CLEANSHEET").toInt();
        int nb_matches = query.value("NB_MATCHES").toInt();
        int age = query.value("AGE").toInt();
        QString poste = query.value("POSTE").toString().toUpper();

        // Calculate A1 based on position
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
            if ((poste == "GARDIEN" || poste == "GK") && (nb_buts == 0 || nb_passes == 0)) {
                double total = nb_cleansheet * cleansheet_percent;
            }

            if ((poste == "DEFENSEUR" || poste == "CB") && (nb_buts == 0 || nb_passes == 0)) {
                double total = nb_cleansheet * cleansheet_percent;
            }
        }

        // Apply age multiplier
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

        // Calculate market value
        double valeur_marchande = A1 * multiplier * 100000;
        ui->Valeur_marchande->setText(QString("$%1").arg(valeur_marchande, 0, 'f', 2));
    } else {
        QMessageBox::warning(this, "Erreur", "Joueur introuvable");
        ui->Valeur_marchande->clear();
    }
}

void joueur::on_valider_suppression_clicked()
{
    int id = ui->Recherche->text().toInt();

    if (id == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide");
        return;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM JOUEUR WHERE ID_JOUEUR = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Joueur supprimé avec succès !");
        // Optionally clear the fields after deletion
        ui->ID_joueur->clear();
        ui->Nationalite->clear();
        ui->Nom->clear();
        ui->Prenom->clear();
        ui->Poste->clear();
        ui->Equipe_Actuelle->clear();
        ui->Age->clear();
        ui->Recherche->clear();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression");
    }
}

void joueur::on_valider_modification_clicked()
{
    bool ok;
    int id = ui->Recherche->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "ID invalide");
        return;
    }

    QString equipe_actuelle = ui->equipe_actuelle->text();
    bool updateEquipe = !equipe_actuelle.isEmpty();

    int nb_matches = ui->nb_matches_2->text().toInt(&ok);
    bool updateMatches = !ui->nb_matches_2->text().isEmpty();

    int nb_buts = ui->nb_buts_2->text().toInt(&ok);
    bool updateButs = !ui->nb_buts_2->text().isEmpty();

    int nb_passes = ui->nb_passes_2->text().toInt(&ok);
    bool updatePasses = !ui->nb_passes_2->text().isEmpty();

    int nb_cleansheet = ui->nb_cleansheet_2->text().toInt(&ok);
    bool updateCleansheet = !ui->nb_cleansheet_2->text().isEmpty();

    int age = ui->age->text().toInt(&ok);
    bool updateAge = !ui->age->text().isEmpty();

    if (Etmp.modifier(id, equipe_actuelle, nb_matches, nb_buts, nb_passes, nb_cleansheet, age, updateEquipe, updateMatches, updateButs, updatePasses, updateCleansheet, updateAge)) {
        QMessageBox::information(this, "Succès", "Joueur modifié avec succès !");
        on_valider_recherche_clicked();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification");
    }
}

void joueur::on_exportPdfButton_clicked()
{
    // Verify there's data to export
    if (ui->ID_joueur->toPlainText().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Aucun joueur sélectionné!");
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "PDF Files (*.pdf)");
    if (fileName.isEmpty()) return;

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setOutputFileName(fileName);

    QPainter painter;
    if (!painter.begin(&printer)) {
        QMessageBox::warning(this, "Erreur", "Impossible de créer le PDF");
        return;
    }

    // Get data from UI
    QStringList fields = {
        "ID: " + ui->ID_joueur->toPlainText(),
        "Nom: " + ui->Nom->toPlainText(),
        "Prénom: " + ui->Prenom->toPlainText(),
        "Âge: " + ui->Age->toPlainText(),
        "Poste: " + ui->Poste->toPlainText(),
        "Équipe: " + ui->Equipe_Actuelle->toPlainText(),
        "Nationalité: " + ui->Nationalite->toPlainText(),
        "Matches joués: " + ui->nb_matches->toPlainText(),
        "Buts: " + ui->nb_buts->toPlainText(),
        "Passes: " + ui->nb_passes->toPlainText(),
        "Clean sheets: " + ui->nb_cleansheet->toPlainText()
    };

    // Configure painter
    QFont headerFont("Arial", 18, QFont::Bold);
    QFont contentFont("Arial", 12);
    painter.setFont(headerFont);

    // Calculate positions
    int margin = 50;
    int ySpacing = 40;
    int currentY = margin + 100;

    // Draw header
    painter.drawText(margin, margin + 50, "Fiche Joueur - UCL Specialists");

    // Set initial content position
    painter.setFont(contentFont);
    currentY += ySpacing * 2;  // Add space after header

    // Draw fields
    painter.setFont(contentFont);
    currentY += ySpacing;

    // Set font
    painter.setFont(QFont("Arial", 14, QFont::Bold));

    int lineSpacing = 40;  // Adjust as needed

    // Draw player information
    painter.drawText(margin, currentY + 50, "Nom: " + ui->Nom->toPlainText());
    currentY += lineSpacing;

    painter.drawText(margin, currentY + 50, "Prenom: " + ui->Prenom->toPlainText());
    currentY += lineSpacing;

    painter.drawText(margin, currentY + 50, "Nationalitè: " + ui->Nationalite->toPlainText());
    currentY += lineSpacing;

    painter.drawText(margin, currentY + 50, "Age: " + ui->Age->toPlainText());
    currentY += lineSpacing;

    painter.drawText(margin, currentY + 50, "Poste: " + ui->Poste->toPlainText());
    currentY += lineSpacing;

    painter.drawText(margin, currentY + 50, "Equipe Actuelle: " + ui->Equipe_Actuelle->toPlainText());
    currentY += lineSpacing;

    painter.drawText(margin, currentY + 50, "Valeur marchande: " + ui->Valeur_marchande->toPlainText());
    currentY += lineSpacing;

    painter.end();
    QMessageBox::information(this, "Succès", "PDF généré avec succès: " + fileName);
}

QString joueur::getPlayerName(int playerId) {
    QSqlQuery query;
    query.prepare("SELECT NOM, PRENOM FROM JOUEUR WHERE ID_JOUEUR = :id");
    query.bindValue(":id", playerId);

    if (query.exec() && query.next()) {
        return query.value(0).toString() + " " + query.value(1).toString();
    }
    return "Joueur inconnu";
}

void joueur::updateBestPlayers(int tour, const QString &poste, QLineEdit *lineEdit) {
    QSqlQuery query;
    QString posteUpper = poste.toUpper();
    lineEdit->setText("Calcul en cours...");

    try {
        if (!QSqlDatabase::database().isOpen()) {
            lineEdit->setText("DB non connectée");
            return;
        }

        QString queryString;
        if (posteUpper == "GARDIEN") {
            queryString =
                "SELECT NOM, PRENOM FROM ("
                "   SELECT j.NOM, j.PRENOM, COUNT(m.ID_EQUIPE_CLEANSHEET) AS cleansheets "
                "   FROM JOUEUR j "
                "   JOIN EQUIPE e ON j.ID_EQUIPE = e.ID_EQUIPE "
                "   JOIN MATCHES m ON e.ID_EQUIPE = m.ID_EQUIPE_CLEANSHEET "
                "   WHERE m.TOUR = :tour AND j.POSTE = 'GARDIEN' "
                "   GROUP BY j.NOM, j.PRENOM "
                "   ORDER BY cleansheets DESC "
                ") WHERE ROWNUM = 1";
        }
        else if (posteUpper == "DEFENSEUR") {
            queryString =
                "SELECT NOM, PRENOM FROM ("
                "   SELECT j.NOM, j.PRENOM, COUNT(m.ID_EQUIPE_CLEANSHEET) AS cleansheets "
                "   FROM JOUEUR j "
                "   JOIN EQUIPE e ON j.ID_EQUIPE = e.ID_EQUIPE "
                "   JOIN MATCHES m ON e.ID_EQUIPE = m.ID_EQUIPE_CLEANSHEET "
                "   WHERE m.TOUR = :tour AND j.POSTE = 'DEFENSEUR' "
                "   GROUP BY j.NOM, j.PRENOM "
                "   ORDER BY cleansheets DESC "
                ") WHERE ROWNUM = 1";
        }
        else if (posteUpper == "MILIEU") {
            queryString =
                "SELECT NOM, PRENOM FROM ("
                "   SELECT j.NOM, j.PRENOM, COUNT(m.ID_PASSEURS) AS passes "
                "   FROM JOUEUR j "
                "   JOIN MATCHES m ON j.ID_JOUEUR = m.ID_PASSEURS "
                "   WHERE m.TOUR = :tour "
                "   GROUP BY j.NOM, j.PRENOM "
                "   ORDER BY passes DESC "
                ") WHERE ROWNUM = 1";
        }
        else if (posteUpper == "ATTAQUANT") {
            queryString =
                "SELECT NOM, PRENOM FROM ("
                "   SELECT j.NOM, j.PRENOM, COUNT(m.ID_BUTTEURS) AS buts "
                "   FROM JOUEUR j "
                "   JOIN MATCHES m ON j.ID_JOUEUR = m.ID_BUTTEURS "
                "   WHERE m.TOUR = :tour "
                "   GROUP BY j.NOM, j.PRENOM "
                "   ORDER BY buts DESC "
                ") WHERE ROWNUM = 1";
        }
        else {
            lineEdit->setText("Poste invalide");
            return;
        }

        queryString = "SELECT * FROM (" + queryString + ") WHERE ROWNUM = 1";
        query.prepare(queryString);
        query.bindValue(":tour", tour);

        if (!query.exec()) {
            lineEdit->setText("Erreur DB: " + query.lastError().text());
            qDebug() << "Erreur SQL:" << query.lastError().text();
            qDebug() << "Requête:" << query.lastQuery();
            return;
        }

        if (query.next()) {
            lineEdit->setText(query.value(0).toString() + " " + query.value(1).toString());
        } else {
            lineEdit->setText("Aucun joueur trouvé");
        }
    } catch (const std::exception& e) {
        lineEdit->setText("Erreur système");
        qDebug() << "Exception:" << e.what();
    }
}

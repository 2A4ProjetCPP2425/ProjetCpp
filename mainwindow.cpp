#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stade.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>


#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QAuthenticator>
#include <QEventLoop>
#include <QDebug>
#include <QNetworkRequest>
#include <QTextEdit>
#include <QCalendarWidget>



#include <QFile>
#include <QPdfWriter>
#include <QFileDialog>
#include <QMessageBox>
#include <QPrinter>
#include <QTextDocument>
#include <QDateTime>

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QVBoxLayout>
#include <QStyledItemDelegate>
Stade stade;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    ui->tableViewStade->setModel(stade.afficher());
    // After setting model:
    ui->tableViewStade->setIconSize(QSize(32, 32));
    ui->tableViewStade->verticalHeader()->setDefaultSectionSize(40);


    // Force Qt to recognize icons
    ui->tableViewStade->setItemDelegate(new QStyledItemDelegate());
    ui->tableViewStade->viewport()->update();  // Immediate refresh

    // Force immediate update
    ui->tableViewStade->viewport()->update();
    connect(ui->lineEdit_6, &QLineEdit::textChanged, this, &MainWindow::on_lineEdit_6_textChanged);

    // Initialize statut combo box items
    ui->comboBox_statut->addItems({"Ouvert", "Ferme",  "Maintenance"});
    displayStadiumLocationStats();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_button_clicked()
{
    // Get values from UI
    QString nomStade = ui->lineEdit_nomStade->text();
    QString capaciteStr = ui->lineEdit_capacite->text();
    QString localisation = ui->lineEdit_localisation->text();
    QString statut = ui->comboBox_statut->currentText();

    // Validate fields
    if (nomStade.isEmpty() || capaciteStr.isEmpty() || localisation.isEmpty()) {
        QMessageBox::warning(this, "Champ(s) manquant(s)", "Veuillez remplir tous les champs correctement.");
        return;
    }

    // Validate capacity
    bool capaciteOk;
    int capacite = capaciteStr.toInt(&capaciteOk);
    if (!capaciteOk || capacite <= 0) {
        QMessageBox::warning(this, "Entrée invalide", "Veuillez entrer un nombre entier valide pour la capacité.");
        return;
    }

    qDebug() << "Nom du Stade:" << nomStade;
    qDebug() << "Capacité:" << capacite;
    qDebug() << "Localisation:" << localisation;
    qDebug() << "Statut:" << statut;

    // Create Stade instance
    Stade stade(nomStade, capacite, localisation, statut);

    // Add to database
    bool success = stade.ajouter();

    if (success) {
        displayStadiumLocationStats();
        QMessageBox::information(this, "Succès", "Le stade a été ajouté avec succès.");

        // Clear fields
        ui->lineEdit_nomStade->clear();
        ui->lineEdit_capacite->clear();
        ui->lineEdit_localisation->clear();

        // Refresh table
        ui->tableViewStade->setModel(stade.afficher());
    } else {
        QMessageBox::critical(this, "Erreur", "Une erreur est survenue lors de l'ajout du stade.");
    }
}

void MainWindow::on_modifStadeButton_clicked()
{
    bool ok;
    int id = ui->idStade->text().toInt(&ok);
    if (!ok || id <= 0) {
        QMessageBox::critical(this, "Erreur", "ID de stade invalide.");
        return;
    }

    // Get values from UI
    QString nomStade = ui->lineEdit_nomStade->text();
    QString capaciteStr = ui->lineEdit_capacite->text();
    QString localisation = ui->lineEdit_localisation->text();
    QString statut = ui->comboBox_statut->currentText();

    // Validate fields
    if (nomStade.isEmpty() || capaciteStr.isEmpty() || localisation.isEmpty()) {
        QMessageBox::warning(this, "Champ(s) manquant(s)", "Veuillez remplir tous les champs correctement.");
        return;
    }

    // Validate capacity
    bool capaciteOk;
    int capacite = capaciteStr.toInt(&capaciteOk);
    if (!capaciteOk || capacite <= 0) {
        QMessageBox::warning(this, "Entrée invalide", "Veuillez entrer un nombre entier valide pour la capacité.");
        return;
    }

    // Create Stade instance
    Stade stade(id, nomStade, capacite, localisation, statut);

    // Update in database
    bool success = stade.modifier(id);

    if (success) {
        displayStadiumLocationStats();
        sendStatusChangeSMS(nomStade, statut);
        // Refresh table
        ui->tableViewStade->setModel(stade.afficher());

        // Clear fields
        ui->lineEdit_nomStade->clear();
        ui->lineEdit_capacite->clear();
        ui->lineEdit_localisation->clear();
        ui->idStade->clear();

        QMessageBox::information(this, "Modification réussie", "Stade modifié avec succès.");
    } else {
        QMessageBox::critical(this, "Erreur", "Une erreur est survenue lors de la modification du stade.");
    }
}

void MainWindow::on_DeleteStadeButton_clicked()
{
    QModelIndexList selectedIndexes = ui->tableViewStade->selectionModel()->selectedIndexes();

    if (!selectedIndexes.isEmpty()) {
        int id = selectedIndexes.at(0).sibling(selectedIndexes.at(0).row(), 0).data().toInt();

        bool supprime = stade.supprimer(id);

        if (supprime) {
            displayStadiumLocationStats();
            ui->tableViewStade->setModel(stade.afficher());
            QMessageBox::information(this, "Suppression réussie", "Stade supprimé avec succès.");
        } else {
            QMessageBox::warning(this, "Échec de la suppression", "Échec de la suppression du stade.");
        }
    } else {
        QMessageBox::warning(this, "Aucun stade sélectionné", "Veuillez sélectionner un stade à supprimer.");
    }
}

void MainWindow::on_tableViewStade_doubleClicked(const QModelIndex &index)
{
    int row = index.row();

    // Get data from selected row
    int id = ui->tableViewStade->model()->data(ui->tableViewStade->model()->index(row, 0)).toInt();
    QString nomStade = ui->tableViewStade->model()->data(ui->tableViewStade->model()->index(row, 1)).toString();
    int capacite = ui->tableViewStade->model()->data(ui->tableViewStade->model()->index(row, 2)).toInt();
    QString localisation = ui->tableViewStade->model()->data(ui->tableViewStade->model()->index(row, 3)).toString();
    QString statut = ui->tableViewStade->model()->data(ui->tableViewStade->model()->index(row, 4)).toString();

    // Set data in UI elements
    ui->idStade->setText(QString::number(id));
    ui->lineEdit_nomStade->setText(nomStade);
    ui->lineEdit_capacite->setText(QString::number(capacite));
    ui->lineEdit_localisation->setText(localisation);
    ui->comboBox_statut->setCurrentText(statut);
}


void MainWindow::on_lineEdit_6_textChanged(const QString &arg1)
{
    // Call the rechercherParNom method
    QSqlQueryModel* model = stade.rechercherParNom(arg1);

    // Set the model for the QTableView
    ui->tableViewStade->setModel(model);


}


void MainWindow::on_trier_Button_clicked()
{
    QString champ = "capacite";
    QString order = "asc";       // Default sort order

    // Update the sort order based on the combo box selection
    if (ui->comboBox_order->currentText().compare("Descendant", Qt::CaseInsensitive) == 0) {
        order = "desc";
    }

    qDebug() << "Order:" << order;
    qDebug() << "Champ:" << champ;

    // Set the model to the QTableView
    ui->tableViewStade->setModel(stade.Tri(order, champ));
}



bool MainWindow::sendStatusChangeSMS(const QString& stadeName, const QString& newStatus)
{
    // Twilio credentials
    const QString TWILIO_ACCOUNT_SID = "ACc10213c099c0fe4b9299f547b9edcffe";
    const QString TWILIO_AUTH_TOKEN = "fe0dd01ff3dfe98a0391ff76e07a2bc9";
    const QString TWILIO_PHONE_NUMBER = "++14632836838";
    const QString TO_PHONE_NUMBER = "+21658640880";

    // Create message content
    QString message = QString("Stadium Status Update: %1 status has changed to %2").arg(stadeName).arg(newStatus);

    // Create URL for Twilio API
    QString urlStr = QString("https://api.twilio.com/2010-04-01/Accounts/%1/Messages.json").arg(TWILIO_ACCOUNT_SID);
    QUrl url(urlStr);

    // Set up network request
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request;
    request.setUrl(url);

    // Set basic authentication header
    QString concatenated = TWILIO_ACCOUNT_SID + ":" + TWILIO_AUTH_TOKEN;
    QByteArray data = concatenated.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader("Authorization", headerData.toLocal8Bit());
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    // Create form data
    QByteArray postData;
    postData.append("From=" + QUrl::toPercentEncoding(TWILIO_PHONE_NUMBER));
    postData.append("&To=" + QUrl::toPercentEncoding(TO_PHONE_NUMBER));
    postData.append("&Body=" + QUrl::toPercentEncoding(message));

    // Send POST request
    QNetworkReply *reply = manager->post(request, postData);

    // Wait for the reply
    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    // Process reply
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        qDebug() << "SMS sent successfully:" << responseData;
        reply->deleteLater();
        return true;
    } else {
        qDebug() << "Failed to send SMS:" << reply->errorString();
        reply->deleteLater();
        return false;
    }
}

void MainWindow::on_pushButton_clicked()
{

    // Ask user where to save PDF
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");

    if (fileName.isEmpty())
        return;

    // Ensure .pdf extension
    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive))
        fileName += ".pdf";

    // Create printer
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize(QPageSize::A4));

    // Create HTML content
    QTextDocument doc;
    QString html = "<h1 align='center'>Liste des Stades</h1>";
    html += "<p align='center'>Date: " + QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss") + "</p>";
    html += "<table border='1' cellspacing='0' cellpadding='3' width='100%'>";

    // Add table headers (modified for Stade attributes)
    html += "<tr bgcolor='#eeeeee'>";
    html += "<th>ID</th>";
    html += "<th>Nom du Stade</th>";
    html += "<th>Capacité</th>";
    html += "<th>Localisation</th>";
    html += "<th>Statut</th>";
    html += "</tr>";

    // Get data from your table view (assuming QTableView)
    QTableView* tableView = ui->tableViewStade; // Match your UI component name

    if (tableView->model()->rowCount() == 0) {
        QMessageBox::warning(this, "Erreur", "Aucun stade à exporter");
        return;
    }

    // Read data from model
    QAbstractItemModel* model = tableView->model();
    for (int row = 0; row < model->rowCount(); ++row) {
        html += "<tr>";
        for (int col = 0; col < model->columnCount(); ++col) {
            QString cellText = model->data(model->index(row, col)).toString();
            html += "<td>" + cellText + "</td>";
        }
        html += "</tr>";
    }

    html += "</table>";
    html += "<p align='right'><i>Document généré par le système de gestion des stades</i></p>";

    // Set HTML and print to PDF
    doc.setHtml(html);
    doc.print(&printer);

    QMessageBox::information(this, "PDF Exporté",
                             "La liste des stades a été exportée avec succès.\n" + fileName);
}

void MainWindow::displayStadiumLocationStats()
{
    // Get the statistics data
    Stade stade;
    QMap<QString, int> locationStats = stade.getStadiumsPerLocation();

    // Clear the frame layout if it exists
    if (ui->frame->layout()) {
        QLayoutItem* item;
        while ((item = ui->frame->layout()->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete ui->frame->layout();
    }

    // Create a new vertical layout for the frame
    QVBoxLayout* layout = new QVBoxLayout(ui->frame);

    // Create a chart view
    QChartView* chartView = new QChartView(ui->frame);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Create a chart
    QChart* chart = new QChart();
    chart->setTitle("Stadiums Per Location");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Create a bar series
    QBarSeries* series = new QBarSeries();

    // Create a category axis for locations
    QBarCategoryAxis* axisX = new QBarCategoryAxis();
    QStringList categories;

    // Create a bar set from the data
    QBarSet* barSet = new QBarSet("Number of Stadiums");

    // Add data to the bar set
    QMapIterator<QString, int> i(locationStats);
    while (i.hasNext()) {
        i.next();
        categories << i.key();
        *barSet << i.value();
    }

    // Add the bar set to the series
    series->append(barSet);

    // Add the series to the chart
    chart->addSeries(series);

    // Set up the axes
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis* axisY = new QValueAxis();
    axisY->setRange(0, barSet->at(barSet->count() - 1) + 1);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Set the chart on the chart view
    chartView->setChart(chart);

    // Add the chart view to the layout
    layout->addWidget(chartView);

    // Set the layout on the frame
    ui->frame->setLayout(layout);
}


void MainWindow::on_tableViewStade_clicked(const QModelIndex &index)
{
    // Check if the clicked cell is in the calendar column (column 5)
    if (index.column() == 5) {
        int row = index.row();
        int stadeId = ui->tableViewStade->model()->data(ui->tableViewStade->model()->index(row, 0)).toInt();

        // Create a calendar dialog
        QDialog *calendarDialog = new QDialog(this);
        calendarDialog->setWindowTitle("Matches au stade");
        calendarDialog->setMinimumSize(600, 400);

        QVBoxLayout *layout = new QVBoxLayout(calendarDialog);

        // Get stadium name for display
        QString stadeName = ui->tableViewStade->model()->data(ui->tableViewStade->model()->index(row, 1)).toString();
        QLabel *titleLabel = new QLabel("Calendrier des matches pour " + stadeName);
        titleLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(titleLabel);

        // Create calendar widget
        QCalendarWidget *calendar = new QCalendarWidget(calendarDialog);
        layout->addWidget(calendar);

        // Get match dates from database for this stadium
        QSqlQuery query;
        query.prepare("SELECT DATE_MATCH FROM matche WHERE id_stade = :id_stade");
        query.bindValue(":id_stade", stadeId);

        // Store all match dates
        QList<QDate> matchDates;

        if (query.exec()) {
            while (query.next()) {
                QDate matchDate = query.value("DATE_MATCH").toDate();
                matchDates.append(matchDate);
            }
        } else {
            qDebug() << "Error fetching match dates:" << query.lastError().text();
        }

        // Set up calendar formatting for dates with matches
        QTextCharFormat matchFormat;
        matchFormat.setBackground(QBrush(QColor(0, 128, 255, 100))); // Light blue background
        matchFormat.setForeground(QBrush(Qt::darkBlue));             // Dark blue text
        matchFormat.setFontWeight(QFont::Bold);

        // Apply formatting to dates with matches
        for (const QDate &date : matchDates) {
            calendar->setDateTextFormat(date, matchFormat);
        }

        // Add labels showing match info when a date is clicked
        QLabel *matchInfoLabel = new QLabel("Cliquez sur une date pour voir les détails des matches");
        matchInfoLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(matchInfoLabel);

        QTextEdit *matchDetailsText = new QTextEdit();
        matchDetailsText->setReadOnly(true);
        matchDetailsText->setMaximumHeight(150);
        layout->addWidget(matchDetailsText);

        // Connect date selection to show match details
        connect(calendar, &QCalendarWidget::clicked, [=](const QDate &date) {
            QSqlQuery detailsQuery;
            QString dateStr = date.toString("yyyy-MM-dd");

            // Oracle-specific date handling
            detailsQuery.prepare("SELECT ID_MATCH, DATE_MATCH, EQUIPE1, EQUIPE2 FROM matche "
                                 "WHERE id_stade = :id_stade AND TRUNC(DATE_MATCH) = TO_DATE(:date_match, 'YYYY-MM-DD')");
            detailsQuery.bindValue(":id_stade", stadeId);
            detailsQuery.bindValue(":date_match", dateStr);

            QString details;
            if (detailsQuery.exec()) {
                bool foundMatches = false;
                details = "<b>Matches prévus le " + date.toString("dd/MM/yyyy") + ":</b><br>";

                while (detailsQuery.next()) {
                    foundMatches = true;
                    int matchId = detailsQuery.value("ID_MATCH").toInt();
                    QString equipe1 = detailsQuery.value("EQUIPE1").toString();
                    QString equipe2 = detailsQuery.value("EQUIPE2").toString();

                    details += "- Match #" + QString::number(matchId) + ": ";
                    details += equipe1 + " vs " + equipe2 + "<br>";
                }

                if (!foundMatches) {
                    details += "Aucun match prévu à cette date.";
                }
            } else {
                details = "Erreur lors de la récupération des détails du match.";
                qDebug() << "Error fetching match details:" << detailsQuery.lastError().text();
            }

            matchDetailsText->setHtml(details);
        });

        // Add a close button
        QPushButton *closeButton = new QPushButton("Fermer");
        layout->addWidget(closeButton);
        connect(closeButton, &QPushButton::clicked, calendarDialog, &QDialog::accept);

        // Show dialog
        calendarDialog->exec();
        delete calendarDialog; // Clean up after dialog is closed
    }
}


#include "G_Tours.h"
#include "qsqlerror.h"
#include "ui_G_Tours.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSettings>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QSqlError>

G_Tours::G_Tours(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::G_Tours)
{
    ui->setupUi(this);

    // Create button group for rating
    ratingButtons = new QButtonGroup(this);
    ratingButtons->addButton(ui->radioButton, 1);
    ratingButtons->addButton(ui->radioButton_2, 2);
    ratingButtons->addButton(ui->radioButton_3, 3);
    ratingButtons->addButton(ui->radioButton_4, 4);
    ratingButtons->addButton(ui->radioButton_5, 5);

    // Connect submit button
    connect(ui->pushButton_2, &QPushButton::clicked, this, &G_Tours::submitRating);

    // Initial load
    populateTourComboBox(); // Only for comboBox_3 (TOUR_ID)
    updateTopRatedTours();

    ui->linetourname_5->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->linetourname_5->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->linetourname_5->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->linetourname_5->setFocusPolicy(Qt::NoFocus);

    // Set the column count and headers for the table (removed Level)
    ui->linetourname_5->setColumnCount(8);
    QStringList headers = {"Tour ID", "Tour Name", "Rounds", "Start Date", "End Date", "Description", "Status", "Rating"};
    ui->linetourname_5->setHorizontalHeaderLabels(headers);

    // Load existing data into the table
    loadDataToTable();
}

G_Tours::~G_Tours()
{
    QSqlDatabase::database().close(); // Ensure the database connection is closed
    delete ui;
}

void G_Tours::on_pushButton1_clicked()
{
    // Check if database is open
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Error", "Database connection is not open.");
        return;
    }

    // Retrieve input values from UI
    QString rounds = ui->comboBox_2->currentText();
    QString startDate = ui->dateEdit->date().toString("yyyy-MM-dd"); // Keep as ISO format for TO_DATE
    QString endDate = ui->dateEdit_2->date().toString("yyyy-MM-dd"); // Keep as ISO format for TO_DATE
    QString tourName = ui->linetourname->text();
    QString description = ui->textEdit->toPlainText();
    QString status = ui->comboBox_7->currentText();
    QString rating = "0"; // Default rating

    // Check if any of the fields are empty
    if (tourName.isEmpty() || rounds.isEmpty() || startDate.isEmpty() || endDate.isEmpty() || description.isEmpty() || status.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "All fields must be filled out.");
        return;
    }

    // Prepare SQL query for insertion with TO_DATE
    QSqlQuery query;
    query.prepare("INSERT INTO HEDI.TOURR (TOUR_NAME, ROUNDS, START_DATE, END_DATE, TOUR_DESCRIPTION, STATUS, RATING) "
                  "VALUES (:tour_name, :rounds, TO_DATE(:start_date, 'YYYY-MM-DD'), TO_DATE(:end_date, 'YYYY-MM-DD'), :tour_description, :status, :rating)");

    // Bind values to query
    query.bindValue(":tour_name", tourName);
    query.bindValue(":rounds", rounds);
    query.bindValue(":start_date", startDate);
    query.bindValue(":end_date", endDate);
    query.bindValue(":tour_description", description);
    query.bindValue(":status", status);
    query.bindValue(":rating", rating);

    // Execute query and handle result
    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to add tour: " + query.lastError().text());
        return;
    }

    QMessageBox::information(this, "Success", "Tour added successfully");

    // Add the tour directly to the QTableWidget
    int row = ui->linetourname_5->rowCount();
    ui->linetourname_5->insertRow(row);

    ui->linetourname_5->setItem(row, 0, new QTableWidgetItem("")); // Leave tour ID blank for now
    ui->linetourname_5->setItem(row, 1, new QTableWidgetItem(tourName));
    ui->linetourname_5->setItem(row, 2, new QTableWidgetItem(rounds));
    ui->linetourname_5->setItem(row, 3, new QTableWidgetItem(startDate));
    ui->linetourname_5->setItem(row, 4, new QTableWidgetItem(endDate));
    ui->linetourname_5->setItem(row, 5, new QTableWidgetItem(description));
    ui->linetourname_5->setItem(row, 6, new QTableWidgetItem(status));
    ui->linetourname_5->setItem(row, 7, new QTableWidgetItem(rating));

    // Reload data from database to refresh the table
    loadDataToTable();
}
void G_Tours::loadDataToTable()
{
    // Check if database is open
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Error", "Database connection is not open.");
        return;
    }

    // Clear existing data in the table
    ui->linetourname_5->clearContents();
    ui->linetourname_5->setRowCount(0);

    // Create a query to get the data from the database (removed TOUR_LEVEL)
    QSqlQuery query("SELECT TOUR_ID, TOUR_NAME, ROUNDS, START_DATE, END_DATE, TOUR_DESCRIPTION, STATUS, RATING FROM HEDI.TOURR");

    // Loop through the query results
    while (query.next()) {
        QString tourId = query.value(0).toString();
        QString tourName = query.value(1).toString();
        QString rounds = query.value(2).toString();
        QString startDate = query.value(3).toString();
        QString endDate = query.value(4).toString();
        QString description = query.value(5).toString();
        QString status = query.value(6).toString();
        QString rating = query.value(7).toString();

        int row = ui->linetourname_5->rowCount();
        ui->linetourname_5->insertRow(row);

        ui->linetourname_5->setItem(row, 0, new QTableWidgetItem(tourId));
        ui->linetourname_5->setItem(row, 1, new QTableWidgetItem(tourName));
        ui->linetourname_5->setItem(row, 2, new QTableWidgetItem(rounds));
        ui->linetourname_5->setItem(row, 3, new QTableWidgetItem(startDate));
        ui->linetourname_5->setItem(row, 4, new QTableWidgetItem(endDate));
        ui->linetourname_5->setItem(row, 5, new QTableWidgetItem(description));
        ui->linetourname_5->setItem(row, 6, new QTableWidgetItem(status));
        ui->linetourname_5->setItem(row, 7, new QTableWidgetItem(rating));
    }
    populateTourComboBox();
}

void G_Tours::on_pushButton_3_clicked()
{
    // Check if database is open
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Error", "Database connection is not open.");
        return;
    }

    int selectedRow = ui->linetourname_5->currentRow();

    if (selectedRow < 0) {
        QMessageBox::warning(this, "No Selection", "Please select a row to delete.");
        return;
    }

    QString tourId = ui->linetourname_5->item(selectedRow, 0)->text();

    QMessageBox::StandardButton confirm = QMessageBox::question(this, "Confirm Delete",
                                                                "Are you sure you want to delete the selected tour?",
                                                                QMessageBox::Yes | QMessageBox::No);
    if (confirm == QMessageBox::Yes) {
        QSqlQuery query;
        query.prepare("DELETE FROM HEDI.TOURR WHERE TOUR_ID = :id");
        query.bindValue(":id", tourId);

        if (!query.exec()) {
            QMessageBox::critical(this, "Error", "Failed to delete tour: " + query.lastError().text());
        } else {
            ui->linetourname_5->removeRow(selectedRow);
            QMessageBox::information(this, "Success", "Tour deleted successfully.");
        }
    }
}

void G_Tours::on_lineEdit_textChanged(const QString &arg1)
{
    // Check if database is open
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Error", "Database connection is not open.");
        return;
    }

    QString searchText = ui->lineEdit->text();
    QString queryStr;

    if (ui->radioName->isChecked()) {
        queryStr = "SELECT TOUR_ID, TOUR_NAME, ROUNDS, START_DATE, END_DATE, TOUR_DESCRIPTION, STATUS, RATING "
                   "FROM HEDI.TOURR WHERE TOUR_NAME LIKE :search";
    } else if (ui->radioRounds->isChecked()) {
        queryStr = "SELECT TOUR_ID, TOUR_NAME, ROUNDS, START_DATE, END_DATE, TOUR_DESCRIPTION, STATUS, RATING "
                   "FROM HEDI.TOURR WHERE ROUNDS LIKE :search";
    } else {
        // Since TOUR_LEVEL is removed, default to TOUR_NAME search
        queryStr = "SELECT TOUR_ID, TOUR_NAME, ROUNDS, START_DATE, END_DATE, TOUR_DESCRIPTION, STATUS, RATING "
                   "FROM HEDI.TOURR WHERE TOUR_NAME LIKE :search";
    }

    QSqlQuery query;
    query.prepare(queryStr);
    query.bindValue(":search", "%" + searchText + "%");

    if (!query.exec()) {
        QMessageBox::critical(this, "Search Error", "Failed to search: " + query.lastError().text());
        return;
    }

    ui->linetourname_5->setRowCount(0);

    while (query.next()) {
        int row = ui->linetourname_5->rowCount();
        ui->linetourname_5->insertRow(row);

        ui->linetourname_5->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->linetourname_5->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->linetourname_5->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->linetourname_5->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
        ui->linetourname_5->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));
        ui->linetourname_5->setItem(row, 5, new QTableWidgetItem(query.value(5).toString()));
        ui->linetourname_5->setItem(row, 6, new QTableWidgetItem(query.value(6).toString()));
        ui->linetourname_5->setItem(row, 7, new QTableWidgetItem(query.value(7).toString()));
    }
}

void G_Tours::on_pushButton_exportPDF_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "*.pdf");
    if (fileName.isEmpty())
        return;

    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive)) {
        fileName += ".pdf";
    }

    QPdfWriter writer(fileName);
    writer.setPageSize(QPageSize::A2);
    writer.setResolution(300);

    QPainter painter(&writer);
    if (!painter.isActive()) {
        QMessageBox::warning(this, "Erreur", "Erreur lors de la création du PDF.");
        return;
    }

    int startX = 100;
    int startY = 100;
    int rowHeight = 250;
    int colWidth = 500;

    painter.setFont(QFont("Arial", 12));
    painter.setPen(Qt::black);

    painter.setFont(QFont("Arial", 18, QFont::Bold));
    painter.drawText(200, 40, "Football Tournament Overview");

    QBrush headerBrush(Qt::green);
    painter.setBrush(headerBrush);
    for (int col = 0; col < ui->linetourname_5->columnCount(); ++col) {
        QRect headerRect(startX + col * colWidth, startY, colWidth, rowHeight);
        painter.drawRect(headerRect);
        painter.drawText(headerRect, Qt::AlignCenter, ui->linetourname_5->horizontalHeaderItem(col)->text());
    }

    QBrush oddRowBrush(Qt::white);
    QBrush evenRowBrush(QColor(200, 255, 200));

    for (int row = 0; row < ui->linetourname_5->rowCount(); ++row) {
        QBrush currentRowBrush = (row % 2 == 0) ? oddRowBrush : evenRowBrush;
        painter.setBrush(currentRowBrush);

        for (int col = 0; col < ui->linetourname_5->columnCount(); ++col) {
            QRect cellRect(startX + col * colWidth, startY + (row + 1) * rowHeight, colWidth, rowHeight);
            painter.drawRect(cellRect);

            QTableWidgetItem *item = ui->linetourname_5->item(row, col);
            QString cellText = item ? item->text() : "";
            painter.drawText(cellRect, Qt::AlignCenter, cellText);
        }
    }

    painter.end();
    QMessageBox::information(this, "Export PDF", "Le tableau a été exporté avec succès !");
}

void G_Tours::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Error", "Database connection is not open.");
        return;
    }

    auto countToursByStatus = [](const QString &status) {
        QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM HEDI.TOURR WHERE LOWER(STATUS) = :status");
        query.bindValue(":status", status.toLower());
        if (!query.exec()) {
            qDebug() << "Query error for status" << status << ":" << query.lastError().text();
            return -1;
        }
        if (query.next())
            return query.value(0).toInt();
        return 0;
    };

    int activeCount = countToursByStatus("active");
    int nonActiveCount = countToursByStatus("non active");

    ui->lcdActive->display(activeCount);
    ui->lcdNonActive->display(nonActiveCount);
}

void G_Tours::populateTourComboBox() {
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Error", "Database connection is not open.");
        return;
    }

    // Populate comboBox_3 with TOUR_IDs only
    ui->comboBox_3->clear();
    QSqlQuery idQuery("SELECT TOUR_ID FROM HEDI.TOURR");
    while (idQuery.next()) {
        ui->comboBox_3->addItem(idQuery.value(0).toString());
    }
}

void G_Tours::submitRating() {
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Error", "Database connection is not open.");
        return;
    }

    int selectedRating = ratingButtons->checkedId();
    QString selectedTourId;

    if (ui->comboBox_3->currentIndex() != -1) {
        selectedTourId = ui->comboBox_3->currentText(); // Assuming comboBox_3 has TOUR_ID
    } else {
        int selectedRow = ui->linetourname_5->currentRow();
        if (selectedRow >= 0)
            selectedTourId = ui->linetourname_5->item(selectedRow, 0)->text();
    }

    if (selectedTourId.isEmpty() || selectedRating < 1 || selectedRating > 5) {
        QMessageBox::warning(this, "Input Error", "Please select a tour and rating before submitting.");
        return;
    }

    QSqlQuery query;
    query.prepare("UPDATE HEDI.TOURR SET RATING = :rating WHERE TOUR_ID = :tour_id");
    query.bindValue(":tour_id", selectedTourId);
    query.bindValue(":rating", QString::number(selectedRating));

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", "Failed to submit rating: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Success", "Rating submitted successfully.");
        updateTopRatedTours();
    }
}

void G_Tours::updateTopRatedTours()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Error", "Database connection is not open.");
        return;
    }

    QSqlQuery query;
    query.prepare(R"(
        SELECT TOUR_ID, TOUR_NAME, RATING
        FROM (
            SELECT TOUR_ID, TOUR_NAME, RATING
            FROM HEDI.TOURR
            WHERE RATING IS NOT NULL AND TO_NUMBER(RATING) > 0
            ORDER BY TO_NUMBER(RATING) DESC
        )
        WHERE ROWNUM <= 5
    )");

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Query failed: " + query.lastError().text());
        return;
    }

    if (query.size() == 0) {
        QMessageBox::information(this, "No Results", "No top-rated tours found.");
        return;
    }

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // Tour ID
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // Tour Name
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // Rating
        row++;
    }
}

void G_Tours::on_pushButton_4_clicked()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Error", "Database connection is not open.");
        return;
    }

    int selectedRow = ui->linetourname_5->currentRow();
    if (selectedRow < 0) {
        QMessageBox::warning(this, "No Selection", "Please select a row to update.");
        return;
    }

    QString tourId = ui->linetourname_5->item(selectedRow, 0)->text();

    QString tourName = ui->linetourname->text();
    QString rounds = ui->comboBox_2->currentText();
    QString startDate = ui->dateEdit->date().toString("yyyy-MM-dd");
    QString endDate = ui->dateEdit_2->date().toString("yyyy-MM-dd");
    QString description = ui->textEdit->toPlainText();
    QString status = ui->comboBox_7->currentText();

    if (tourName.isEmpty() || rounds.isEmpty() || startDate.isEmpty() || endDate.isEmpty() || description.isEmpty() || status.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill out all fields before updating.");
        return;
    }

    QSqlQuery query;
    query.prepare("UPDATE HEDI.TOURR SET TOUR_NAME = :name, ROUNDS = :rounds, "
                  "START_DATE = :start_date, END_DATE = :end_date, TOUR_DESCRIPTION = :desc, STATUS = :status "
                  "WHERE TOUR_ID = :id");

    query.bindValue(":name", tourName);
    query.bindValue(":rounds", rounds);
    query.bindValue(":start_date", startDate);
    query.bindValue(":end_date", endDate);
    query.bindValue(":desc", description);
    query.bindValue(":status", status);
    query.bindValue(":id", tourId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Update Failed", "Could not update the record: " + query.lastError().text());
        return;
    }

    QMessageBox::information(this, "Success", "Tour updated successfully.");
    loadDataToTable();
}

void G_Tours::on_pushButton5_clicked()
{
    // Placeholder for pushButton5 functionality (not implemented in original code)
}

void G_Tours::on_btnStatistique_clicked()
{
    // Placeholder for btnStatistique functionality (not implemented in original code)
}

void G_Tours::clearForm()
{
    // Placeholder for clearForm (not implemented in original code)
}

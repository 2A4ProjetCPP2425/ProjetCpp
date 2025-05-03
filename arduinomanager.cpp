#include "arduinomanager.h"
#include <QDebug>
#include <QSerialPortInfo>
#include <QSqlError>
#include <QThread>

ArduinoManager::ArduinoManager(QObject *parent) : QObject(parent), serial(new QSerialPort(this)) {
    connect(serial, &QSerialPort::readyRead, this, &ArduinoManager::readSerial);
}

ArduinoManager::~ArduinoManager() {
    disconnectArduino();
}

bool ArduinoManager::connectArduino() {
    if (serial->isOpen()) {
        qDebug() << "Port" << serial->portName() << "is already open.";
        emit rfidStatusChanged("Port " + serial->portName() + " is already open.");
        return true;
    }

    // Search for Arduino port
    qDebug() << "Scanning available ports for Arduino...";
    emit rfidStatusChanged("Scanning available ports for Arduino...");
    QString selectedPort;
    foreach (const QSerialPortInfo &portInfo, QSerialPortInfo::availablePorts()) {
        qDebug() << "Port:" << portInfo.portName()
        << "Description:" << portInfo.description()
        << "Manufacturer:" << portInfo.manufacturer()
        << "System Location:" << portInfo.systemLocation();
        if (portInfo.description().contains("Arduino", Qt::CaseInsensitive) ||
            portInfo.manufacturer().contains("Arduino", Qt::CaseInsensitive)) {
            selectedPort = portInfo.portName();
            qDebug() << "Selected Arduino port:" << selectedPort;
            emit rfidStatusChanged("Selected Arduino port: " + selectedPort);
            break;
        }
    }

    // If no Arduino port was found, try COM6 as a fallback
    if (selectedPort.isEmpty()) {
        qDebug() << "No Arduino port found. Falling back to COM6.";
        emit rfidStatusChanged("No Arduino port found. Falling back to COM6.");
        selectedPort = "COM6";
    }

    // Set the selected port
    serial->setPortName(selectedPort);
    qDebug() << "Attempting to connect to" << selectedPort << "...";
    emit rfidStatusChanged("Attempting to connect to " + selectedPort + "...");

    // Configure serial port settings
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    // Attempt to open the port with retries
    int retries = 3;
    for (int i = 1; i <= retries; i++) {
        qDebug() << "Connection attempt" << i << "of" << retries << "...";
        emit rfidStatusChanged(QString("Connection attempt %1 of %2...").arg(i).arg(retries));
        if (serial->open(QIODevice::ReadWrite)) {
            qDebug() << "Successfully connected to Arduino on" << serial->portName();
            emit rfidStatusChanged("Successfully connected to Arduino on " + serial->portName());
            return true;
        } else {
            qDebug() << "Failed to connect to Arduino on" << serial->portName()
            << ":" << serial->errorString()
            << "(Error code:" << serial->error() << ")";
            emit rfidStatusChanged(QString("Failed to connect to Arduino on %1: %2 (Error code: %3)")
                                       .arg(serial->portName())
                                       .arg(serial->errorString())
                                       .arg(serial->error()));
            if (i < retries) {
                qDebug() << "Waiting 1 second before retrying...";
                emit rfidStatusChanged("Waiting 1 second before retrying...");
                QThread::sleep(1);
            }
        }
    }

    qDebug() << "All connection attempts failed.";
    emit rfidStatusChanged("All connection attempts failed.");
    return false;
}

void ArduinoManager::disconnectArduino() {
    if (serial->isOpen()) {
        serial->close();
        qDebug() << "Disconnected from Arduino";
        emit rfidStatusChanged("Disconnected from Arduino");
    }
}


void ArduinoManager::readSerial() {
    while (serial->canReadLine()) {
        QString uid = serial->readLine().trimmed();
        qDebug() << "Received UID:" << uid;
        emit rfidStatusChanged("Received UID: " + uid);

        if (uid == "Scan a card to see its UID...") {
            qDebug() << "Ignoring startup message";
            emit rfidStatusChanged("Ignoring startup message");
            continue;
        }

        QSqlQuery query;
        query.prepare("SELECT ID_JOUEUR, NB_MATCHES FROM JOUEUR WHERE UPPER(RFID_UID) = UPPER(:uid)");
        query.bindValue(":uid", uid);
        qDebug() << "Executing query with UID:" << uid;
        if (query.exec()) {
            qDebug() << "Query executed, rows found:" << query.size();
            bool found = false;
            while (query.next()) {
                found = true;
                qDebug() << "UID found in database for ID_JOUEUR:" << query.value("ID_JOUEUR").toInt();
                emit rfidStatusChanged("UID found in database");
                int id_joueur = query.value("ID_JOUEUR").toInt();
                int current_matches = query.value("NB_MATCHES").toInt();

                QSqlQuery updateQuery;
                updateQuery.prepare("UPDATE JOUEUR SET NB_MATCHES = :matches WHERE ID_JOUEUR = :id");
                updateQuery.bindValue(":matches", current_matches + 1);
                updateQuery.bindValue(":id", id_joueur);
                if (updateQuery.exec()) {
                    qDebug() << "NB_MATCHES incremented to" << current_matches + 1 << "for ID_JOUEUR" << id_joueur;
                    emit rfidStatusChanged(QString("NB_MATCHES incremented to %1 for ID_JOUEUR %2")
                                               .arg(current_matches + 1)
                                               .arg(id_joueur));
                } else {
                    qDebug() << "Failed to increment NB_MATCHES:" << updateQuery.lastError().text();
                    emit rfidStatusChanged("Failed to increment NB_MATCHES: " + updateQuery.lastError().text());
                }
            }
            if (found) {
                serial->write("OK\n");
                serial->waitForBytesWritten(100);
                qDebug() << "Sent: OK";
                emit rfidStatusChanged("Sent: OK");
            } else {
                qDebug() << "UID not found in database";
                emit rfidStatusChanged("UID not found in database");
                serial->write("NOK\n");
                serial->waitForBytesWritten(100);
                qDebug() << "Sent: NOK";
                emit rfidStatusChanged("Sent: NOK");
            }
        } else {
            qDebug() << "Database query failed:" << query.lastError().text();
            emit rfidStatusChanged("Database query failed: " + query.lastError().text());
            serial->write("NOK\n");
            serial->waitForBytesWritten(100);
            qDebug() << "Sent: NOK due to query error";
            emit rfidStatusChanged("Sent: NOK due to query error");
        }
    }
}

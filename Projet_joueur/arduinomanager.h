#ifndef ARDUINOMANAGER_H
#define ARDUINOMANAGER_H

#include <QObject>
#include <QSerialPort>
#include <QSqlQuery>

class ArduinoManager : public QObject {
    Q_OBJECT

public:
    explicit ArduinoManager(QObject *parent = nullptr);
    ~ArduinoManager();
    bool connectArduino();
    void disconnectArduino();

signals:
    void rfidStatusChanged(const QString &message);

private slots:
    void readSerial();

private:
    QSerialPort *serial;
};

#endif // ARDUINOMANAGER_H

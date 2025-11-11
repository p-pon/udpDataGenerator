#ifndef UDPDATAGENERATOR_H
#define UDPDATAGENERATOR_H

#include <QObject>
#include <QUdpSocket>
#include <QTimer>
#include <QDateTime>
#include <QtMath>
#include <QMap>
#include <QHostAddress>

#include "datatypes.h"

class UdpDataGenerator : public QObject
{
    Q_OBJECT
public:
    explicit UdpDataGenerator(QObject *parent = nullptr);
    void start(quint16 port, int channels, int rate, int syncInterval);
    void stop();
    bool isRunning() const { return timer.isActive(); }

signals:
    void statusMessage(QString msg);

private slots:
    void sendPackets();

private:
    QUdpSocket socket;
    QTimer timer;
    quint16 udpPort = 0;
    int channelCount = 0;
    int packetsPerSecond = 0;
    int packetIntervalMs = 0;
    int syncIntervalus = 0;

    uint64_t testSyncTS = 0;
    uint64_t testBaseTime = 0;
    QMap<int, uint32_t> packetNumbers;
};

#endif // UDPDATAGENERATOR_H

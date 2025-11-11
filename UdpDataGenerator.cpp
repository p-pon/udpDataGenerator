#include "UdpDataGenerator.h"

UdpDataGenerator::UdpDataGenerator(QObject *parent)
    : QObject(parent)
{
    connect(&timer, &QTimer::timeout, this, &UdpDataGenerator::sendPackets);
}

void UdpDataGenerator::start(quint16 port, int channels, int rate, int syncInterval)
{
    udpPort = port;
    channelCount = channels;
    packetsPerSecond = rate;
    packetIntervalMs = 1000 / packetsPerSecond;
    syncIntervalus = syncInterval * 1000;
    testSyncTS = QDateTime::currentMSecsSinceEpoch() * 1000;
    testBaseTime = testSyncTS;
    packetNumbers.clear();

    timer.start(packetIntervalMs);

    emit statusMessage(QString("Started: port %1, %2 channels, %3 pkt/s")
                       .arg(port).arg(channels).arg(rate));
}

void UdpDataGenerator::stop()
{
    timer.stop();
    emit statusMessage("Stopped");
}

void UdpDataGenerator::sendPackets()
{
    uint64_t currentTime = QDateTime::currentMSecsSinceEpoch() * 1000; // μs

    if (currentTime - testBaseTime >= syncIntervalus) {
        testSyncTS = currentTime;
        testBaseTime = currentTime;
    }

    for (int channel = 0; channel < channelCount; ++channel) {
        ADC_pack_struct packet{};
        packet.number = packetNumbers[channel]++;
        packet.chan_num = channel;
        packet.TS = currentTime + channel * 10;
        packet.sync_TS = testSyncTS;
        packet.dTS = 55;

        for (int i = 0; i < BUFFER_SIZE; ++i) {
            double phase = 2.0 * M_PI * (packet.number * (BUFFER_SIZE-1) + i) / 1000.0;
            packet.adc_l[i] = static_cast<int32_t>(5000000 * sin(phase));
        }

        socket.writeDatagram(reinterpret_cast<const char*>(&packet),
                             sizeof(packet),
                             QHostAddress::LocalHost,
                             udpPort);

    }
}

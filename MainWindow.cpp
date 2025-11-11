#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&generator, &UdpDataGenerator::statusMessage, this, &MainWindow::showStatusMessage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startStopButton_clicked()
{
    if (generator.isRunning()) {
        generator.stop();
        ui->startStopButton->setText("Start");
    } else {
        quint16 port = ui->portSpinBox->value();
        int channels = ui->channelsSpinBox->value();
        int rate = ui->rateSpinBox->value();
        int sync = ui->syncIntervalSpinBox->value();

        generator.start(port, channels, rate, sync);
        ui->startStopButton->setText("Stop");
    }
}

void MainWindow::showStatusMessage(QString msg)
{
    ui->statusLabel->setText(msg);
}

/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QLabel *labelPort;
    QSpinBox *portSpinBox;
    QLabel *labelChannels;
    QSpinBox *channelsSpinBox;
    QLabel *labelRate;
    QSpinBox *rateSpinBox;
    QPushButton *startStopButton;
    QLabel *statusLabel;
    QLabel *label;
    QSpinBox *syncIntervalSpinBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(311, 197);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName("formLayout");
        labelPort = new QLabel(centralwidget);
        labelPort->setObjectName("labelPort");

        formLayout->setWidget(0, QFormLayout::LabelRole, labelPort);

        portSpinBox = new QSpinBox(centralwidget);
        portSpinBox->setObjectName("portSpinBox");
        portSpinBox->setMaximum(999999);
        portSpinBox->setValue(5000);

        formLayout->setWidget(0, QFormLayout::FieldRole, portSpinBox);

        labelChannels = new QLabel(centralwidget);
        labelChannels->setObjectName("labelChannels");

        formLayout->setWidget(1, QFormLayout::LabelRole, labelChannels);

        channelsSpinBox = new QSpinBox(centralwidget);
        channelsSpinBox->setObjectName("channelsSpinBox");
        channelsSpinBox->setValue(4);

        formLayout->setWidget(1, QFormLayout::FieldRole, channelsSpinBox);

        labelRate = new QLabel(centralwidget);
        labelRate->setObjectName("labelRate");

        formLayout->setWidget(2, QFormLayout::LabelRole, labelRate);

        rateSpinBox = new QSpinBox(centralwidget);
        rateSpinBox->setObjectName("rateSpinBox");
        rateSpinBox->setMinimum(1);
        rateSpinBox->setMaximum(999999);
        rateSpinBox->setValue(80);

        formLayout->setWidget(2, QFormLayout::FieldRole, rateSpinBox);

        startStopButton = new QPushButton(centralwidget);
        startStopButton->setObjectName("startStopButton");

        formLayout->setWidget(4, QFormLayout::LabelRole, startStopButton);

        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName("statusLabel");

        formLayout->setWidget(4, QFormLayout::FieldRole, statusLabel);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        formLayout->setWidget(3, QFormLayout::LabelRole, label);

        syncIntervalSpinBox = new QSpinBox(centralwidget);
        syncIntervalSpinBox->setObjectName("syncIntervalSpinBox");
        syncIntervalSpinBox->setMinimum(1);
        syncIntervalSpinBox->setMaximum(9999999);
        syncIntervalSpinBox->setValue(1000);

        formLayout->setWidget(3, QFormLayout::FieldRole, syncIntervalSpinBox);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 311, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "UDP Generator", nullptr));
        labelPort->setText(QCoreApplication::translate("MainWindow", "Port:", nullptr));
        labelChannels->setText(QCoreApplication::translate("MainWindow", "Channels:", nullptr));
        labelRate->setText(QCoreApplication::translate("MainWindow", "Rate (pkt/s):", nullptr));
        startStopButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        statusLabel->setText(QCoreApplication::translate("MainWindow", "Stopped", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Sync Interval (ms)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

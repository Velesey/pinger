/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave_settings;
    QAction *actionLoad_settings;
    QAction *actionQuit;
    QAction *actionLoad_settings_at_startup;
    QWidget *centralWidget;
    QPushButton *bt_go;
    QLabel *label;
    QTextBrowser *textBrowser;
    QLineEdit *lineEdit;
    QSpinBox *spinBox;
    QLabel *label_2;
    QPushButton *bt_stop;
    QCheckBox *checkBox;
    QSpinBox *spinBox_cnt;
    QLabel *label_3;
    QSpinBox *spinBox_cntFails;
    QCheckBox *checkBox_isManipulateVpn;
    QLabel *label_4;
    QLineEdit *lineEdit_vpnName;
    QLineEdit *lineEdit_vpnUser;
    QLineEdit *lineEdit_vpnPass;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *bt_connect;
    QPushButton *bt_disconnect;
    QLabel *label_8;
    QTextBrowser *textBrowser_vpn;
    QMenuBar *menuBar;
    QMenu *menuConfig;
    QMenu *menuPinger;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(527, 511);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/neutral.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionSave_settings = new QAction(MainWindow);
        actionSave_settings->setObjectName(QString::fromUtf8("actionSave_settings"));
        actionLoad_settings = new QAction(MainWindow);
        actionLoad_settings->setObjectName(QString::fromUtf8("actionLoad_settings"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionLoad_settings_at_startup = new QAction(MainWindow);
        actionLoad_settings_at_startup->setObjectName(QString::fromUtf8("actionLoad_settings_at_startup"));
        actionLoad_settings_at_startup->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        bt_go = new QPushButton(centralWidget);
        bt_go->setObjectName(QString::fromUtf8("bt_go"));
        bt_go->setGeometry(QRect(410, 0, 89, 41));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(260, 30, 141, 16));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(20, 90, 481, 111));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(260, 50, 121, 21));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(20, 50, 121, 23));
        spinBox->setReadOnly(false);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 60, 141, 16));
        bt_stop = new QPushButton(centralWidget);
        bt_stop->setObjectName(QString::fromUtf8("bt_stop"));
        bt_stop->setGeometry(QRect(410, 50, 89, 27));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(260, 0, 121, 20));
        spinBox_cnt = new QSpinBox(centralWidget);
        spinBox_cnt->setObjectName(QString::fromUtf8("spinBox_cnt"));
        spinBox_cnt->setGeometry(QRect(20, 0, 51, 23));
        spinBox_cnt->setMinimum(1);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 10, 161, 16));
        spinBox_cntFails = new QSpinBox(centralWidget);
        spinBox_cntFails->setObjectName(QString::fromUtf8("spinBox_cntFails"));
        spinBox_cntFails->setGeometry(QRect(20, 230, 41, 23));
        spinBox_cntFails->setMinimum(1);
        checkBox_isManipulateVpn = new QCheckBox(centralWidget);
        checkBox_isManipulateVpn->setObjectName(QString::fromUtf8("checkBox_isManipulateVpn"));
        checkBox_isManipulateVpn->setGeometry(QRect(20, 210, 171, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 240, 131, 16));
        lineEdit_vpnName = new QLineEdit(centralWidget);
        lineEdit_vpnName->setObjectName(QString::fromUtf8("lineEdit_vpnName"));
        lineEdit_vpnName->setGeometry(QRect(20, 260, 171, 23));
        lineEdit_vpnUser = new QLineEdit(centralWidget);
        lineEdit_vpnUser->setObjectName(QString::fromUtf8("lineEdit_vpnUser"));
        lineEdit_vpnUser->setGeometry(QRect(20, 290, 171, 23));
        lineEdit_vpnPass = new QLineEdit(centralWidget);
        lineEdit_vpnPass->setObjectName(QString::fromUtf8("lineEdit_vpnPass"));
        lineEdit_vpnPass->setGeometry(QRect(20, 320, 171, 23));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(200, 260, 131, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(200, 290, 131, 16));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(200, 320, 131, 16));
        bt_connect = new QPushButton(centralWidget);
        bt_connect->setObjectName(QString::fromUtf8("bt_connect"));
        bt_connect->setGeometry(QRect(400, 210, 89, 41));
        bt_disconnect = new QPushButton(centralWidget);
        bt_disconnect->setObjectName(QString::fromUtf8("bt_disconnect"));
        bt_disconnect->setGeometry(QRect(400, 270, 89, 41));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(390, 330, 111, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_8->setFont(font);
        textBrowser_vpn = new QTextBrowser(centralWidget);
        textBrowser_vpn->setObjectName(QString::fromUtf8("textBrowser_vpn"));
        textBrowser_vpn->setGeometry(QRect(20, 350, 481, 81));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 527, 25));
        menuConfig = new QMenu(menuBar);
        menuConfig->setObjectName(QString::fromUtf8("menuConfig"));
        menuPinger = new QMenu(menuBar);
        menuPinger->setObjectName(QString::fromUtf8("menuPinger"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuPinger->menuAction());
        menuBar->addAction(menuConfig->menuAction());
        menuConfig->addAction(actionSave_settings);
        menuConfig->addAction(actionLoad_settings);
        menuConfig->addSeparator();
        menuPinger->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Pinger", 0, QApplication::UnicodeUTF8));
        actionSave_settings->setText(QApplication::translate("MainWindow", "Save settings", 0, QApplication::UnicodeUTF8));
        actionLoad_settings->setText(QApplication::translate("MainWindow", "Load settings", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionLoad_settings_at_startup->setText(QApplication::translate("MainWindow", "load settings at startup", 0, QApplication::UnicodeUTF8));
        bt_go->setText(QApplication::translate("MainWindow", "Go", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Server IP or Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Delay (sec)", 0, QApplication::UnicodeUTF8));
        bt_stop->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("MainWindow", "Hide, not close", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Count of pings at a time", 0, QApplication::UnicodeUTF8));
        checkBox_isManipulateVpn->setText(QApplication::translate("MainWindow", "Auto reconnect to VPN", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Count of fails times", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "VPN name", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "VPN user name", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "VPN user password", 0, QApplication::UnicodeUTF8));
        bt_connect->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        bt_disconnect->setText(QApplication::translate("MainWindow", "Disconnect", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Status", 0, QApplication::UnicodeUTF8));
        menuConfig->setTitle(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        menuPinger->setTitle(QApplication::translate("MainWindow", "Pinger", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

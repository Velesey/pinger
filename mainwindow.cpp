#include "mainwindow.h"
#include "ui_mainwindow.h"


using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer;
    thread = new QThread;
    createActions();
    createTrayIcon();
    setIconNeutral();
    fileName = QApplication::applicationDirPath() + "/settings.ini";
    cntFailsPings = 0;
}

void MainWindow::createActions()
{
    minimizeAction = new QAction(tr("Mi&nimize"), this);
    connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));

    maximizeAction = new QAction(tr("Ma&ximize"), this);
    connect(maximizeAction, SIGNAL(triggered()), this, SLOT(showMaximized()));

    restoreAction = new QAction(tr("&Restore"), this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));

    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    connect(ui->bt_go, SIGNAL(clicked()), this, SLOT(bt_go_click()));

    connect(ui->bt_stop, SIGNAL(clicked()), this, SLOT(bt_stop_click()));

    connect(timer,SIGNAL(timeout()), this, SLOT(timer_overflow()));

    connect(thread,SIGNAL(started()),this,SLOT(thread_run()));

    connect(ui->actionQuit,SIGNAL(triggered()), qApp, SLOT(quit()));

    connect(ui->actionSave_settings,SIGNAL(triggered()), this,  SLOT(saveSettings()));

    connect(ui->actionLoad_settings,SIGNAL(triggered()), this,  SLOT(loadSettings()));

    connect(ui->bt_connect,SIGNAL(clicked()), this, SLOT(bt_connect_click()));

    connect(ui->bt_disconnect,SIGNAL(clicked()), this, SLOT(bt_disconnect_click()));

}

void MainWindow::createTrayIcon()
{
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(minimizeAction);
    trayIconMenu->addAction(maximizeAction);
    trayIconMenu->addAction(restoreAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->show();
}

void MainWindow::setIconBad()
{
    QIcon icon = QIcon(":/images/bad.png");
    setWindowIcon(icon);
    trayIcon->setIcon(icon);
    trayIcon->setToolTip("Status: Ping failed");
}

void MainWindow::setIconGood()
{
    QIcon icon = QIcon(":/images/good.png");
    setWindowIcon(icon);
    trayIcon->setIcon(icon);
    trayIcon->setToolTip("Status: Pinged");
}

void MainWindow::setIconNeutral()
{
    QIcon icon = QIcon(":/images/neutral.png");
    setWindowIcon(icon);
    trayIcon->setIcon(icon);
    trayIcon->setToolTip("Status: stopped");
}
void MainWindow::bt_go_click(){
    if (ui->spinBox_cnt->value() == 0)
        ui->spinBox_cnt->setValue(1);
    if(ui->lineEdit->text().length() == 0)
        ui->lineEdit->setText("localhost");

    thread->start();
    ui->lineEdit->setEnabled(false);
    ui->spinBox->setEnabled(false);
    ui->spinBox_cnt->setEnabled(false);
    ui->bt_go->setEnabled(false);

}

void MainWindow::bt_stop_click(){
    timer->stop();
    thread->exit();
    setIconNeutral();

    ui->lineEdit->setEnabled(true);
    ui->spinBox->setEnabled(true);
    ui->spinBox_cnt->setEnabled(true);
    ui->bt_go->setEnabled(true);
}

bool MainWindow::doPing(QString host){
    string s;
    int cnt = ui->spinBox_cnt->value();
#ifdef __linux__
    s = "ping " + host.toStdString() + " -c " + to_string(cnt);

#elif _WIN32
    s = "ping " + host.toStdString() + " -n "  + to_string((long double)cnt), cnt;

#endif
    processPing =new QProcess(thread);
    processPing->start(tr(s.c_str()));
    processPing->waitForFinished();
    QString res =  processPing->readAllStandardOutput();
    res+= processPing->readAllStandardError();

    ui->textBrowser->setText(res);
    if (res.toStdString().find("ttl")!=string::npos || res.toStdString().find("TTL")!=string::npos
            ||res.toStdString().find("Lost = 0")!=string::npos ){
        setIconGood();
        return true;
    }
    else{
        setIconBad();
        return false;
    }

}

void MainWindow::timer_overflow()
{

    if (doPing(ui->lineEdit->text()))
    {
        cntFailsPings = 0;
    }
    else {
        cntFailsPings++;
    }

    if (cntFailsPings == ui->spinBox_cntFails->value()){
        cntFailsPings = 0;
        bt_disconnect_click();
        bt_connect_click();
    }
}

void  MainWindow ::closeEvent(QCloseEvent *event)
{
    if ( ui->checkBox->isChecked()) {
         trayIcon->showMessage(tr("Systray"),
                               tr("The program will keep running in the "
                                  "system tray. To terminate the program, "
                                  "choose Quit in the context menu "
                                  "of the system tray entry."));
        hide();
        event->ignore();

    }
}

void MainWindow::thread_run(){
    timer->start(ui->spinBox->value()* 1000);
    //exec();
}

void MainWindow::saveSettings(){
    QSettings settings(fileName, QSettings::IniFormat);

    settings.setValue("is_hide_not_close", ui->checkBox->isChecked());
    settings.setValue("count_pings_at_time", ui->spinBox_cnt->value());
    settings.setValue("delay", ui->spinBox->value());
    settings.setValue("server_name",ui->lineEdit->text());

    settings.setValue("auto_connect_vpn", ui->checkBox_isManipulateVpn->isChecked());
    settings.setValue("count_pings_vpn", ui->spinBox_cntFails->value());
    settings.setValue("vpn_name", ui->lineEdit_vpnName->text());
    settings.setValue("vpn_username", ui->lineEdit_vpnUser->text());
    settings.setValue("vpn_userpass", ui->lineEdit_vpnPass->text());

    trayIcon->showMessage(tr("Settings"), tr("Saved"));

}

void MainWindow::loadSettings(){
    QSettings settings(fileName, QSettings::IniFormat);

     ui->checkBox->setChecked(settings.value("is_hide_not_close", true).toBool());
     ui->spinBox_cnt->setValue(settings.value("count_pings_at_time",1).toInt());
     ui->spinBox->setValue(settings.value("delay",1).toInt());
     ui->lineEdit->setText(settings.value("server_name", "localhost").toString());

     ui->checkBox_isManipulateVpn->setChecked(settings.value("auto_connect_vpn").toBool());
     ui->spinBox_cntFails->setValue(settings.value("count_pings_vpn",1).toInt());
     ui->lineEdit_vpnName->setText(settings.value("vpn_name").toString());
     ui->lineEdit_vpnUser->setText(settings.value("vpn_username").toString());
     ui->lineEdit_vpnPass->setText(settings.value("vpn_userpass").toString());

     trayIcon->showMessage(tr("Settings"), tr("Loaded"));

}


void MainWindow::bt_connect_click(){
    ui->lineEdit_vpnName->setEnabled(false);
    ui->lineEdit_vpnUser->setEnabled(false);
    ui->lineEdit_vpnPass->setEnabled(false);

    ui->textBrowser_vpn->setText("");
    string s;
    int cnt = ui->spinBox_cnt->value();
#ifdef __linux__
    // :(
#elif _WIN32
    s = "cmd /c rasdial \"" + ui->lineEdit_vpnName->text().toStdString() + "\" " +
            ui->lineEdit_vpnUser->text().toStdString() + " " +
            ui->lineEdit_vpnPass->text().toStdString() + " ";
#endif
    processVpn =new QProcess(this);
    processVpn->start(tr(s.c_str()));
    processVpn->waitForFinished();
    QString res =  processVpn->readAllStandardOutput();
    res+= processVpn->readAllStandardError();

    ui->textBrowser_vpn->setText(res);

    if (res.toStdString().find("Successfully connected to vpn connection")!=string::npos
            || res.toStdString().find("already connected")!=string::npos){
        ui->label_8->setText("Connected");
        ui->label_8->setStyleSheet("QLabel { color : green; }");

        trayIcon->showMessage(ui->lineEdit_vpnName->text(),
                              tr("Connected"));
    }
    else{
        ui->label_8->setText("Disconnected");
        ui->label_8->setStyleSheet("QLabel { color : red; }");
    }

}

void MainWindow::bt_disconnect_click(){
    ui->lineEdit_vpnName->setEnabled(true);
    ui->lineEdit_vpnUser->setEnabled(true);
    ui->lineEdit_vpnPass->setEnabled(true);

    string s;
    int cnt = ui->spinBox_cnt->value();
#ifdef __linux__
    // :(
#elif _WIN32
    s = "cmd /c rasdial \"" + ui->lineEdit_vpnName->text().toStdString() + "\" /disconnect";
   #endif

    processVpn =new QProcess(this);
    processVpn->start(tr(s.c_str()));
    processVpn->waitForFinished();
    QString res =  processVpn->readAllStandardOutput();
             res+= processVpn->readAllStandardError();
    ui->textBrowser_vpn->setText(res);

    ui->label_8->setText("Disconnected");
    ui->label_8->setStyleSheet("QLabel { color : red; }");


}


MainWindow::~MainWindow()
{
    delete ui;
    timer->stop();
    thread->exit();
}

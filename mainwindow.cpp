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
    ui->spinBox->setValue(5);
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
    trayIcon->setToolTip("Ping failed");
}

void MainWindow::setIconGood()
{
    QIcon icon = QIcon(":/images/good.png");
    setWindowIcon(icon);
    trayIcon->setIcon(icon);
    trayIcon->setToolTip("Pinged");
}

void MainWindow::setIconNeutral()
{
    QIcon icon = QIcon(":/images/neutral.png");
    setWindowIcon(icon);
    trayIcon->setIcon(icon);
    trayIcon->setToolTip("Unknown");
}
void MainWindow::bt_go_click(){
    thread->start();
    ui->lineEdit->setReadOnly(true);
    ui->spinBox->setReadOnly(true);
}

void MainWindow::bt_stop_click(){
    timer->stop();
    thread->exit();
    setIconNeutral();
    ui->lineEdit->setReadOnly(false);
    ui->spinBox->setReadOnly(false);
}

void MainWindow::doPing(QString host){
    string s;
#ifdef __linux__
    s = "ping " + host.toStdString() + " -c 1" + " 1>tmp.txt 2>&1 ";
    system(s.c_str());
#elif _WIN32
    s = "cmd /c ping " + host.toStdString() + " -n 1" + " 1>tmp.txt 2>&1 ";
    WinExec(s.c_str(), SW_HIDE);
#endif

    s="";
    string str;
    ifstream infile;
    infile.open ("tmp.txt");
    while (std::getline(infile, str))
    {
        s+=str;
    }
    infile.close();
    ui->textBrowser->setText(tr(s.c_str()));
    if (s.find("ttl")!=string::npos || s.find("TTL")!=string::npos){
        setIconGood();
    }
    else{
        setIconBad();
    }

}

void MainWindow::timer_overflow()
{
    //Обновляем значение времени на форме
    doPing(ui->lineEdit->text());
}

void  MainWindow ::closeEvent(QCloseEvent *event)
{
    if (trayIcon->isVisible()) {
        // QMessageBox::information(this, tr("Systray"),
        //                          tr("The program will keep running in the "
        //                             "system tray. To terminate the program, "
        //                             "choose <b>Quit</b> in the context menu "
        //                             "of the system tray entry."));
        hide();
        event->ignore();

    }
}

void MainWindow::thread_run(){
    timer->start(ui->spinBox->value()* 1000);
    //exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <QTimer>
#include <QThread>
#include <QSettings>
#include <qmessagebox.h>
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event);
private slots:
    void setIconBad();
    void setIconGood();
    void setIconNeutral();
    void bt_go_click();
    void bt_stop_click();
    void timer_overflow();
    void thread_run();
    void loadSettings();
    void saveSettings();
    void bt_connect_click();
    void bt_disconnect_click();

private:
    void createActions();
    void createTrayIcon();
    bool doPing(QString host);

    QAction *minimizeAction;
    QAction *maximizeAction;
    QAction *restoreAction;
    QAction *quitAction;

    Ui::MainWindow *ui;
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    QTimer *timer;
    QThread *thread;
    QString  fileName;
    int cntFailsPings;
    QProcess *processVpn;
    QProcess *processPing;
};

#endif // MAINWINDOW_H

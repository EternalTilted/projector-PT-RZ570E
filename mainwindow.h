#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <windows.h>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>
#include <QString>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_powerOn_clicked();

    void on_Confirm_clicked();

    void on_powerOff_clicked();

    void on_freeze_clicked(bool checked);

    void on_menuKey_clicked();

    void on_enterKey_clicked();

    void on_upKey_clicked();

    void on_downKey_clicked();

    void on_leftKey_clicked();

    void on_rightKey_clicked();

    void on_defaultKey_clicked();

    void on_autoSetup_clicked();

    void on_AVMute_clicked(bool checked);

    void on_comboBox_activated(int index);

    void on_func1Key_clicked();

    void on_func2Key_clicked();

    void on_func3Key_clicked();    

    void on_testPattern_activated(int index);

    void on_radioButton_clicked(bool checked);   

    void on_horizontalSlider_valueChanged(int value);

    void on_sysSelector_clicked();

    void on_com_clicked(bool checked);

    void on_eth_clicked(bool checked);  



private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QTcpSocket *TCPSocket;
};
#endif // MAINWINDOW_H

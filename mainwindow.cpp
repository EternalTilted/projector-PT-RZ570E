#include "mainwindow.h"
#include "ui_mainwindow.h"

HANDLE hSerial;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    serial = new QSerialPort(this);
    serial->setPortName("COM1");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open((QIODevice::ReadWrite));

    TCPSocket = new QTcpSocket();

}

MainWindow::~MainWindow()
{
    delete ui;
    serial->close();
    TCPSocket->close();
    delete serial;
    delete TCPSocket;
}


void MainWindow::on_powerOn_clicked()
{
    if(ui->com->isChecked()){
         serial->write("\x02");
         serial->write("ADZZ;PON");
         serial->write("\x03");
    }
    else if(ui->eth->isChecked()){
        TCPSocket->write("\x02");
        TCPSocket->write("ADZZ;PON");
        TCPSocket->write("\x03");
    }

}

void MainWindow::on_Confirm_clicked()
{
    if(ui->com->isChecked()){
        serial->close();
        TCPSocket->close();
        serial->setPortName(ui->comName->text());
        serial->open((QIODevice::ReadWrite));
    }
    if(ui->eth->isChecked()){
        serial->close();
        TCPSocket->close();
        TCPSocket->connectToHost(ui->ethName_2->text(), ui->ethName->text().toShort());
        TCPSocket->open(QIODevice::ReadWrite);

    }
}


void MainWindow::on_powerOff_clicked()
{

    if(ui->com->isChecked()){
         serial->write("\x02");
         serial->write("ADZZ;POF");
         serial->write("\x03");
    }
    else if(ui->eth->isChecked()){
        TCPSocket->write("\x02");
        TCPSocket->write("ADZZ;POF");
        TCPSocket->write("\x03");
    }
}

void MainWindow::on_freeze_clicked(bool checked)
{


   if(ui->com->isChecked()){
       serial->write("\x02");
       if(checked){
           serial->write("ADZZ;OFZ:1");
       }
       else{
           serial->write("ADZZ;OFZ:0");
       }
       serial->write("\x03");
   }
   else if(ui->eth->isChecked()){
       TCPSocket->write("\x02");
       if(checked){
           TCPSocket->write("ADZZ;OFZ:1");
       }
       else{
           TCPSocket->write("ADZZ;OFZ:0");
       }
       TCPSocket->write("\x03");
   }

}


void MainWindow::on_menuKey_clicked()
{

    if(ui->com->isChecked()){
         serial->write("\x02");
         serial->write("ADZZ;OMN");
         serial->write("\x03");
    }
    else if(ui->eth->isChecked()){
        TCPSocket->write("\x02");
        TCPSocket->write("ADZZ;OMN");
        TCPSocket->write("\x03");
    }
}


void MainWindow::on_enterKey_clicked()
{
    if(ui->com->isChecked()){
         serial->write("\x02");
         serial->write("ADZZ;OEN");
         serial->write("\x03");
    }
    else if(ui->eth->isChecked()){
        TCPSocket->write("\x02");
        TCPSocket->write("ADZZ;OEN");
        TCPSocket->write("\x03");
    }
}


void MainWindow::on_upKey_clicked()
{   
    if(ui->com->isChecked()){
         serial->write("\x02");
         serial->write("ADZZ;OCU");
         serial->write("\x03");
    }
    else if(ui->eth->isChecked()){
        TCPSocket->write("\x02");
        TCPSocket->write("ADZZ;OCU");
        TCPSocket->write("\x03");
    }
}


void MainWindow::on_downKey_clicked()
{   
    if(ui->com->isChecked()){
         serial->write("\x02");
         serial->write("ADZZ;OCD");
         serial->write("\x03");
    }
    else if(ui->eth->isChecked()){
        TCPSocket->write("\x02");
        TCPSocket->write("ADZZ;OCD");
        TCPSocket->write("\x03");
    }
}



void MainWindow::on_leftKey_clicked()
{   
    if(ui->com->isChecked()){
         serial->write("\x02");
         serial->write("ADZZ;OCL");
         serial->write("\x03");
    }
    else if(ui->eth->isChecked()){
        TCPSocket->write("\x02");
        TCPSocket->write("ADZZ;OCL");
        TCPSocket->write("\x03");
    }
}


void MainWindow::on_rightKey_clicked()
{
    if(ui->com->isChecked()){
         serial->write("\x02");
         serial->write("ADZZ;OCR");
         serial->write("\x03");
    }
    else if(ui->eth->isChecked()){
        TCPSocket->write("\x02");
        TCPSocket->write("ADZZ;OCR");
        TCPSocket->write("\x03");
    }
}


void MainWindow::on_defaultKey_clicked()
{
    if(ui->com->isChecked()){
         serial->write("\x02");
         serial->write("ADZZ;OST");
         serial->write("\x03");
    }
    else if(ui->eth->isChecked()){
        TCPSocket->write("\x02");
        TCPSocket->write("ADZZ;OST");
        TCPSocket->write("\x03");
    }
}


void MainWindow::on_autoSetup_clicked()
{
    if(ui->com->isChecked()){
         serial->write("\x02");
         serial->write("ADZZ;OAS");
         serial->write("\x03");
    }
    else if(ui->eth->isChecked()){
        TCPSocket->write("\x02");
        TCPSocket->write("ADZZ;OAS");
        TCPSocket->write("\x03");
    }
}


void MainWindow::on_AVMute_clicked(bool checked)
{
;
    if(ui->com->isChecked()){
        serial->write("\x02");
        if(checked){
            serial->write("ADZZ;OSH:1");
        }
        else{
             serial->write("ADZZ;OSH:0");
        }
        serial->write("\x03");
    }
    else if(ui->eth->isChecked()){
        TCPSocket->write("\x02");
        if(checked){
            TCPSocket->write("ADZZ;OSH:1");
        }
        else{
             TCPSocket->write("ADZZ;OSH:0");
        }
        TCPSocket->write("\x03");
    }
}

void MainWindow::on_comboBox_activated(int index)
{


    if(ui->com->isChecked()){
        switch (index) {
        case 0:
            break;
        case 1:
            serial->write("\x02");
            serial->write("ADZZ;IIS:PC1");
            serial->write("\x03");
            break;
        case 2:
            serial->write("\x02");
            serial->write("ADZZ;IIS:PC2");
            serial->write("\x03");
            break;
        case 3:
            serial->write("\x02");
            serial->write("ADZZ;IIS:RG1");
            serial->write("\x03");
            break;
        case 4:
            serial->write("\x02");
            serial->write("ADZZ;IIS:RG2");
            serial->write("\x03");
            break;
        case 5:
            serial->write("\x02");
            serial->write("ADZZ;IIS:VID");
            serial->write("\x03");
            break;
        case 6:
            serial->write("\x02");
            serial->write("ADZZ;IIS:DVI");
            serial->write("\x03");
            break;
        case 7:
            serial->write("\x02");
            serial->write("ADZZ;IIS:HD1");
            serial->write("\x03");
            break;
        case 8:
            serial->write("\x02");
            serial->write("ADZZ;IIS:DL1");
            serial->write("\x03");
            break;
        default:
            break;
        }
    }
    else if(ui->eth->isChecked()){
        switch (index) {
        case 0:
            break;
        case 1:
            TCPSocket->write("\x02");
            TCPSocket->write("ADZZ;IIS:PC1");
            TCPSocket->write("\x03");
            break;
        case 2:
            TCPSocket->write("\x02");
            TCPSocket->write("ADZZ;IIS:PC2");
            TCPSocket->write("\x03");
            break;
        case 3:
            TCPSocket->write("\x02");
            TCPSocket->write("ADZZ;IIS:RG1");
            TCPSocket->write("\x03");
            break;
        case 4:
            TCPSocket->write("\x02");
            TCPSocket->write("ADZZ;IIS:RG2");
            TCPSocket->write("\x03");
            break;
        case 5:
            TCPSocket->write("\x02");
            TCPSocket->write("ADZZ;IIS:VID");
            TCPSocket->write("\x03");
            break;
        case 6:
            TCPSocket->write("\x02");
            TCPSocket->write("ADZZ;IIS:DVI");
            TCPSocket->write("\x03");
            break;
        case 7:
            TCPSocket->write("\x02");
            TCPSocket->write("ADZZ;IIS:HD1");
            TCPSocket->write("\x03");
            break;
        case 8:
            TCPSocket->write("\x02");
            TCPSocket->write("ADZZ;IIS:DL1");
            TCPSocket->write("\x03");
            break;
        default:
            break;
        }
    }

}


void MainWindow::on_func1Key_clicked()
{
    if(ui->com->isChecked()){
         serial->write("\x02");
         serial->write("ADZZ;FC1");
         serial->write("\x03");
    }
    else if(ui->eth->isChecked()){
        TCPSocket->write("\x02");
        TCPSocket->write("ADZZ;FC1");
        TCPSocket->write("\x03");
    }
}



void MainWindow::on_func2Key_clicked()
{
    if(ui->com->isChecked()){
         serial->write("\x02");
         serial->write("ADZZ;FC2");
         serial->write("\x03");
    }
    else if(ui->eth->isChecked()){
        TCPSocket->write("\x02");
        TCPSocket->write("ADZZ;FC2");
        TCPSocket->write("\x03");
    }
}


void MainWindow::on_func3Key_clicked()
{
    if(ui->com->isChecked()){
         serial->write("\x02");
         serial->write("ADZZ;FC3");
         serial->write("\x03");
    }
    else if(ui->eth->isChecked()){
        TCPSocket->write("\x02");
        TCPSocket->write("ADZZ;FC3");
        TCPSocket->write("\x03");
    }
}

void MainWindow::on_testPattern_activated(int index)
{


    if(ui->com->isChecked()){
        serial->write("\x02");
        switch(index){
        case 0:
            serial->write("ADZZ;OTS:00");
            break;
        case 1:
            serial->write("ADZZ;OTS:01");
            break;
        case 2:
            serial->write("ADZZ;OTS:02");
            break;
        case 3:
            serial->write("ADZZ;OTS:05");
            break;
        case 4:
            serial->write("ADZZ;OTS:06");
            break;
        case 5:
            serial->write("ADZZ;OTS:07");
            break;
        case 6:
            serial->write("ADZZ;OTS:08");
            break;
        case 7:
            serial->write("ADZZ;OTS:51");
            break;
        case 8:
            serial->write("ADZZ;OTS:59");
            break;
        default:
            break;
        }
        serial->write("\x03");
    }
    else if(ui->eth->isChecked()){
        TCPSocket->write("\x02");
        switch(index){
        case 0:
            TCPSocket->write("ADZZ;OTS:00");
            break;
        case 1:
            TCPSocket->write("ADZZ;OTS:01");
            break;
        case 2:
            TCPSocket->write("ADZZ;OTS:02");
            break;
        case 3:
            TCPSocket->write("ADZZ;OTS:05");
            break;
        case 4:
            TCPSocket->write("ADZZ;OTS:06");
            break;
        case 5:
            TCPSocket->write("ADZZ;OTS:07");
            break;
        case 6:
            TCPSocket->write("ADZZ;OTS:08");
            break;
        case 7:
            TCPSocket->write("ADZZ;OTS:51");
            break;
        case 8:
            TCPSocket->write("ADZZ;OTS:59");
            break;
        default:
            break;
        }
        TCPSocket->write("\x03");
    }
}


void MainWindow::on_radioButton_clicked(bool checked)
{


    if(ui->com->isChecked()){
        serial->write("\x02");
        if(checked){
            serial->write("ADZZ;OOS:1");
        }
        else{
            serial->write("ADZZ;OOS:0");
        }
        serial->write("\x03");
    }
    else if(ui->eth->isChecked()){

        TCPSocket->write("\x02");
        if(checked){
            TCPSocket->write("ADZZ;OOS:1");
        }
        else{
            TCPSocket->write("ADZZ;OOS:0");
        }
        TCPSocket->write("\x03");
    }
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{


    if(ui->com->isChecked()){
        ui->label_4->setText(QString::number(value));
        serial->write("\x02");
        QByteArray ba("ADZZ;ONK:");
        ba.append(QString::number(value));
        serial->write(ba);
        serial->write("\x03");
    }
    else if(ui->eth->isChecked()){
        ui->label_4->setText(QString::number(value));
        TCPSocket->write("\x02");
        QByteArray ba("ADZZ;ONK:");
        ba.append(QString::number(value));
        TCPSocket->write(ba);
        TCPSocket->write("\x03");
    }

}


void MainWindow::on_sysSelector_clicked()
{
    if(ui->com->isChecked()){
         serial->write("\x02");
         serial->write("ADZZ;OSL");
         serial->write("\x03");
    }
    else if(ui->eth->isChecked()){
        TCPSocket->write("\x02");
        TCPSocket->write("ADZZ;OSL");
        TCPSocket->write("\x03");
    }
}


void MainWindow::on_com_clicked(bool checked)
{
    if(checked){
        ui->eth->setChecked(false);
        on_Confirm_clicked();
    }
}


void MainWindow::on_eth_clicked(bool checked)
{
    if(checked){
        ui->com->setChecked(false);
        on_Confirm_clicked();
    }
}






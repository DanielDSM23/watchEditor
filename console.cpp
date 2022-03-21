#include "console.h"
#include "ui_console.h"
#include <QMessageBox>

console::console(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::console)
{
    ui->setupUi(this);
    serial = new QSerialPort;
    serial->setPortName("COM4");
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);
    if(!serial->isOpen()){
        QMessageBox::information(this, tr("usb"),tr("La montre n'a pas été détectée !\nVerifier votre branchement\n"));

    }
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(500);
}

void console::update(){
    if(serial->isOpen()){
        while(serial->canReadLine()){
            buf = serial->readLine();
            ui->textEdit->append(buf);
        }
        //buf = serial->readAll();

    }
}

console::~console()
{
    serial->close();
    delete ui;
}

void console::on_pushButton_clicked()
{
    QString command = ui->lineEdit->text();
    ui->lineEdit->clear();
    serial->write(command.toLocal8Bit());
}


QByteArray console::getBuf(){
    return buf;
}

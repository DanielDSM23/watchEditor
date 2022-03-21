#include "wifieditor.h"
#include "ui_wifieditor.h"
#include <QThread>
#include <QMessageBox>

wifiEditor::wifiEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wifiEditor)
{
    ui->setupUi(this);
    konsole = new console;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(textConsolef()));
    timer->start(500);
    active = false;
}

wifiEditor::~wifiEditor()
{
    delete ui;
}

void wifiEditor::on_actualiser_clicked()
{
    command = "set wifi";
    ssid = ui->ssid->text();
    passwd = ui->lineEdit_2->text();
    QString firstCondition = "put SSID :", secondCondition = "put password :";

    konsole->serial->write(command.toLocal8Bit());
    active = true;

}

void wifiEditor::textConsolef(){
    textConsole=konsole->getBuf();
    qDebug() << textConsole << active;
    if (active == true){
        if(textConsole.contains("......put SSID") || textConsole.contains("put SSID")){
            konsole->serial->write(ssid.toLocal8Bit());
            qDebug() << "dans if ssid";
            konsole->serial->write(passwd.toLocal8Bit());
        }
        if(textConsole.contains("put password :")){
            active = false;
        }

    }

}

void wifiEditor::on_pushButton_2_clicked()
{

}

#include "watchEditor.h"
#include "addclient.h"
#include "ui_watchEditor.h"
#include "about.h"
#include "wifieditor.h"
#include <QMessageBox>

watchEditor::watchEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::watchEditor)
{
    ui->setupUi(this);
}

watchEditor::~watchEditor()
{
    delete ui;
}


void watchEditor::on_actionmodifier_MQTT_triggered()
{

}


void watchEditor::on_actionAjouter_client_BDD_triggered()
{
    addClient * ajouterClient = new addClient;
    if(ajouterClient->db.open()){
        ajouterClient->setModal(true);
        ajouterClient->exec();
    }
    else{
        QMessageBox::critical(this, tr("BDD"),tr("Echec ouverture bdd ! \nVeuillez contacter un administrateur\n"));
    }

}


void watchEditor::on_action_propos_triggered()
{
    about * aPropos = new about;
    aPropos->setModal(true);
    aPropos->exec();
}


void watchEditor::on_menu_triggered()
{
    wifiEditor * modifWifi = new wifiEditor;
    modifWifi->setModal(true);
    modifWifi->exec();
}

void watchEditor::on_actionConsole_triggered()
{
    console * konsole = new console;
    konsole->show();
}


#ifndef WATCHEDITOR_H
#define WATCHEDITOR_H
#include <QMainWindow>
#include "addclient.h"
#include <QtSerialPort/QSerialPort>
#include "console.h"

QT_BEGIN_NAMESPACE
namespace Ui { class watchEditor; }
QT_END_NAMESPACE

class watchEditor : public QMainWindow
{
    Q_OBJECT

public:
    watchEditor(QWidget *parent = nullptr);
    ~watchEditor();


private slots:
    void on_actionmodifier_MQTT_triggered();

    void on_actionAjouter_client_BDD_triggered();

    void on_action_propos_triggered();

    void on_menu_triggered();

    void on_actionConsole_triggered();

private:
    Ui::watchEditor *ui;
};
#endif // WATCHEDITOR_H

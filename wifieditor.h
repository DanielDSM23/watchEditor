#ifndef WIFIEDITOR_H
#define WIFIEDITOR_H

#include <QDialog>
#include "watchEditor.h"
#include <QDebug>
#include "console.h"

namespace Ui {
class wifiEditor;
}

class wifiEditor : public QDialog
{
    Q_OBJECT

public:
    explicit wifiEditor(QWidget *parent = 0);
    ~wifiEditor();
public slots :
    void textConsolef();

private slots:
    void on_buttonBox_accepted();

    void on_actualiser_clicked();

    void on_pushButton_2_clicked();
private:
    Ui::wifiEditor *ui;
    console * konsole;
    QByteArray textConsole;
    QTimer *timer;
    bool active;
    QString ssid;
    QString passwd;
    QString command;
};

#endif // WIFIEDITOR_H

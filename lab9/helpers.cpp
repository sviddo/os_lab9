#include "clientwindow.h"
#include "ui_clientwindow.h"
#include <string>
#include <QString>
using namespace std;

void set_DateTimeLabel(Ui::ClientWindow *ui, string value)
{
    ui->dateTimeLabel->setText(QString::fromStdString(value));
}


void set_cityLabel(Ui::ClientWindow *ui, string value)
{
    ui->cityLabel->setText(QString::fromStdString(value));
}


void set_tempLabel(Ui::ClientWindow *ui, string value)
{
    ui->tempLabel->setText(QString::fromStdString(value));
}


void set_appleLabel(Ui::ClientWindow *ui, string value)
{
    ui->appleLabel->setText(QString::fromStdString(value));
}


void set_teslaLabel(Ui::ClientWindow *ui, string value)
{
    ui->teslaLabel->setText(QString::fromStdString(value));
}


void set_amazonLabel(Ui::ClientWindow *ui, string value)
{
    ui->amazonLabel->setText(QString::fromStdString(value));
}


void set_dollarLabel(Ui::ClientWindow *ui, string value)
{
    ui->dollarLabel->setText(QString::fromStdString(value));
}


void set_euroLabel(Ui::ClientWindow *ui, string value)
{
    ui->euroLabel->setText(QString::fromStdString(value));
}


void set_poundLabel(Ui::ClientWindow *ui, string value)
{
    ui->poundLabel->setText(QString::fromStdString(value));
}

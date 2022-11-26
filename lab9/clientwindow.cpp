#include "clientwindow.h"
#include "ui_clientwindow.h"

Ui::ClientWindow *ui_global;

ClientWindow::ClientWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    ui_global = ui;
}

ClientWindow::~ClientWindow()
{
    delete ui;
}

void ClientWindow::on_subsWeatherAction_triggered()
{
    QStringList citiesList; bool ok = false;
    citiesList << "Львів" << "Київ" << "Івано-Франківськ" << "Харків" << "Дніпро";
    QString choiceCity = QInputDialog::getItem(this, "", "Оберіть місто, обновлення погоди\nз якого ви хочете бачити: ",
                                               citiesList, false ,&ok);
    if(ok){
        // передача сигналу до сервера
    }
}

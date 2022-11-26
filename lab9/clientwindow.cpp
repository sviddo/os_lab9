#include "clientwindow.h"
#include "ui_clientwindow.h"

ClientWindow::ClientWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
}

ClientWindow::~ClientWindow()
{
    delete ui;
}

void ClientWindow::on_subscribeButton_clicked()
{
    std::string requestStr = "";
    if(ui->weatherCheckBox->isChecked()){
            QStringList citiesList; QString choiceCity = "Львів"; bool ok = false;
            citiesList << "Львів" << "Київ" << "Івано-Франківськ" << "Харків" << "Дніпро";
            choiceCity = QInputDialog::getItem(this, "", "Оберіть місто, обновлення погоди\nз якого ви хочете бачити: ",
                                                       citiesList, false ,&ok);
            requestStr += "1";
    } else requestStr += "0";
    requestStr += (ui->stocksCheckBox->isChecked()) ? "1" : "0";
    requestStr += (ui->currencyCheckBox->isChecked()) ? "1" : "0";
    const char* request = requestStr.c_str();
}


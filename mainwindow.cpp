#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "address.h"
#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

QHash<QString, QString> MainWindow::getPersonalDetailsData() {
    QHash<QString, QString> data = QHash<QString, QString>();
    data["givenName1"] = ui->txtGivenName->text();
    data["givenName2"] = ui->txtMiddleName->text();
    data["surname"] = ui->txtSurname->text();
    data["preferredName"] = ui->txtPreferredName->text();
    data["address1"] = ui->txtAddress1->text();
    data["address2"] = ui->txtAddress2->text();
    data["city"] = ui->txtCity->text();
    data["postcode"] = ui->txtPostcode->text();
    data["state"] = ui->txtState->text();
    data["country"] = ui->txtCountry->text();
    data["phoneNumber"] = ui->txtPhone->text();
    data["email"]= ui->txtEmail->text();
    data["isMononym"] = ui->chkIsMononymous->isChecked() ;
    data["isEastAsian"] = ui->chkEastAsian->isChecked() ? "true" : "false";
    data["preferWestern"] = ui->chkPreferWest->isChecked() ? "true" : "false";
    data["linkedIn"] = ui->txtLinkedIn->text();
    data["website"] = ui->txtWebsite->text();
    data["personalProfile"] = ui->textPersonalProfile->toMarkdown();

    return data;
}


void MainWindow::on_btnSave_clicked() {
    QHash<QString, QString> data = getPersonalDetailsData();
    Address * addy = new Address(data["address1"], data["address2"], data["city"], data["postcode"], data["state"], data["country"]);
    QJsonObject addrObj;
    addy->write(addrObj);
    QFile saveFile(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/address.bigpurrs");
    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Could not open file");
        return;
    }
    saveFile.write(QJsonDocument(addrObj).toJson());
}


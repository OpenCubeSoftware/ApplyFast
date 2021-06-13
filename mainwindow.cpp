#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "address.h"
#include "applicantdetails.h"
#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QMessageBox>
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    achievementModel= new StringListModel(this);
    skillsModel = new StringListModel(this);
    ui->skillsListView->setModel(skillsModel);
    ui->achievementsListView->setModel(achievementModel);

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

bool strToBool(QString str) {
    if (str == "true")
        return true;
    if (str == "false")
        return false;
    return false;
}


void MainWindow::on_btnSave_clicked() {
    QHash<QString, QString> data = getPersonalDetailsData();
    QStringList achievements = achievementModel->outputData();
    QStringList skills = skillsModel->outputData();
    Address * addy = new Address(data["address1"], data["address2"], data["city"], data["postcode"], data["state"], data["country"]);
    ApplicantDetails * appy = new ApplicantDetails(data["givenName1"], data["givenName2"], data["surname"], data["preferredName"], addy, data["phoneNumber"], data["email"], strToBool(data["isMononym"]), strToBool(data["isEastAsian"]), strToBool(data["preferWestern"]),   data["linkedIn"], data["personalProfile"], data["website"], achievements, skills);
    QJsonObject appObj;
    appy->write(appObj);
    QFile saveFile(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/address.bigpurrs");
    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Could not open file");
        return;
    }
    QMessageBox msg;
    int res = saveFile.write(QJsonDocument(appObj).toJson());
    if (res != -1) {
        msg.setWindowTitle("Success");
        msg.setText("Saved successfully");
        msg.setIcon(QMessageBox::Information);
        msg.exec();
    } else {
        msg.setWindowTitle("Error");
        msg.setText("An error occurred");
        msg.setIcon(QMessageBox::Critical);
        msg.exec();
    }

}


void MainWindow::on_btnAddSkill_clicked() {
    QString skill = ui->txtSkill->text();
    if (!skill.isEmpty()) {
        skillsModel->addString(skill);
        ui->txtSkill->setText("");
    }
}


void MainWindow::on_btnAddAchievement_clicked() {
    QString achievement = ui->txtAchievement->text();
    if (!achievement.isEmpty()) {
        achievementModel->addString(achievement);
        ui->txtAchievement->setText("");
    }
}


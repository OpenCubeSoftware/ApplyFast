#include "jobpersondetails.h"

JobPersonDetails::JobPersonDetails(QObject *parent) : PersonalDetails(parent) {

}

JobPersonDetails::JobPersonDetails(QString &name1, QString &name2, QString &familyName, QString &preferredName, Address *address, QString &phone, QString &email, bool isMononymous, bool isEastAsian, bool preferredWesternOrder, QString &jobTitle, QString &company)
    :PersonalDetails(name1, name2, familyName, preferredName, address, phone, email, isMononymous, isEastAsian, preferredWesternOrder) {
    m_jobTitle = jobTitle;
    m_companyName = company;
}

void JobPersonDetails::write(QJsonObject &json) {
    PersonalDetails::write(json);
    json["companyname"] = m_companyName;
    json["jobTitle"] = m_jobTitle;
}

QString JobPersonDetails::toString() {
    QString data = PersonalDetails::toString();
    return data + "\n\n" + QString("%1 is a %2 at %3\n").arg(PersonalDetails::m_preferredName, m_jobTitle, m_companyName);
}

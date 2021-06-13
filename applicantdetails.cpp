#include "applicantdetails.h"



ApplicantDetails::ApplicantDetails(QObject *parent) : PersonalDetails(parent) {

}

ApplicantDetails::ApplicantDetails(QString &name1, QString &name2, QString &familyName, QString &preferName, Address *address, QString &phone, QString &email, bool isMononymous, bool isEastAsian, bool preferredWesternOrder, QString &linkedIn, QString &personalProfile, QString &web, QStringList &achievements, QStringList &skills)
    :PersonalDetails(name1, name2, familyName, preferName, address, phone, email, isMononymous, isEastAsian, preferredWesternOrder) {
    m_linkedInProfile = linkedIn;
    m_personalProfile = personalProfile;
    m_website = web;
    m_skills = skills;
    m_achievements = achievements;
}

void ApplicantDetails::write(QJsonObject &json) {
    PersonalDetails::write(json);
    json["linkedIn"] = m_linkedInProfile;
    json["personalProfile"] = m_personalProfile;
    json["website"] = m_website;
    QJsonArray skills = QJsonArray::fromStringList(m_skills);
    QJsonArray achievements = QJsonArray::fromStringList(m_achievements);
    json["skills"] = skills;
    json["achievements"] = achievements;
}

QString ApplicantDetails::toString() {
    QString data = PersonalDetails::toString();
    data += QString("%1\n%2\nPersonal Profile:\n%3\n").arg(m_website, m_linkedInProfile, m_personalProfile);
    data += "Skills:\n - " + m_skills.join("\n - ") +"\n";
    data += "Achievements:\n - " + m_achievements.join("\n - ");
    return data + "\n";
}

#ifndef APPLICANTDETAILS_H
#define APPLICANTDETAILS_H

#include "personaldetails.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QObject>

class ApplicantDetails : public PersonalDetails {
    Q_OBJECT
public:
    explicit ApplicantDetails(QObject *parent = nullptr);
    ApplicantDetails(QString &name1, QString &name2, QString &familyName, QString &preferName, Address *address, QString &phone, QString &email, bool isMononymous, bool isEastAsian, bool preferredWesternOrder, QString &linkedIn, QString &personalProfile, QString &web, QStringList &achievements, QStringList &skills);
    void write(QJsonObject &json);
    QString toString();
private:
    QString m_linkedInProfile;
    QString m_personalProfile;
    QString m_website;
    QStringList m_achievements;
    QStringList m_skills;
};

#endif // APPLICANTDETAILS_H

#ifndef JOBPERSONDETAILS_H
#define JOBPERSONDETAILS_H

#include <QJsonObject>
#include <QObject>
#include "personaldetails.h"

class JobPersonDetails : public PersonalDetails {
    Q_OBJECT
public:
    explicit JobPersonDetails(QObject *parent = nullptr);
    JobPersonDetails(QString &name1, QString &name2, QString &familyName, QString &preferredName, Address *address, QString &phone, QString &email, bool isMononymous, bool isEastAsian, bool preferredWesternOrder, QString &jobTitle, QString &company);
    void write(QJsonObject &json);
    QString toString();
private:
    QString m_jobTitle;
    QString m_companyName;
};

#endif // JOBPERSONDETAILS_H

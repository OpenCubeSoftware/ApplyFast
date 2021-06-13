#ifndef PERSONALDETAILS_H
#define PERSONALDETAILS_H

#include <QObject>
#include "address.h"

class PersonalDetails : public QObject {
    Q_OBJECT
public:
    explicit PersonalDetails(QObject *parent = nullptr);
    PersonalDetails(QString &name1, QString &name2, QString &familyName, QString &preferredName, Address *address, QString &phone, QString &email, bool isMononymous, bool isEastAsian, bool preferredWesternOrder);
    QString toString();
    void write(QJsonObject &json);
protected:
    QString m_givenName1;
    QString m_givenName2;
    QString m_surname;
    QString m_preferredName;
    Address * m_address;
    QString m_phoneNumber;
    QString m_email;
    bool m_isMononymous;
    bool m_isEastAsian;
    bool m_preferredNameWesternOrder;
};

#endif // PERSONALDETAILS_H

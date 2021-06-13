#include "personaldetails.h"

PersonalDetails::PersonalDetails(QObject *parent) : QObject(parent) {

}

PersonalDetails::PersonalDetails(QString &name1, QString &name2, QString &familyName, QString &preferredName, Address *address, QString &phone, QString &email, bool isMononymous, bool isEastAsian, bool preferredWesternOrder) {
    m_givenName1 = name1;
    m_givenName2 = name2;
    m_surname = familyName;
    m_preferredName = preferredName;
    m_address = address;
    m_phoneNumber = phone;
    m_email= email;
    m_isMononymous = isMononymous;
    m_isEastAsian = isEastAsian;
    m_preferredNameWesternOrder = preferredWesternOrder;
}

QString PersonalDetails::toString() {
    QString data;
    if(m_isMononymous) {
        data = m_surname + "\n";
    } else {
        if (m_isEastAsian && !m_preferredNameWesternOrder) {
            data = QString("%1 %2\n").arg(m_surname, m_preferredName);
        } else {
            data = QString("%1 %2\n").arg(m_preferredName, m_surname);
        }

        if (!m_givenName2.isEmpty()) {
            if (m_isEastAsian)
                data += QString("(%1 %2 %3)\n").arg(m_surname, m_givenName1, m_givenName2);
            else
                data += QString("(%1 %2 %3)\n").arg(m_givenName1, m_givenName2, m_surname);
        } else {
            if (m_isEastAsian)
                data += QString("(%1 %2)\n").arg(m_surname, m_givenName1);
            else
                data += QString("(%1 %2)\n").arg(m_givenName1, m_surname);
        }
    }
    data += m_address->toString();
    data += QString("%1\n%2\n").arg(m_phoneNumber, m_email);

    return data+ "\n";
}

void PersonalDetails::write(QJsonObject &json) {
    json["givenName1"] = m_givenName1;
    json["givenName2"] = m_givenName2;
    json["surname"] = m_surname;
    json["preferredName"] = m_preferredName;
    QJsonObject addrObject;
    m_address->write(addrObject);
    json["address"] = addrObject;
    json["phoneNumber"] = m_phoneNumber;
    json["email"] = m_email;
    json["isMononomous"] = m_isMononymous;
    json["isEastAsian"] = m_isEastAsian;
    json["preferredNameWesternOrder"] = m_preferredNameWesternOrder;
}

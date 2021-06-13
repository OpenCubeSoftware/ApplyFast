#include "educationitem.h"

EducationItem::EducationItem(QObject *parent) : QObject(parent) {

}

EducationItem::EducationItem(QString &educationProvider, QString &location, QList<Qualification *>  qualifications) {
    m_educationProvider = educationProvider;
    m_location = location;
    m_qualifications = qualifications;
}

void EducationItem::write(QJsonObject &json) {
    json["educationProvider"] = m_educationProvider;
    json["location"] = m_location;
    QJsonArray qualsArray;
    for (Qualification * qual : m_qualifications) {
        QJsonObject qualObject;
        qual->write(qualObject);
        qualsArray.append(qualObject);
    }
    json["qualifications"] = qualsArray;
}

QString EducationItem::toString() {
    QString data = m_educationProvider + "\n";
    data += m_location + "\n";
    foreach(Qualification * q, m_qualifications) {
        data += q->toString();
    }
    return data+ "\n";
}

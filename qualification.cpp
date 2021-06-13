#include "qualification.h"

Qualification::Qualification(QObject *parent) : QObject(parent) {

}

Qualification::Qualification(QString &qualificationName, QString &subject, DateStartEnd *dates) {
    m_qualificationName = qualificationName;
    m_subject = subject;
    m_dates = dates;
}

QString Qualification::toString() {
    return QString("%1 in %2\n%3\n").arg(m_qualificationName, m_subject, m_dates->toString());
}

void Qualification::write(QJsonObject &json) {
    json["qualificationName"] = m_qualificationName;
    json["subject"] = m_subject;
    QJsonObject dateObject;
    m_dates->write(json);
    json["dates"] = dateObject;
}

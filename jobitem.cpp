#include "jobitem.h"

JobItem::JobItem(QObject *parent) : QObject(parent) {

}

JobItem::JobItem(QString &jobTitle, QString &companyName, QString &location, DateStartEnd *dates, QString &description, QStringList &dutyList) {
    m_jobTitle = jobTitle;
    m_companyName = companyName;
    m_location = location;
    m_dates = dates;
    m_description = description;
    m_duties = dutyList;
}

JobItem::JobItem(QString &jobTitle, QString &companyName, QString &location, DateStartEnd *dates, QStringList &dutyList) {
    m_jobTitle = jobTitle;
    m_companyName = companyName;
    m_location = location;
    m_dates = dates;
    m_duties = dutyList;
}

JobItem::JobItem(QString &jobTitle, QString &companyName, QString &location, DateStartEnd *dates, QString &description) {
    m_jobTitle = jobTitle;
    m_companyName = companyName;
    m_location = location;
    m_dates = dates;
    m_description = description;

}

QString JobItem::toString() {
    QString jobInfo = QString("%1 at %2\n%3\n").arg(m_jobTitle, m_companyName, m_location);
    jobInfo += m_dates->toString() + "\n";
    if (!m_description.isEmpty() && m_duties.length() > 0) {
        jobInfo += m_description + "\n" + m_duties.join("\n");
    } else {
        if (m_description.isEmpty()) {
            jobInfo += m_duties.join("\n");
        }
        if (m_duties.length() == 0) {
            jobInfo += m_description + "\n";
        }
    }
    return jobInfo+ "\n";
}

void JobItem::write(QJsonObject &json) {
    json["jobTitle"] = m_jobTitle;
    json["companyName"] = m_companyName;
    json["location"] = m_location;
    QJsonObject dateObject;
    m_dates->write(dateObject);
    json["dates"] = dateObject;
    json["description"] = m_description;
    if (!m_duties.isEmpty()) {
        QJsonArray dutiesObject = QJsonArray::fromStringList(m_duties);
        json["duties"] = dutiesObject;
    }
}

#ifndef JOBITEM_H
#define JOBITEM_H

#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include "datestartend.h"

class JobItem : public QObject {
    Q_OBJECT
public:
    explicit JobItem(QObject *parent = nullptr);
    JobItem(QString &jobTitle, QString &companyName, QString &location, DateStartEnd *dates, QString &description, QStringList &dutyList);
    JobItem(QString &jobTitle, QString &companyName, QString &location, DateStartEnd *dates, QStringList &dutyList);
    JobItem(QString &jobTitle, QString &companyName, QString &location, DateStartEnd *dates, QString &description);
    QString toString();
    void write(QJsonObject &json);
private:
    QString m_jobTitle;
    QString m_companyName;
    QString m_location;
    DateStartEnd * m_dates;
    QString m_description;
    QStringList m_duties;
};

#endif // JOBITEM_H

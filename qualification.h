#ifndef QUALIFICATION_H
#define QUALIFICATION_H
#include "datestartend.h"

#include <QObject>
#include <QJsonObject>

class Qualification : public QObject {
    Q_OBJECT
public:
    explicit Qualification(QObject *parent = nullptr);
    Qualification(QString &qualificationName, QString &subject, DateStartEnd *dates);
    QString toString();
    void write(QJsonObject &json);
private:
    QString m_qualificationName;
    QString m_subject;
    DateStartEnd * m_dates;

signals:

};

#endif // QUALIFICATION_H

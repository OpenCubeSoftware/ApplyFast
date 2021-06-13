#ifndef EDUCATIONITEM_H
#define EDUCATIONITEM_H

#include <QJsonObject>
#include <QJsonArray>
#include <QObject>
#include "qualification.h"

class EducationItem : public QObject {
    Q_OBJECT
public:
    explicit EducationItem(QObject *parent = nullptr);
    EducationItem(QString &educationProvider, QString &location, QList<Qualification *> qualifications);
    void write(QJsonObject &json);
    QString toString();
private:
    QString m_educationProvider;
    QString m_location;
    QList<Qualification*> m_qualifications;

};

#endif // EDUCATIONITEM_H

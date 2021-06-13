#ifndef CV_H
#define CV_H

#include <QJsonObject>
#include <QObject>
#include "applicantdetails.h"
#include "jobitem.h"
#include "educationitem.h"
#include "jobpersondetails.h"

class Cv : public QObject {
    Q_OBJECT
public:
    explicit Cv(QObject *parent = nullptr);
    Cv(ApplicantDetails * applicantDetails, QList<JobItem*> workHistory, QList<EducationItem*> educationHistory, QList<JobItem*> volunteerHistory, QList<JobPersonDetails*> referees);
    void write(QJsonObject &json);
    QString toString();
private:
    ApplicantDetails * m_applicantDetails;
    QList<JobItem*> m_workHistory;
    QList<EducationItem*> m_educationHistory;
    QList<JobItem*> m_volunteerHistory;
    QList<JobPersonDetails*> m_referees;
};

#endif // CV_H

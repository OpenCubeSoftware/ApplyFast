#include "cv.h"

Cv::Cv(QObject *parent) : QObject(parent) {

}

Cv::Cv(ApplicantDetails *applicantDetails, QList<JobItem *> workHistory, QList<EducationItem *> educationHistory, QList<JobItem *> volunteerHistory, QList<JobPersonDetails *> referees) {
    m_applicantDetails = applicantDetails;
    m_workHistory = workHistory;
    m_educationHistory = educationHistory;
    m_volunteerHistory = volunteerHistory;
    m_referees = referees;
}

void Cv::write(QJsonObject &json) {
    m_applicantDetails->write(json);

}

QString Cv::toString() {
    QString data;
    data += m_applicantDetails->toString();
    foreach(JobItem *job, m_workHistory) {
        data+= job->toString();
    }
    foreach(EducationItem *edu, m_educationHistory) {
        data += edu->toString();
    }
    if (m_volunteerHistory.length() > 0) {
        foreach(JobItem *vol, m_volunteerHistory) {
            data += vol->toString();
        }
    }
    foreach(JobPersonDetails *ref, m_referees) {
        data += ref->toString();
    }
    return data;
}

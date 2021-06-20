#include "datestartend.h"

DateStartEnd::DateStartEnd(QObject *parent) : QObject(parent) {

}

DateStartEnd::DateStartEnd(const QDate &fromDate, const QDate &toDate, const bool isCurrent) {
    m_dateFrom = fromDate;
    m_dateTo = toDate;
    m_isCurrent = isCurrent;
}

DateStartEnd::DateStartEnd(const int &fromYear, const int &fromMonth, const int &toYear, const int &toMonth, const bool isCurrent) {
    m_dateFrom = QDate(fromYear, fromMonth, 1);
    m_dateTo = QDate(toYear, toMonth, 1);
    m_isCurrent = false;
}

QString DateStartEnd::toString() {
    QString data = QString("%1/%2 - ").arg(m_dateFrom.month()).arg(m_dateFrom.year());
    m_isCurrent ? data += QString("Present") : data += QString("%3/%4\n").arg(m_dateTo.month()).arg(m_dateTo.year());
    return data;
}


void DateStartEnd::write(QJsonObject &json) {
    json["dateFrom"] = m_dateFrom.toString("M/yyyy");
    json["dateTo"] = m_isCurrent ? "Present" : m_dateTo.toString("M/yyyy");
    json["isCurrent"] = m_isCurrent;
}


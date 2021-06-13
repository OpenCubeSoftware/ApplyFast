#include "datestartend.h"

DateStartEnd::DateStartEnd(QObject *parent) : QObject(parent) {

}

DateStartEnd::DateStartEnd(const QDate &fromDate, const QDate &toDate) {
    m_dateFrom = fromDate;
    m_dateTo = toDate;
}

DateStartEnd::DateStartEnd(const int &fromYear, const int &fromMonth, const int &toYear, const int &toMonth) {
    m_dateFrom = QDate(fromYear, fromMonth, 1);
    m_dateTo = QDate(toYear, toMonth, 1);
}

QString DateStartEnd::toString() {
    return QString("%1/%2 - %3/%4\n").arg(m_dateFrom.month()).arg(m_dateFrom.year()).arg(m_dateTo.month()).arg(m_dateTo.year());
}

void DateStartEnd::write(QJsonObject &json) {
    json["dateFrom"] = m_dateFrom.toString("M/yyyy");
    json["dateTo"] = m_dateTo.toString("M/yyyy");
}


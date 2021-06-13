#ifndef DATESTARTEND_H
#define DATESTARTEND_H
#include <QDate>
#include <QObject>
#include <QDebug>
#include <QJsonObject>

class DateStartEnd : public QObject {
    Q_OBJECT
public:
    explicit DateStartEnd(QObject *parent = nullptr);
    DateStartEnd(const QDate &fromDate, const QDate &toDate);
    DateStartEnd(const int &fromYear, const int &fromMonth, const int &toYear, const int &toMonth);
    QString toString();
    void write(QJsonObject &json);
private:
    QDate m_dateFrom;
    QDate m_dateTo;
};

#endif // DATESTARTEND_H

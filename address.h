#ifndef ADDRESS_H
#define ADDRESS_H

#include <QObject>
#include <QJsonObject>

class Address : public QObject {
    Q_OBJECT
public:
    explicit Address(QObject *parent = nullptr);
    Address(QString &address1, QString &address2, QString &city, QString &postcode, QString &state, QString &country);
    Address(QString &address1, QString &city, QString &postcode, QString &state, QString &country);
    Address(QString &address1, QString &address2, QString &city, QString &postcode);
    Address(QString &address1, QString &city, QString &postcode);
    QString toString();
    void write(QJsonObject &json) const;

    const QString &address1() const;
    void setAddress1(const QString &newAddress1);

    const QString &address2() const;
    void setAddress2(const QString &newAddress2);

    const QString &city() const;
    void setCity(const QString &newCity);

    const QString &state() const;
    void setState(const QString &newState);

    const QString &postcode() const;
    void setPostcode(const QString &newPostcode);

    const QString &country() const;
    void setCountry(const QString &newCountry);

private:
    QString m_address1;
    QString m_address2;
    QString m_city;
    QString m_state;
    QString m_postcode;
    QString m_country;
};

#endif // ADDRESS_H

#include "address.h"

Address::Address(QObject *parent) : QObject(parent) {

}

Address::Address(QString &address1, QString &address2, QString &city, QString &postcode, QString &state, QString &country) {
    m_address1 = address1;
    m_address2 = address2;
    m_city = city;
    m_postcode = postcode;
    m_state = state;
    m_country = country;
}

Address::Address(QString &address1, QString &city, QString &postcode, QString &state, QString &country) {
    m_address1 = address1;
    m_city = city;
    m_postcode = postcode;
    m_state = state;
    m_country = country;
}

Address::Address(QString &address1, QString &address2, QString &city, QString &postcode) {
    m_address1= address1;
    m_address2=address2;
    m_city = city;
    m_postcode = postcode;
}

Address::Address(QString &address1, QString &city, QString &postcode) {
    m_address1 = address1;
    m_city = city;
    m_postcode = postcode;
}

QString Address::toString() {
    QString data = m_address1 + "\n";
    if (!m_address2.isEmpty())
        data += m_address2 + "\n";
    data += m_city + "\n " + m_postcode + "\n";
    if (!m_state.isEmpty())
        data += m_state + "\n";
    if (!m_country.isEmpty())
        data += m_country+ "\n";

    return data;
}

void Address::write(QJsonObject &json) const {
    json["address1"] = m_address1;
    json["address2"] = m_address2;
    json["city"] = m_city;
    json["state"] = m_state;
    json["postcode"] = m_postcode;
    json["country"] = m_country;
}

const QString &Address::address1() const {
    return m_address1;
}

const QString &Address::address2() const {
    return m_address2;
}

void Address::setAddress2(const QString &newAddress2) {
    m_address2 = newAddress2;
}

const QString &Address::city() const {
    return m_city;
}

void Address::setCity(const QString &newCity) {
    m_city = newCity;
}

const QString &Address::state() const {
    return m_state;
}

void Address::setState(const QString &newState) {
    m_state = newState;
}

const QString &Address::postcode() const {
    return m_postcode;
}

void Address::setPostcode(const QString &newPostcode) {
    m_postcode = newPostcode;
}

const QString &Address::country() const {
    return m_country;
}

void Address::setCountry(const QString &newCountry) {
    m_country = newCountry;
}

void Address::setAddress1(const QString &newAddress1) {
    m_address1 = newAddress1;
}


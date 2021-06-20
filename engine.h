#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include "applicantdetails.h"
#include "jobitem.h"
#include "educationitem.h"

class Engine : public QObject {
    Q_OBJECT
public:
    explicit Engine(QObject *parent = nullptr);
private:
    ApplicantDetails * applicant;

signals:

};

#endif // ENGINE_H

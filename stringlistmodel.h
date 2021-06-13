#ifndef STRINGLISTMODEL_H
#define STRINGLISTMODEL_H

#include <QAbstractListModel>

class StringListModel : public QAbstractListModel
{
public:
    explicit StringListModel(QObject *parent = nullptr);
};

#endif // STRINGLISTMODEL_H

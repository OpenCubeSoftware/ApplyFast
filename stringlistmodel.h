#ifndef STRINGLISTMODEL_H
#define STRINGLISTMODEL_H

#include <QAbstractListModel>

class StringListModel : public QAbstractListModel {
public:
    explicit StringListModel(QObject *parent = nullptr);


    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    void addString(QString str);
    QStringList outputData();
private:
    QStringList dataList;
};

#endif // STRINGLISTMODEL_H

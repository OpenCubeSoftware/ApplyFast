#include "stringlistmodel.h"

StringListModel::StringListModel(QObject *parent) : QAbstractListModel(parent) {

}

int StringListModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return dataList.length();
}

QVariant StringListModel::data(const QModelIndex &index, int role) const {
    if (index.row() < 0 || index.row() >= dataList.count())
        return QVariant();
    QString dataString = dataList[index.row()];
    if (role == Qt::DisplayRole)
        return dataString;
    if (role == Qt::EditRole)
        return dataString;
    return QVariant();
}

bool StringListModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (!index.isValid())
        return false;
    QString dataString = dataList[index.row()];
    bool somethingChanged = false;

    switch(role) {
    case Qt::EditRole:
        if (dataString != value.toString()) {
            dataString = value.toString();
            dataList[index.row()] = dataString;
            somethingChanged = true;
        }
    }
    if (somethingChanged) {
        emit dataChanged(index,index);
        return true;
    }
    return false;
}

Qt::ItemFlags StringListModel::flags(const QModelIndex &index) const {
    if (!index.isValid())
        return QAbstractItemModel::flags(index);
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

void StringListModel::addString(QString str) {
    const int index = dataList.size();
    beginInsertRows(QModelIndex(),index,index);
    dataList.append(str);
    endInsertRows();
}

QStringList StringListModel::outputData() {
    return dataList;
}

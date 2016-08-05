#include "myfilesystemmodel.h"
#include <QDebug>

Qt::ItemFlags MyFileSystemModel::flags(const QModelIndex & index) const
{
    if (index.column() == 0)
        return QFileSystemModel::flags(index) | Qt::ItemIsEditable;
    return QFileSystemModel::flags((index));
}

QVariant MyFileSystemModel::data(const QModelIndex &index, int role) const
{
    qDebug() << index.row();
    return QFileSystemModel::data(index, role);
}

void MyFileSystemModel::fetchMore(const QModelIndex &parent)
{
//    int remain = _totalRow - _currentRow;
//    int batchSize = remain <= 20 ? remain : 20;

//    beginInsertRows(parent, _currentRow, _currentRow + batchSize - 1);
//    _currentRow += batchSize;
//    endInsertRows();
    QFileSystemModel::fetchMore(parent);
}

bool MyFileSystemModel::canFetchMore(const QModelIndex &parent) const
{
//    return _currentRow < _totalRow;
    return QFileSystemModel::canFetchMore(parent);
}


int MyFileSystemModel::rowCount(const QModelIndex &parent) const
{
//    return _currentRow;
    return QFileSystemModel::rowCount(parent);
}

int MyFileSystemModel::getTotalRow(const QModelIndex &parent)
{
    return QFileSystemModel::rowCount(parent);
}

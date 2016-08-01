#include "myfilesystemmodel.h"

Qt::ItemFlags MyFileSystemModel::flags(const QModelIndex & index) const
{
    if (index.column() == 0)
        return QFileSystemModel::flags(index) | Qt::ItemIsEditable;
    return QFileSystemModel::flags((index));
}

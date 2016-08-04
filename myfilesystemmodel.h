#ifndef MYFILESYSTEMMODEL_H
#define MYFILESYSTEMMODEL_H

#include <QFileSystemModel>

class MyFileSystemModel: public QFileSystemModel
{
public:
    MyFileSystemModel(QObject *parent = 0) : QFileSystemModel(parent) {
        _totalRow = 0;
        _currentRow = 0;
    }
    Qt::ItemFlags flags(const QModelIndex & index) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
    bool canFetchMore(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    void fetchMore(const QModelIndex &parent) Q_DECL_OVERRIDE;
    int rowCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
//    QModelIndex setRootPath(const QString &newPath);
    int getTotalRow(const QModelIndex &parent);
    int _totalRow, _currentRow;
};

#endif // MYFILESYSTEMMODEL_H

#ifndef MYFILESYSTEMMODEL_H
#define MYFILESYSTEMMODEL_H

#include <QFileSystemModel>

class MyFileSystemModel: public QFileSystemModel
{
public:
    MyFileSystemModel(QObject *parent = 0) : QFileSystemModel(parent) {}
    Qt::ItemFlags flags(const QModelIndex & index) const Q_DECL_OVERRIDE;
};

#endif // MYFILESYSTEMMODEL_H

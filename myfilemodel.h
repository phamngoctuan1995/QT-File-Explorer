#ifndef MYFILEMODEL_H
#define MYFILEMODEL_H

#include <QAbstractItemModel>

class myfilemodel: public QAbstractItemModel
{
    enum Column{NAME, SIZE, TYPE, DATE, LASTCOLUMN};
public:
    myfilemodel();
};

#endif // MYFILEMODEL_H

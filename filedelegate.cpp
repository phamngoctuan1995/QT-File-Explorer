#include "filedelegate.h"
#include <QLineEdit>
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QModelIndex>
#include <QDebug>
#include <QRect>
#include <QFileSystemModel>
#include <QSize>

void FileDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
           const QModelIndex &index) const
{
//    if (!index.row() % 1)
        QStyledItemDelegate::paint(painter, option, index);
//      QRect iconRect = option.rect;
//      QRect filenameRect = option.rect;

//      QIcon fileIcon = qvariant_cast<QIcon>(index.data(QFileSystemModel::FileIconRole));
//      QString fileName = qvariant_cast<QString>(index.data(Qt::DisplayRole));

//      iconRect.setRight(filenameRect.right() + 10);
//      iconRect.setTop(filenameRect.top() + 10);
//      iconRect.setBottom(filenameRect.bottom() - 10);
//      iconRect.setRight(iconRect.left() + iconRect.bottom() - iconRect.top());

//      filenameRect.setLeft(iconRect.right() + 20);
//      int w = (iconRect.right() - iconRect.left())/2;
//      int h = (iconRect.bottom() - iconRect.top())/2;
//      painter->drawPixmap(QPoint( iconRect.left() + w / 2, iconRect.top() + h / 2), fileIcon.pixmap(w,h));
//      painter->drawText(filenameRect, fileName);
}

QSize FileDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QStyledItemDelegate::sizeHint(option, index);
    QSize size(100, 50);
    return size;
}

QWidget* FileDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                      const QModelIndex &index) const
{
    return new QLineEdit(parent);
}

void FileDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if (index.column() == 0)
    {
        QLineEdit *le = qobject_cast<QLineEdit*>(editor);
        QString text = qvariant_cast<QString>(index.data());
        le->setText(text);
    }
}

void FileDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                  const QModelIndex &index) const
{
    if (index.column() == 0)
    {
        QLineEdit *le = qobject_cast<QLineEdit*>(editor);
        model->setData(index, QVariant::fromValue(le->text()));
    }
}

void FileDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}

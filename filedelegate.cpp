#include "filedelegate.h"
#include <QLineEdit>
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QModelIndex>

void FileDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
           const QModelIndex &index) const
{
     QStyledItemDelegate::paint(painter, option, index);
}

//QSize sizeHint(const QStyleOptionViewItem &option,
//               const QModelIndex &index)
//{

//}

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

#include "filedelegate.h"
#include <QLineEdit>
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QModelIndex>
#include <QDebug>
#include <QRect>
#include <QFileSystemModel>
#include <QSize>
#include <QFontMetrics>
#include <QListView>
#include <QApplication>
#include <QMouseEvent>
#include <QMenu>
#include <QLabel>
#include <QMovie>
#include <QFileInfo>
#include <QCursor>
#include <QTimer>
#include <QPoint>

FileDelegate::FileDelegate(QWidget *parent = 0) : QStyledItemDelegate(parent)
{
    _gif = new QMovie;
    _oldDir = "";
    _label = new QLabel;
    _label->setWindowFlags(Qt::CustomizeWindowHint);
    _isShow = false;
    _timer = new QTimer;
    _oldPoint = new QPoint;
    _label->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    _label->setWindowFlags(Qt::Window | Qt::CustomizeWindowHint);

    connect(this, SIGNAL(MouseOverGif(QString, const QStyleOptionViewItem&, const QModelIndex&))
            , SLOT(GifHint(QString,const QStyleOptionViewItem&, const QModelIndex&)));
}

void FileDelegate::GifHint(QString fPath, const QStyleOptionViewItem& option, const QModelIndex& index)
{
    if (option.state & QStyle::State_MouseOver)
    {
      if (_oldDir == fPath)
          return;
      else
          _oldDir = fPath;

      delete _gif;
      _gif = new QMovie(fPath);

      if (!_gif->isValid())
          return;

      QPoint mouseCursor = QCursor::pos();
//      _gif->setScaledSize(QSize(200, 150));
      _gif->start();
      _label->move(mouseCursor + QPoint(10, 10));
      QSize size = _gif->currentPixmap().scaled(200,200, Qt::KeepAspectRatio).size();
      _gif->setScaledSize(size);
      _label->setMovie(_gif);
      _label->resize(size);
      _label->show();
      _isShow = true;
    }
    else
      if (fPath == _oldDir && _isShow)
      {
          _isShow = false;
          _oldDir = "";
          _label->close();
      }
}

void FileDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
           const QModelIndex &index) const
{
      QStyledItemDelegate::paint(painter, option, index);

      QString fPath = qvariant_cast<QString>(index.data(QFileSystemModel::FilePathRole));

      if (fPath.contains(".gif", Qt::CaseInsensitive) || fPath.contains(".png", Qt::CaseInsensitive))
              emit MouseOverGif(fPath, option, index);

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

bool FileDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mEvent = static_cast<QMouseEvent*>(event);
        if(mEvent->button() == Qt::MouseButton::RightButton)
        {
            QMenu menu;
            if (index.row() % 2)
                menu.addAction("Them");
            else
                menu.addAction("xoa");
            menu.exec(mEvent->globalPos());
        }
    }
    return QStyledItemDelegate::editorEvent(event, model, option, index);
}

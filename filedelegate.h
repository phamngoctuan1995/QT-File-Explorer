#ifndef FILEDELEGATE_H
#define FILEDELEGATE_H

#include <QStyledItemDelegate>

class QLabel;
class QString;
class QMovie;
class QTimer;
class QPoint;
class QVideoWidget;
class QMediaPlayer;
class QMediaPlaylist;

class FileDelegate: public QStyledItemDelegate
{
    Q_OBJECT
public:
    FileDelegate(QWidget *parent);

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const Q_DECL_OVERRIDE;
    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const Q_DECL_OVERRIDE;
    void FileDelegate::updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &/* index */) const Q_DECL_OVERRIDE;

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const Q_DECL_OVERRIDE;
    void setEditorData(QWidget *editor, const QModelIndex &index) const Q_DECL_OVERRIDE;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const Q_DECL_OVERRIDE;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index) Q_DECL_OVERRIDE;

signals:
    void MouseOverGif(QString, const QStyleOptionViewItem&, const QModelIndex&, int) const;

private slots:
    void GifHint(QString, const QStyleOptionViewItem&, const QModelIndex&, int);
//    void HintShow();
private:
    QMovie *_gif;
    QString _oldDir;
    QLabel *_label;
    bool _isShow, _isWait;
    QTimer *_timer;
    QPoint *_oldPoint;
    QVideoWidget *_videoWidget;
    QMediaPlayer *_mediaPlayer;
    QMediaPlaylist *_playList;
};

#endif // FILEDELEGATE_H

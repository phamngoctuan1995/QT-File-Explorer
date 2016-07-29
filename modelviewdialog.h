#ifndef MODELVIEWDIALOG_H
#define MODELVIEWDIALOG_H

#include <QDialog>

namespace Ui {
class modelviewdialog;
}

class QStringListModel;

class modelviewdialog : public QDialog
{
    Q_OBJECT

public:
    explicit modelviewdialog(QWidget *parent = 0);
    ~modelviewdialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::modelviewdialog *ui;
    QStringListModel *model;
};

#endif // MODELVIEWDIALOG_H

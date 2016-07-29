#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QFileSystemModel;
class QCompleter;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_treeView_clicked(const QModelIndex &index);

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_le_path_returnPressed();

    void on_le_path_editingFinished();

private:
    Ui::MainWindow *ui;
    QCompleter *_pathCompleter;
    QFileSystemModel *_dirModel, *_fileModel;
    QString _oldDir;
};

#endif // MAINWINDOW_H

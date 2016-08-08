#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include <QModelIndex>

namespace Ui {
class MainWindow;
}

class QFileSystemModel;
class QCompleter;
class FileDelegate;
class MyFileSystemModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void initModel();
    void updateNavigator();
    bool goToPath(const QString &path, bool isNavigation);
    void keyPressEvent(QKeyEvent* e);
    ~MainWindow();

private slots:
    void on_treeView_clicked(const QModelIndex &index);

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_le_path_returnPressed();

    void on_le_path_editingFinished();

    void on_btn_back_clicked();

    void on_btn_forward_clicked();

    void on_btn_refresh_clicked();

    void on_le_search_textChanged(const QString &arg1);

    void on_filemodel_loaded(const QString &path);

    void on_tableView_customContextMenuRequested(const QPoint &pos);

private:
    Ui::MainWindow *ui;
    QCompleter *_pathCompleter;
    QFileSystemModel *_dirModel;
    MyFileSystemModel *_fileModel;
    QString _oldDir;
    QStack<QString> *_backWard, *_forWard;
    FileDelegate * _fileDelegate;
    QModelIndex _rootIndex;
};

#endif // MAINWINDOW_H

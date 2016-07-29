#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>

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
    void initModel();
    void updateNavigator();
    bool goToPath(const QString &path, bool isNavigation);
    ~MainWindow();

private slots:
    void on_treeView_clicked(const QModelIndex &index);

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_le_path_returnPressed();

    void on_le_path_editingFinished();

    void on_btn_back_clicked();

    void on_btn_forward_clicked();

private:
    Ui::MainWindow *ui;
    QCompleter *_pathCompleter;
    QFileSystemModel *_dirModel, *_fileModel;
    QString _oldDir;
    QStack<QString> *_backWard, *_forWard;

};

#endif // MAINWINDOW_H

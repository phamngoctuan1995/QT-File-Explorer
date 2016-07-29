#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileSystemModel>
#include <QDebug>
#include <QMessageBox>
#include <QCompleter>
#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initModel();

    _pathCompleter = new QCompleter(this);
    _pathCompleter->setModel(_fileModel);
    ui->le_path->setCompleter(_pathCompleter);

    _backWard = new QStack<QString>();
    _forWard = new QStack<QString>();
    updateNavigator();
}

void MainWindow::initModel()
{
    QString rootPath = _oldDir = "C:/";
    ui->le_path->setText(rootPath);

    _dirModel = new QFileSystemModel(this);
    _dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    _dirModel->setRootPath(rootPath);
    ui->treeView->setModel(_dirModel);

    _fileModel = new QFileSystemModel(this);
    _fileModel->setFilter(QDir::NoDotAndDotDot | QDir::AllEntries);
    _fileModel->setRootPath(rootPath);
    ui->tableView->setModel(_fileModel);
}

void MainWindow::updateNavigator()
{
    ui->btn_back->setEnabled(!_backWard->empty());
    ui->btn_forward->setEnabled(!_forWard->empty());
}

bool MainWindow::goToPath(const QString &path, bool isNavigation = false)
{
    QDir dir(path);
    if (dir.exists())
    {
        ui->tableView->setRootIndex(_fileModel->setRootPath(path));
        ui->le_path->setText(path);

        if (!isNavigation)
        {
            _backWard->push_back(_oldDir);
            _forWard->clear();
            updateNavigator();
        }
        _oldDir = path;
        return true;
    }

    return false;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _dirModel;
    delete _fileModel;
    delete _forWard;
    delete _backWard;
    delete _pathCompleter;
}

void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    QString path = _dirModel->filePath(index);
    goToPath(path);
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    QString path = _fileModel->filePath(index);
    if (!goToPath(path))
        QDesktopServices::openUrl(QUrl(path));
}

void MainWindow::on_le_path_returnPressed()
{
    QString path = ui->le_path->text();
    QDir dir(path);
    if(!goToPath(path))
       QMessageBox::critical(this, "File Explorer", "Can't find '" + path + "'", QMessageBox::Ok);
}

void MainWindow::on_le_path_editingFinished()
{
    ui->le_path->setText(_oldDir);
}

void MainWindow::on_btn_back_clicked()
{
    QString path = _backWard->top();
    _backWard->pop_back();
    _forWard->push_back(_oldDir);
    goToPath(path, true);
    updateNavigator();
}

void MainWindow::on_btn_forward_clicked()
{
    QString path = _forWard->top();
    _forWard->pop_back();
    _backWard->push_back(_oldDir);
    goToPath(path, true);
    updateNavigator();
}

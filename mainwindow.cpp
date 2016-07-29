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
    QString rootPath = "C:/";

    _dirModel = new QFileSystemModel(this);
    _dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    _dirModel->setRootPath(rootPath);
    ui->treeView->setModel(_dirModel);

    _fileModel = new QFileSystemModel(this);
    _fileModel->setFilter(QDir::NoDotAndDotDot | QDir::AllEntries);
    _fileModel->setRootPath(rootPath);
    ui->tableView->setModel(_fileModel);

    _pathCompleter = new QCompleter(this);
    _pathCompleter->setModel(_fileModel);
    ui->le_path->setText(rootPath);
    ui->le_path->setCompleter(_pathCompleter);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    QString path = _dirModel->filePath(index);
    ui->tableView->setRootIndex(_fileModel->setRootPath(path));
    ui->le_path->setText(path);
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    QString path = _fileModel->filePath(index);
    QDir dir(path);
    if (dir.exists())
    {
        ui->tableView->setRootIndex(_fileModel->setRootPath(path));
        ui->le_path->setText(path);
        _oldDir = path;
    }
    else
        QDesktopServices::openUrl(QUrl(path));
}

void MainWindow::on_le_path_returnPressed()
{
    QString path = ui->le_path->text();
    QDir dir(path);
    if(dir.exists())
    {
        ui->tableView->setRootIndex(_fileModel->setRootPath(path));
        _oldDir = path;
    }
    else
       QMessageBox::critical(this, "File Explorer", "Can't find '" + path + "'", QMessageBox::Ok);
}

void MainWindow::on_le_path_editingFinished()
{
    ui->le_path->setText(_oldDir);
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filedelegate.h"
#include <QFileSystemModel>
#include <QDebug>
#include <QMessageBox>
#include <QCompleter>
#include <QDesktopServices>
#include <QUrl>
#include "myfilesystemmodel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("File Explorer");

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
    _oldDir = "";
    ui->le_path->setText(_oldDir);

    _dirModel = new QFileSystemModel(this);
    _dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    _dirModel->setRootPath(_oldDir);
    ui->treeView->setModel(_dirModel);

    _fileModel = new MyFileSystemModel(this);
    _fileModel->setFilter(QDir::NoDotAndDotDot | QDir::AllEntries);
    _fileModel->setRootPath(_oldDir);
    ui->tableView->setModel(_fileModel);

    _fileDelegate = new FileDelegate(this);
    ui->tableView->setItemDelegateForColumn(0, _fileDelegate);
    ui->tableView->setEditTriggers(QAbstractItemView::EditKeyPressed | QAbstractItemView::SelectedClicked);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
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
//        _fileModel->setRootPath(path);
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
    delete _fileDelegate;
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


void MainWindow::on_btn_refresh_clicked()
{
    goToPath(_oldDir, true);
}

void MainWindow::on_le_search_textChanged(const QString &arg1)
{
//    fileModel->findChildren(QRegularExpression(arg1));
}


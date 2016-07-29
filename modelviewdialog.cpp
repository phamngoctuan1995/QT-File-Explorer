#include "modelviewdialog.h"
#include "ui_modelviewdialog.h"
#include <QStringList>
#include <QStringListModel>

modelviewdialog::modelviewdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modelviewdialog)
{
    ui->setupUi(this);
    QStringList data;
    data << "mot" << "hai" << "ba";

    model = new QStringListModel();
    model->setStringList(data);

    ui->listView->setModel(model);
    ui->comboBox->setModel(model);

    ui->listView->setEditTriggers(QAbstractItemView::AnyKeyPressed |
                                QAbstractItemView::DoubleClicked);

}

modelviewdialog::~modelviewdialog()
{
    delete ui;
    delete model;
}

void modelviewdialog::on_pushButton_clicked()
{
    int count = model->rowCount();
    model->insertRow(count);
    ui->listView->edit(model->index(count));
}

void modelviewdialog::on_pushButton_2_clicked()
{
    QModelIndex index = ui->listView->currentIndex();
    model->insertRow(index.row());
    ui->listView->edit(index);
}

void modelviewdialog::on_pushButton_3_clicked()
{
    QModelIndex index = ui->listView->currentIndex();
    model->removeRow(index.row());
}

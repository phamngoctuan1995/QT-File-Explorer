/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_back;
    QPushButton *btn_forward;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *le_path;
    QPushButton *btn_refresh;
    QLineEdit *le_search;
    QHBoxLayout *horizontalLayout_5;
    QTreeView *treeView;
    QTableView *tableView;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1010, 692);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_back = new QPushButton(centralWidget);
        btn_back->setObjectName(QStringLiteral("btn_back"));

        horizontalLayout->addWidget(btn_back);

        btn_forward = new QPushButton(centralWidget);
        btn_forward->setObjectName(QStringLiteral("btn_forward"));

        horizontalLayout->addWidget(btn_forward);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        le_path = new QLineEdit(centralWidget);
        le_path->setObjectName(QStringLiteral("le_path"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(le_path->sizePolicy().hasHeightForWidth());
        le_path->setSizePolicy(sizePolicy);
        le_path->setMinimumSize(QSize(230, 0));

        horizontalLayout_2->addWidget(le_path);

        btn_refresh = new QPushButton(centralWidget);
        btn_refresh->setObjectName(QStringLiteral("btn_refresh"));

        horizontalLayout_2->addWidget(btn_refresh);

        le_search = new QLineEdit(centralWidget);
        le_search->setObjectName(QStringLiteral("le_search"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(le_search->sizePolicy().hasHeightForWidth());
        le_search->setSizePolicy(sizePolicy1);
        le_search->setMinimumSize(QSize(230, 0));

        horizontalLayout_2->addWidget(le_search);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        treeView = new QTreeView(centralWidget);
        treeView->setObjectName(QStringLiteral("treeView"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy2);
        treeView->setMinimumSize(QSize(100, 0));
        treeView->setMaximumSize(QSize(300, 16777215));

        horizontalLayout_5->addWidget(treeView);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->horizontalHeader()->setVisible(true);
        tableView->horizontalHeader()->setHighlightSections(true);

        horizontalLayout_5->addWidget(tableView);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        btn_back->setText(QApplication::translate("MainWindow", "Backward", 0));
        btn_forward->setText(QApplication::translate("MainWindow", "Forward", 0));
        btn_refresh->setText(QApplication::translate("MainWindow", "Refresh", 0));
#ifndef QT_NO_TOOLTIP
        le_search->setToolTip(QApplication::translate("MainWindow", "Search", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        le_search->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        le_search->setInputMask(QString());
        le_search->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

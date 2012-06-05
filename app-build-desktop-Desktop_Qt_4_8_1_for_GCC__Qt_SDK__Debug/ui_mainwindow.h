/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Jun 5 01:11:06 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionProut;
    QAction *actionOpen_DSM;
    QAction *actionNew_Clustering;
    QAction *actionLoad_Clustering;
    QAction *actionSave_Clustering;
    QAction *actionSave_Clustering_As;
    QAction *actionExport_As;
    QAction *actionExit_2;
    QAction *actionPropagation_Cost;
    QAction *actionRedraw;
    QAction *actionFind;
    QAction *actionFind_2;
    QAction *actionShow_Row_Labels;
    QAction *actionAbout;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuLol;
    QMenu *menuFile;
    QMenu *menuMetrics;
    QMenu *menuView;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionProut = new QAction(MainWindow);
        actionProut->setObjectName(QString::fromUtf8("actionProut"));
        actionOpen_DSM = new QAction(MainWindow);
        actionOpen_DSM->setObjectName(QString::fromUtf8("actionOpen_DSM"));
        actionNew_Clustering = new QAction(MainWindow);
        actionNew_Clustering->setObjectName(QString::fromUtf8("actionNew_Clustering"));
        actionLoad_Clustering = new QAction(MainWindow);
        actionLoad_Clustering->setObjectName(QString::fromUtf8("actionLoad_Clustering"));
        actionSave_Clustering = new QAction(MainWindow);
        actionSave_Clustering->setObjectName(QString::fromUtf8("actionSave_Clustering"));
        actionSave_Clustering_As = new QAction(MainWindow);
        actionSave_Clustering_As->setObjectName(QString::fromUtf8("actionSave_Clustering_As"));
        actionExport_As = new QAction(MainWindow);
        actionExport_As->setObjectName(QString::fromUtf8("actionExport_As"));
        actionExit_2 = new QAction(MainWindow);
        actionExit_2->setObjectName(QString::fromUtf8("actionExit_2"));
        actionPropagation_Cost = new QAction(MainWindow);
        actionPropagation_Cost->setObjectName(QString::fromUtf8("actionPropagation_Cost"));
        actionRedraw = new QAction(MainWindow);
        actionRedraw->setObjectName(QString::fromUtf8("actionRedraw"));
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName(QString::fromUtf8("actionFind"));
        actionFind_2 = new QAction(MainWindow);
        actionFind_2->setObjectName(QString::fromUtf8("actionFind_2"));
        actionShow_Row_Labels = new QAction(MainWindow);
        actionShow_Row_Labels->setObjectName(QString::fromUtf8("actionShow_Row_Labels"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuLol = new QMenu(menubar);
        menuLol->setObjectName(QString::fromUtf8("menuLol"));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuMetrics = new QMenu(menubar);
        menuMetrics->setObjectName(QString::fromUtf8("menuMetrics"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuLol->menuAction());
        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuMetrics->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuLol->addAction(actionProut);
        menuFile->addAction(actionOpen_DSM);
        menuFile->addSeparator();
        menuFile->addAction(actionNew_Clustering);
        menuFile->addAction(actionLoad_Clustering);
        menuFile->addSeparator();
        menuFile->addAction(actionSave_Clustering);
        menuFile->addAction(actionSave_Clustering_As);
        menuFile->addSeparator();
        menuFile->addAction(actionExport_As);
        menuFile->addSeparator();
        menuFile->addAction(actionExit_2);
        menuMetrics->addAction(actionPropagation_Cost);
        menuView->addAction(actionRedraw);
        menuView->addSeparator();
        menuView->addAction(actionFind_2);
        menuView->addSeparator();
        menuView->addAction(actionShow_Row_Labels);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);
        QObject::connect(actionExit_2, SIGNAL(activated()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionProut->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionOpen_DSM->setText(QApplication::translate("MainWindow", "Open DSM", 0, QApplication::UnicodeUTF8));
        actionNew_Clustering->setText(QApplication::translate("MainWindow", "New Clustering", 0, QApplication::UnicodeUTF8));
        actionLoad_Clustering->setText(QApplication::translate("MainWindow", "Load Clustering", 0, QApplication::UnicodeUTF8));
        actionSave_Clustering->setText(QApplication::translate("MainWindow", "Save Clustering", 0, QApplication::UnicodeUTF8));
        actionSave_Clustering_As->setText(QApplication::translate("MainWindow", "Save Clustering As", 0, QApplication::UnicodeUTF8));
        actionExport_As->setText(QApplication::translate("MainWindow", "Export As", 0, QApplication::UnicodeUTF8));
        actionExit_2->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionPropagation_Cost->setText(QApplication::translate("MainWindow", "Propagation Cost", 0, QApplication::UnicodeUTF8));
        actionRedraw->setText(QApplication::translate("MainWindow", "Redraw", 0, QApplication::UnicodeUTF8));
        actionFind->setText(QApplication::translate("MainWindow", "Find", 0, QApplication::UnicodeUTF8));
        actionFind_2->setText(QApplication::translate("MainWindow", "Find", 0, QApplication::UnicodeUTF8));
        actionShow_Row_Labels->setText(QApplication::translate("MainWindow", "Show Row Labels", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        menuLol->setTitle(QApplication::translate("MainWindow", "|", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuMetrics->setTitle(QApplication::translate("MainWindow", "Metrics", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

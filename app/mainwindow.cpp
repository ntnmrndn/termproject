#include <QStringList>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "controller.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    controller(*this)
{
    ui->setupUi(this);
    QObject::connect(ui->actionOpen_DSM, SIGNAL(activated()), &(this->controller), SLOT(setFileName()));

    ui->listWidget->item(0)->setText("Ici bientot dynamique");
    ui->listWidget->item(1)->setText("Quand nanbei aura finit");
}

MainWindow::~MainWindow()
{
    delete ui;
}



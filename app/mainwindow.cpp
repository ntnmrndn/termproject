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
    QObject::connect(ui->actionOpen_DSM, SIGNAL(activated()), &(this->controller), SLOT(openDSM()));

    //open about message box
    QObject::connect(ui->actionAbout, SIGNAL(activated()), &(this->controller), SLOT(showAbout()));


    ui->listWidget->item(0)->setText("Ici bientot dynamique");
    ui->listWidget->item(1)->setText("Quand nanbei aura finit");


}

void MainWindow::drawNames(const QVector<QString> & vec)
{
  vec;
}

MainWindow::~MainWindow()
{
    delete ui;
}



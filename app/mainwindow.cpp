#include <qDebug>
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
}

void MainWindow::drawNames(const QVector<QString> & vec)
{
  for (int i = 0; i < vec.size(); ++i)
    ui->listWidget->addItem(vec[i]);
}

void MainWindow::drawTable(const QVector<QString> &names, const QVector<QString>data)
{
  // gaffe segfault
  ui->tableWidget->setRowCount(names.size());
  ui->tableWidget->setColumnCount(data[0].size());
   for (int i = 0; i < names.size(); ++i)
     ui->tableWidget->setVerticalHeaderItem(i, new QTableWidgetItem(names[i]));
}


MainWindow::~MainWindow()
{
  delete ui;
}



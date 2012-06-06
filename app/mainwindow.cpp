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
  ui->tableWidget->setColumnCount(data[0].size() / 2 + data[0].size() % 2);
   for (int i = 0; i < names.size(); ++i)
     {
       QString s;
       s.setNum(i);
       s += " ";
       s +=  names[i];
       ui->tableWidget->setVerticalHeaderItem(i, new QTableWidgetItem(s));
     }
   for (int i = 0; i < names.size(); ++i)
     {
       for (int j = 0; j < data[0].size(); j += 2)
         {
           QString s(data[i][j]);
           ui->tableWidget->setItem(i, j / 2, new QTableWidgetItem(s));
         }
     }
}


MainWindow::~MainWindow()
{
  delete ui;
}



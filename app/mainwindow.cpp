#include <QSize>
#include <qDebug>
#include <QStringList>
#include <QTableWidget>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "controller.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    controller(*this)
{
  ui->setupUi(this);
  ui->Form->hide();
  QObject::connect(ui->actionOpen_DSM, SIGNAL(activated()), &(this->controller), SLOT(openDSM()));
    //open about message box
  QObject::connect(ui->Ok, SIGNAL(clicked()), &(this->controller), SLOT(Add()));
  QObject::connect(ui->Up, SIGNAL(clicked()), &(this->controller), SLOT(Up()));
  QObject::connect(ui->Down, SIGNAL(clicked()), &(this->controller), SLOT(Down()));
  QObject::connect(ui->Delete, SIGNAL(clicked()), &(this->controller), SLOT(Delete()));
  QObject::connect(ui->actionRedraw, SIGNAL(activated()), &(this->controller), SLOT(Draw()));
  QObject::connect(ui->actionAbout, SIGNAL(activated()), &(this->controller), SLOT(showAbout()));
  QObject::connect(ui->tableWidget, SIGNAL(itemChanged(QTableWidgetItem *)),
                   &(this->controller), SLOT(itemChanged(QTableWidgetItem *)));
  QObject::connect(ui->actionSave_DSM, SIGNAL(activated()), &(this->controller), SLOT(saveDSM()));
  QObject::connect(ui->actionSave_DSM_as, SIGNAL(activated()), &(this->controller), SLOT(saveDSMAs()));
}

void MainWindow::drawNames(const QVector<QString> & vec)
{
  ui->listWidget->clear();
  for (int i = 0; i < vec.size(); ++i)
    ui->listWidget->addItem(vec[i]);
  ui->listWidget->setCurrentRow(0);
}


void MainWindow::drawTable(const QVector<QString> &names, const QVector<QString> &data)
{
  ui->tableWidget->clear();
  if (names.empty() || data.empty())
    {
      ui->tableWidget->setRowCount(0);
      ui->tableWidget->setColumnCount(0);
      return ;
    }
  ui->tableWidget->setRowCount(names.size());
  ui->tableWidget->setColumnCount(data[0].size() / 2 + data[0].size() % 2);
  ui->tableWidget->verticalHeader()->setDefaultSectionSize(20);
  ui->tableWidget->horizontalHeader()->setDefaultSectionSize(20);
   for (int i = 0; i < names.size(); ++i)
     {
       QString s;
       s.setNum(i);
       s += " ";
       s +=  names[i];
       ui->tableWidget->setVerticalHeaderItem(i, new QTableWidgetItem(s));
     }
   for (int i = 0; i < names.size(); ++i)
     for (int j = 0; j < data[0].size(); j += 2)
       {
         QString s(data[i][j] == '0' ? ' ' : 'x');
         ui->tableWidget->setItem(i, j / 2, new QTableWidgetItem(s));
       }
}


const QString MainWindow::getName() const
{
  return this->ui->lineEdit->text();
}

void MainWindow::clearName()
{
  this->ui->lineEdit->clear();
}

QListWidgetItem *MainWindow::getSelected() const
{
  QList<QListWidgetItem *> selecteds = ui->listWidget->selectedItems();
  return selecteds.empty() ? 0 : selecteds[0];
}



MainWindow::~MainWindow()
{
  delete ui;
}

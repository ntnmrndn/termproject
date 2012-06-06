#include <qDebug>
#include <QListWidgetItem>
#include <QListWidget>
#include <QList>
#include <QFileDialog>
#include <QMessageBox>
#include "controller.h"
#include "mainwindow.h"

Controller::Controller(MainWindow &win) :
  window(win),
  dsm (0)
{

}

void Controller::openDSM()
{
  delete this->dsm;
  this->dsm = new dsmFile(QFileDialog::getOpenFileName(&(this->window), tr("Open File"),
                                                       "/dsm",
                                                       tr("DSM (*.dsm)")));
  this->window.drawNames(this->dsm->getNames());
  this->window.drawTable(this->dsm->getNames(), this->dsm->getPositions());
}


void Controller::Delete()
{

  QListWidgetItem *item = this->window.getSelected();
  if (!item)
    return ;
  const QString name = item->text();
  qDebug() << name;
  delete item;
}

void Controller::Down()
{

}

void Controller::Up()
{

}

void Controller::showAbout()
{
  QMessageBox msgBox;
  msgBox.setWindowTitle("About");


  msgBox.setStandardButtons(QMessageBox::Close);
  msgBox.setText("Team members: \n\n -Antoine Marandon \n -Thibaut Schmitt \n -Gregory Barry \n -Olivier Hugon \n -Nanbou Lin \n");
  msgBox.exec();
}

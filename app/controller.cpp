#include <qDebug>
#include <QListWidgetItem>
#include <QListWidget>
#include <QList>
#include <QString>
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
  this->Draw();
}

void Controller::Add()
{
  if (!dsm)
    return ;
  this->dsm->Add(this->window.getName());
  this->window.clearName();
  this->Draw();
}


void Controller::Generate()
{
  int i = this->window.getNumber();
  int j = 0;
  QString tempname;
  for (; i ; --i)
  {
    j++;
    tempname =  "entity_" + QString::number(j) ;
    this->dsm->Add(tempname);
  }
     this->Draw();
}


void Controller::Draw()
{
  if (!dsm)
    return;
  this->window.drawNames(this->dsm->getNames());
  this->window.drawTable(this->dsm->getNames(), this->dsm->getPositions());

}

void Controller::itemChanged(QTableWidgetItem *item)
{
  const QString s(item->text());
  if (s != "x")
    item->setText(" ");
  this->dsm->cellChanged(item->row(), item->column(), s == "x");
}


void Controller::Delete()
{
  QListWidgetItem *item = this->window.getSelected();
  if (!item)
    return ;
 dsm->Delete(item->text());
  delete item;
  this->Draw();
}

void Controller::Down()
{
  QListWidgetItem *item = this->window.getSelected();
  if (!item)
    return ;
  dsm->Down(item->text());
  this->window.drawNames(this->dsm->getNames());
  this->Draw();
}

void Controller::Up()
{
  QListWidgetItem *item = this->window.getSelected();
  if (!item)
    return ;
  dsm->Up(item->text());
  this->window.drawNames(this->dsm->getNames());
  this->Draw();
}

void Controller::showAbout()
{
  QMessageBox msgBox;
  msgBox.setWindowTitle("About");
  msgBox.setStandardButtons(QMessageBox::Close);
  msgBox.setText("Team members: \n\n -Antoine Marandon \n -Thibaut Schmitt \n -Gregory Barry \n -Olivier Hugon \n -Nanbou Lin \n");
  msgBox.exec();
}


void Controller::newDSM()
{
  this->dsm = new dsmFile(QFileDialog::getSaveFileName(&this->window, QObject::tr("Save \
your DSM file as"), "./", QObject::tr("Design Structure Matrix (*.dsm);;All Files (*)")));
  this->Draw();
}

void Controller::saveDSM()
{
  //appel foncion dsm save
  this->dsm->saveFile();
}

void Controller::saveDSMAs()
{
  QString newFileName = QFileDialog::getSaveFileName(&this->window, QObject::tr("Save \
your DSM file as"), "./", QObject::tr("Design Structure Matrix (*.dsm);;All Files (*)"))\
    ;
  this->dsm->getFile().setFileName(newFileName);
  this->dsm->setNameFile(newFileName);
  this->dsm->saveFile();
}

void Controller::exportDSMAsClustering()
{
    if (this->dsm)
    {
        QString name;
        name = this->dsm->getFileName();
        name.replace(name.size() - 3,3,"clsx");
        this->clsx = new clsxfile(name);
        this->clsx->exportDSM(this->dsm);
    }
}

void Controller::SortNames()
{
    this->dsm->SortNames();
    this->Draw();
}

void Controller::loadCLSX()
{
    if (this->dsm)
    {
        //new clsx
        this->clsx = new clsxfile(QFileDialog::getOpenFileName(&(this->window), tr("Open File"),
                                                             "/clsx",
                                                             tr("CLSX (*.clsx)")));
        this->clsx->loaderCLSX();
        //need to draw again
        this->Draw();
    }
}

Controller::~Controller()
{
  delete dsm;
}

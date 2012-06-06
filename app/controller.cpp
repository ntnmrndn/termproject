#include <QFileDialog>
#include <QMessageBox>
#include "controller.h"
#include "mainwindow.h"

Controller::Controller(MainWindow &win) :
  fileName(""),
  window(win)
{

}

void Controller::setFileName()
{
  fileName = (QFileDialog::getOpenFileName(&(this->window), tr("Open File"),
                                           "/dsm",
                                           tr("DSM (*.dsm)")));
}

void Controller::showAbout()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("About");


    msgBox.setStandardButtons(QMessageBox::Close);
    msgBox.setText("Team members: \n\n -Antoine Marandon \n -Thibaut Schmitt \n -Gregory Barry \n -Olivier Hugon \n -Nanbou Lin \n");
    msgBox.exec();
}

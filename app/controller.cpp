#include <QFileDialog>
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

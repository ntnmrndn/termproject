#include <iostream>
#include <QFile>
#include <QApplication>
#include <QtDebug>
#include "clsxfile.h"

//constructeur avec un nom de fichier
clsxfile::clsxfile(const QString &name):
  _fileName(name),
  _file(name)
{

}

void clsxfile::exportDSM(dsmFile *_dsm)
{
    qDebug() << "on est ici";
}

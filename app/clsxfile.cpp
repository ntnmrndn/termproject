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

QString clsxfile::getName()
{
  return _fileName;
}

ParseXml &clsxfile::getParser()
{
    return _parser;
}

QFile& clsxfile::getFile()
{
    return _file;
}

void clsxfile::exportDSM(dsmFile *_dsm)
{
    QFile       _export(this->getName());
    //on creer le fichier
    if (_export.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        //on appel la fonction parsexml qui ecrit dans le fichier
        this->getParser().exportDSM(_export, *_dsm);


        //on ferme le fichier
        _export.close();
    }
}

void clsxfile::loaderCLSX()
{
    //load le fichier dans clsx
    _parser.openFile(this->getName());
}

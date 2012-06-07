#include <iostream>
#include <QFile>
#include <QApplication>
#include <QtDebug>

#include "dsmfile.h"

dsmFile::dsmFile(const QString &n):
  _fileName(n),
  _file(n),
  _num(0),
  _posFile(0)
{
  if (checkFile())
    {
      setNum();
      setPositions();
      setNames();
    }
}

void dsmFile::setNameFile(QString& fileName)
{
  _fileName = fileName;
}

void dsmFile::setNum()
{
  _file.seek(0);
  if (!_file.atEnd())
    {
      QString tmp = _file.readLine();
      _posFile += tmp.size();
      _num = tmp.toInt();
    }
}

void dsmFile::setModifNum(int nb)
{
      _num = nb;
}

void dsmFile::setPositions()
{
  _file.seek(_posFile);
  if (!_file.atEnd())
    {
      for (int i = 0 ; i < _num ; ++i)
	{
	  QString tmp = _file.readLine();
	  _posFile += tmp.size();
	  _positions.append(tmp.simplified().trimmed());
	}
    }
}

void dsmFile::setNames()
{
  _file.seek(_posFile);
  while (!_file.atEnd())
    {
      QString tmp = _file.readLine().simplified().trimmed();
      _names.append(tmp);
    }
}

void dsmFile::cellChanged(int, int, bool)
{

}


void dsmFile::Delete(const QString &module)
{
    int find = 0;
    int j;

    for ( j = 0; j < getNames().count(); ++j)
    {
        if(getNames()[j] == module)
        {
         find = 1;
         break;
        }
    }
    if (find == 1)
    {
        //decrement le nombre de module
        this->setModifNum(getNum()-1);
        //supprime son nom dans le tableau des modules et jointure
        if (j+1 == getNames().count())
        {
            getNames().pop_back();
            getPositions().pop_back();
        }
        else
        {
            getNames().remove(j);
            getPositions().remove(j);
        }
    }
}


void dsmFile::Down(const QString &module)
{
    //on echange avec l'element du dessus
    //attention si dernier element
    int find = 0;
    int j;
    QString temp;
    for ( j = 0; j < getNames().count(); ++j)
    {
        if(getNames()[j] == module)
        {
         find = 1;
         break;
        }
    }
    if (find == 1)
    {

        //move son nom dans le tableau des modules et jointure
        if (j+1 != getNames().count())
        {
            //tableau module
            temp = getNames()[j];
            getNames()[j] = getNames()[j+1];
            getNames()[j+1] = temp;
            //tableau position
            temp = getPositions()[j];
            getPositions()[j] = getPositions()[j+1];
            getPositions()[j+1] = temp;
        }
    }
}


void dsmFile::Up(const QString &module)
{
    //on echange avec l'element du dessus
    //attention si premier element
    int find = 0;
    int j;
    QString temp;
    for ( j = 0; j < getNames().count(); ++j)
    {
        if(getNames()[j] == module)
        {
         find = 1;
         break;
        }
    }
    if (find == 1)
    {

        //move son nom dans le tableau des modules et jointure
        if (j != 0)
        {
            //tableau module
            temp = getNames()[j];
            getNames()[j] = getNames()[j-1];
            getNames()[j-1] = temp;
            //tableau position
            temp = getPositions()[j];
            getPositions()[j] = getPositions()[j-1];
            getPositions()[j-1] = temp;
        }
    }
}

QVector<QString> &dsmFile::getNames()
{
  return _names;
}

QVector<QString> &dsmFile::getPositions()
{
  return _positions;
}

int dsmFile::getNum()
{
  return _num;
}


void dsmFile::Add(const QString &)
{

}

QString dsmFile::getFileName()
{
  return _fileName;
}

int dsmFile::checkFile()
{
  if (!_file.exists())
    {
      qDebug() << "File doesn't exist";
      return 0;
    }
  if (!_file.open(QIODevice::ReadOnly))
    {
      qDebug() << "Couldn't open the file";
      return 0;
    }
  return 1;
}

void dsmFile::closeFile()
{
  _file.close();
}

void dsmFile::saveFile()
{
  if (this)
    {
      this->closeFile();
      if (_file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
        {
	  QTextStream out(&_file);
	  out << getNum() << endl;
	  for (int i = 0 ; i < getNum() ; ++i)
            {
	      out << getPositions()[i] << endl;
            }
	  for (int i = 0 ; i < getNum() ; ++i)
            {
	      out << getNames()[i] << endl;
            }
	  this->closeFile();
        }
      if (this->_file.open(QIODevice::ReadOnly))
	return;
    }
}

QFile& dsmFile::getFile()
{
  return _file;
}

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
}

void dsmFile::setFileName(QString& fileName)
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

QVector<QString> &dsmFile::getNames()
{
  return _names;
}

QVector<QString> dsmFile::getPositions()
{
  return _positions;
}

int dsmFile::getNum()
{
  return _num;
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

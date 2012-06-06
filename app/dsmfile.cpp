#include <iostream>
#include <QFile>
#include <QApplication>
#include <QtDebug>

#include "dsmfile.h"

dsmFile::dsmFile(const QString &n):
  _fileName(n),
  _num(0)
{
}

void dsmFile::setFileName(QString& fileName)
{
  _fileName = fileName;
}

void dsmFile::setNum(int number)
{
  _num = number;
}

void dsmFile::setPositions(QVector<QString> &positions)
{
  _positions = positions;
}

void dsmFile::setNames(QVector<QString> &names)
{
  _names = names;
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

int readfile(QString fileName)
{
  dsmFile *data = new dsmFile(fileName);
  QVector<QString> positions;
  QVector<QString> names;
  QFile file(fileName);

  if (!file.exists())
    {
      qDebug() << "File doesn't exist";
      return 0;
    }
  if (!file.open(QIODevice::ReadOnly))
    {
      qDebug() << "Couldn't open the file";
      return 0;
    }
  data->setFileName(fileName);
  if (!file.atEnd())
    {
      QString tmp = file.readLine().simplified().trimmed();
      data->setNum(tmp.toInt());
      for (int i = 0; i < data->getNum() ; ++i)
	{
	  tmp = file.readLine().simplified().trimmed();
	  positions.append(tmp);
	}
      data->setPositions(positions);
      for (int i = 0 ; i < data->getNum() ; ++i)
	{
	  tmp = file.readLine().simplified().trimmed();
	  names.append(tmp);
	}
      data->setNames(names);
    }
  qDebug() << data->getNum();
  qDebug() << data->getNames();
  qDebug() << data->getPositions();
  file.close();
  return 1;
}

#ifndef READFILE_H
# define READFILE_H

#include <QString>
#include <QVector>
#include <QFile>

class dsmFile
{
 public:
  dsmFile(const QString &);
  int checkFile();
  void setPosFile();

  void setNum();
  void setPositions();
  void setNames();
  void setFileName(QString& fileName);
  
  int getNum();
  QVector<QString> &getNames();
  QVector<QString> getPositions();
  QString getFileName();
  QFile getFile();
  void closeFile();

 private:
  QVector<QString> _positions;
  QVector<QString> _names;
  QString _fileName;
  QFile _file;
  int _num;
  int _posFile;
};

#endif
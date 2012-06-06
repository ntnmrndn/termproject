#ifndef READFILE_H
# define READFILE_H

#include <QString>
#include <QVector>

class dsmFile
{
 public:
  dsmFile();
  ~dsmFile();
  void setNum(int);
  void setPositions(QVector<QString>&);
  void setNames(QVector<QString>&);
  void setFileName(QString&);

  int getNum();
  QVector<QString> getNames();
  QVector<QString> getPositions();
  QString getFileName();

 private:
  QVector<QString> _positions;
  QVector<QString> _names;
  QString _fileName;
  int _num;
};

int readfile(QString);

#endif

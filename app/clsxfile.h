#ifndef CLSXFILE_H
#define CLSXFILE_H

#include <QString>
#include <QVector>
#include <QFile>
#include "dsmfile.h"
#include "ParseXml.h"

class clsxfile
{
public:

    clsxfile(const QString &);
    void exportDSM(dsmFile *);
    //QString getFileName();
    //QFile& getFile();

    //void closeFile();
    //void saveFile();

private:
    QString     _fileName;
    QFile       _file;
    ParseXml    _parser;
};

#endif // CLSXFILE_H

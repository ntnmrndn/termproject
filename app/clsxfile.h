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

    QString getName();
    ParseXml &getParser();
    QFile& getFile();

    void loaderCLSX();
    void exportDSM(dsmFile *);

private:
    QString     _fileName;
    QFile       _file;
    ParseXml    _parser;
};

#endif // CLSXFILE_H

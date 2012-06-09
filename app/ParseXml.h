#ifndef _PARSEXML_H_
# define _PARSEXML_H_

#include <QObject>
#include <QtXml>
#include <QDomDocument>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include "dsmfile.h"

class ParseXml : public QObject 
{
	Q_OBJECT
	public:
		ParseXml();
		~ParseXml();
	public slots : 
		int	openFile(QString filename);
		int readFile(QDomElement root);
		int	getInfo();
        void exportDSM(QFile &, dsmFile& );
	private : 
		QDomDocument doc;
};

#endif

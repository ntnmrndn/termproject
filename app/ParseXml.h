#ifndef _PARSEXML_H_
# define _PARSEXML_H_

#include <QObject>
#include <QtXml>
#include <QDomDocument>
#include <QMessageBox>
#include <QFile>

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
	private : 
		QDomDocument doc;
};

#endif
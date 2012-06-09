# ifndef _NEWFILE_H_
# define _NEWXML_H_

#include <QObject>
#include <QtXml>
#include <QDomDocument>
#include <QMessageBox>
#include <QFile>

class		NewXml : public QObject{
	Q_OBJECT

	public :
		NewXml();
		~NewXml();

	public slots :
		int	WriteFile(QString toWrite, QDomElement root);
		int	setInfo();

	private :
		QDomDocument	doc;
		QString			toWrite;

};

#endif
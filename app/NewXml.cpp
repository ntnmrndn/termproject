#include "NewXml.h"

NewXml::NewXml()
{
	qDebug() << "value 1 "; 
	QDomDocument doc("CLSXfile");
	QFile file("test.clsx");
	qDebug() << "value 10 ";
	if (!file.open(QIODevice::ReadWrite)){
		qDebug() << "value 4 "; 
		exit;
	}
	if (!doc.setContent(&file)){
		qDebug() << "value 5 "; 
		file.close();
		exit;
	}
	file.close();
	qDebug() << " value 9 ";

	QDomElement root = doc.documentElement(); //recupere le ficher dans un Dom
	if(root.tagName() != "cluster"){
		qDebug() << "value 6 ";
		exit;
	}

}

NewXml::~NewXml()
{

}

int		NewXml::WriteFile(QString toWrite, QDomElement root){


	
	return 0;
}

int		SetInfo(){

}
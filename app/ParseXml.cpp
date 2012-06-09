
#include "ParseXml.h"

//Penser a faire un index des erreurs



ParseXml::ParseXml()
{
	
}

ParseXml::~ParseXml()
{

}

int		ParseXml::getInfo(){
	return 0;
}

int		ParseXml::openFile(QString filename){
	
	qDebug() << "value 1 "; 
	QDomDocument doc("CLSXfile");
	QFile file(filename);
	qDebug() << "value 10 ";
	if (!file.open(QIODevice::ReadOnly)){
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
	//parseur

	QDomElement root = doc.documentElement();
	if(root.tagName() != "cluster"){
		qDebug() << "value 6 ";
		exit;
	}
	this->readFile(root);
}

int		ParseXml::readFile(QDomElement root){

	QDomNode n = root.firstChild();
	QDomNodeList tab;
	QDomElement e;
	int i=0;
	QDomNode tmp;
	QDomElement temp; // Ce temp sert a stocker le premier noeud si il existe
	QString affichage;
	QMessageBox a(0);

	while (!n.isNull()){ 
		e = n.toElement();
		if (!e.isNull()){  //on test si il est null (comme thibaut)
			affichage = e.attribute("name"); // récupère l'attribut
			QDomNodeList tab = e.childNodes(); // crée un tableau avec les valeurs des attibuts, la taille est donnee par childnode
			for(i=0;i<tab.length();i++){ // on parcour la profondeur du noeud egale a la taille du tableau
				tmp = tab.item(i); // on stocke la valeur courante dans le tmp
				if (!tmp.isNull()){
					QDomElement p = tmp.toElement();
					affichage = affichage + " " + p.attribute("name"); //on stocke la valeur dans la variable d'affichage
					qDebug() << "value : " << affichage;
					temp = p.firstChildElement(); //on teste si le fils de l'element courant est un node
					if (temp.hasChildNodes()){
						this->readFile(p);//on descend d'un niveau dans le fichier
					}
				}
			}
		} 
		n = n.nextSibling();
	}
	return 0;
}
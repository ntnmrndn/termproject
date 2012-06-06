
#include "ParseXml.h"

//Penser a faire un index des erreurs



ParseXml::ParseXml()
{

}

ParseXml::~ParseXml()
{

}

int		ParseXml::readFile(){

	qDebug() << "value 1 "; 
	//QMessageBox::information(this, "Nom de la balise", "Le nom de la balise est ");
	//ouverture du fichier
	QDomDocument doc("CLSXfile");
	QFile file("test.clsx");
	qDebug() << "value 10 ";
	if (!file.open(QIODevice::ReadOnly)){
		qDebug() << "value 4 "; 
		return 1;
	}
	if (!doc.setContent(&file)){
		qDebug() << "value 5 "; 
		file.close();
		return 2;
	}
	file.close();
	qDebug() << " value 9 ";
	//parseur

	QDomElement root = doc.documentElement();
	if(root.tagName() != "cluster"){
		qDebug() << "value 6 ";
		return 3;
	}
	QDomNode n = root.firstChild();
	QDomNodeList tab;
	QDomElement e;
	int i=0;
	QDomNode tmp;
	QString affichage;
	QMessageBox a(0);

	while (!n.isNull()){
		qDebug() << "value 3 "; 
		e = n.toElement(); //on recupere le premiere element
		if (!e.isNull()){  //on test si il est null (comme thibaut)
			if (e.tagName() == "group"){ //on checke le tag de l'element pour savoir si ca matche bien le fichier
				affichage = e.attribute("name"); // récupère l'attribut
				tab = e.childNodes(); // crée un tableau avec les valeurs des attibuts, la taille est donnee par childnode
				for(i=0;i<tab.length();i++){ // on parcour la profondeur du noeud egale a la taille du tableau
					tmp = tab.item(i); // on stocke la valeur courante dans le tmp
					QDomElement p = tmp.toElement();
					affichage = affichage + " " + p.attribute("name"); //on stocke la valeur dans la variable d'affichage
					qDebug() << "value : " << affichage; 
				}
				
				//a.setText(affichage); // affichage dans un QMessageBox
				//a.exec();
			}
			n = n.nextSibling();
		}
	}
	return 0;
}
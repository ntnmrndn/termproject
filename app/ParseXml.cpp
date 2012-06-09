
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

void     ParseXml::exportDSM(QFile &pfile, dsmFile &dsm)
{

    QTextStream out(&pfile);
    out << "<cluster xmlns=\"http://rise.cs.drexel.edu/minos/clsx\">" << endl;
    out << "<group name=\"ROOT\">" << endl;
    for (int i = 0 ; i < dsm.getNames().count(); ++i)
    {
        out << "<item name=\"" << dsm.getNames()[i]<< "\" />" << endl;
    }
    out << "</group>" << endl;
    out << " </cluster>" << endl;

    QMessageBox msgBox;
    msgBox.setText("Export finish");
    msgBox.exec();
}

int		ParseXml::openFile(QString filename){
	
	QDomDocument doc("CLSXfile");
	QFile file(filename);
	if (!file.open(QIODevice::ReadOnly)){
		exit;
	}
	if (!doc.setContent(&file)){
		file.close();
		exit;
	}
	file.close();
	//parseur

	QDomElement root = doc.documentElement();
	if(root.tagName() != "cluster"){
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

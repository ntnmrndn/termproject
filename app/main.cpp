#include <QApplication>
#include <qdebug.h>
#include "mainwindow.h"
#include "ParseXml.h"

int  main(int argc, char *argv[])
{
	qDebug() << "toto";
	QApplication app(argc, argv);
	// ParseXml test;

	app.setOrganizationName("EPITECH");
	app.setApplicationName("Term project");
	MainWindow main_Window;
	main_Window.show();
        //	test.readFile();
	return (app.exec());
}

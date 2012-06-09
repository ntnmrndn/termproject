#include <QApplication>
#include <qdebug.h>
#include "mainwindow.h"
#include "ParseXml.h"

int  main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	ParseXml *test = new ParseXml();

	app.setOrganizationName("EPITECH");
	app.setApplicationName("Term project");
	//MainWindow main_Window;
	//main_Window.show();
	test->openFile("test.clsx");
	return (app.exec());
}

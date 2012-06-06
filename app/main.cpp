#include <QApplication>
#include "mainwindow.h"

int  main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  app.setOrganizationName("EPITECH");
  app.setApplicationName("Term project");
  MainWindow main_Window;
  main_Window.show();

  return (app.exec());
}

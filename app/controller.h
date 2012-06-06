#ifndef CONTROLLER_H_
# define CONTROLLER_H_

#include <QMainWindow>
#include <QString>
#include "dsmfile.h"

class MainWindow;

class Controller : public QObject
{
  Q_OBJECT
  public:
  Controller(MainWindow &);
public slots:
  void openDSM();
  void showAbout();
private:
  MainWindow    &window;
  dsmFile       *dsm;
};

#endif /* !CONTROLLER_H_ */

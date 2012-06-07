#ifndef CONTROLLER_H_
# define CONTROLLER_H_

#include <QTableWidget>
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
  void saveDSM();
  void saveDSMAs();
  void showAbout();
  void Delete();
  void Up();
  void Add();
  void Down();
  void Draw();
  void itemChanged(QTableWidgetItem * item);
  ~Controller();
private:
  MainWindow    &window;
  dsmFile       *dsm;
};

#endif /* !CONTROLLER_H_ */

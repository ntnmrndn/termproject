#ifndef CONTROLLER_H_
# define CONTROLLER_H_

#include <QTableWidget>
#include <QMainWindow>
#include <QString>
#include "dsmfile.h"
#include "clsxfile.h"

class MainWindow;

class Controller : public QObject
{
  Q_OBJECT
  public:
  Controller(MainWindow &);
  ~Controller();

public slots:
  void Generate();
  void openDSM();
  void newDSM();
  void saveDSM();
  void saveDSMAs();
  void showAbout();
  void Delete();
  void Up();
  void Add();
  void Down();
  void Draw();
  void SortNames();
  void loadCLSX();
  void itemChanged(QTableWidgetItem * item);
  void exportDSMAsClustering();
private:
  MainWindow    &window;
  dsmFile       *dsm;
  clsxfile      *clsx;
};

#endif /* !CONTROLLER_H_ */

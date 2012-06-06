#ifndef CONTROLLER_H_
# define CONTROLLER_H_

#include <QMainWindow>
#include <QString>

class MainWindow;

class Controller : public QObject
{
  Q_OBJECT
  public:
  Controller(MainWindow &);
public slots:
  void setFileName();
  void showAbout();
private:
  QString fileName;
  MainWindow    &window;
};

#endif /* !CONTROLLER_H_ */

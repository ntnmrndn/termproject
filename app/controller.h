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
private:
  QString fileName;
  MainWindow    &window;
};

#endif /* !CONTROLLER_H_ */

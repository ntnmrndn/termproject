#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class MainWindow;
}
#include "controller.h"

class Controller;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
  Ui::MainWindow *ui;
   Controller controller;
};

#endif // MAINWINDOW_H

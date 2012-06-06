#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QVector>

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
  void drawNames(const QVector<QString> &);
  void drawTable(const QVector<QString> &, const QVector<QString>);
private:
  Ui::MainWindow *ui;
  Controller controller;
};

#endif // MAINWINDOW_H

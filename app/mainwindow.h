#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidgetItem>
#include <QListWidget>
#include <QList>
#include <QFileDialog>
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
  void drawTable(const QVector<QString> &, const QVector<QString>&);
  QListWidgetItem *getSelected() const;

private:
  Ui::MainWindow *ui;
  Controller controller;
public:
};

#endif // MAINWINDOW_H

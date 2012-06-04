#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    fileName("")
{
    ui->setupUi(this);
    QObject::connect(ui->actionOpen_DSM, SIGNAL(activated()), this, SLOT(setFileName()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setFileName()
{

  fileName = (QFileDialog::getOpenFileName(this, tr("Open File"),
                                           "/dsm",
                                           tr("DSM (*.dsm)")));
}

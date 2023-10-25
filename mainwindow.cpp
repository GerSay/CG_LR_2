#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _timer = new QTimer(this);
    connect(_timer, SIGNAL(timeout()), this, SLOT(timer()));
    _timer->start(16);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _timer;
}

void MainWindow::timer()
{
    _star.setRotation(_star.getRotation() + qDegreesToRadians(_star.getSpeed()));
    _star.setSpeed(_star.getSpeed() - 0.1f);
}

void MainWindow::paintEvent(QPaintEvent *event)
{

}

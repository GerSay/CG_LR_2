#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "lr_2.h"

#include <QMainWindow>
#include <QRandomGenerator>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void timer();

private:
    Ui::MainWindow *ui;

    QList<double> m = QList<double>{0};
    QRandomGenerator gen = QRandomGenerator();

    Star _star = {QPointF(), (double)gen.bounded(360.0f), 0, 1.0f, 1.0f, Qt::white};
    QTimer* _timer;
    bool _needReflect = false;
    bool _drawStar = false;

    void paintEvent(QPaintEvent* event);
};

#endif // MAINWINDOW_H

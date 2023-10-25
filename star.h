#ifndef STAR_H
#define STAR_H

#include <QWidget>

class Star : public QWidget
{
    Q_OBJECT

    QPointF _pos;
    double _angle;
    double _rotation;
    double _rSpeed;
    double _speed;
    QColor _color;

public:
    explicit Star(QWidget *parent = nullptr);

    QPointF getPos() const;
    double getAngle() const;
    double getRotation() const;
    double getRSpeed() const;
    double getSpeed() const;
    QColor getColor() const;

    void setPos(double x, double y);
    void setPos(QPointF* p);
    void setAngle(double a);
    void setRotation(double r);
    void setRSpeed(double rs);
    void setSpeed(double s);
    void setColor(double c);


    void operator+(QPointF* p);
    double& operator+(double a);


    void operator-(QPointF* p);


    void operator+=(QPointF* p);


signals:



};

#endif // STAR_H

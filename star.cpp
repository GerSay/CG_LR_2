#include "star.h"

Star::Star(QWidget *parent)
    : QWidget{parent}
{}


QPointF Star::getPos() const { return _pos; }
double Star::getAngle() const { return _angle; }
double Star::getRotation() const { return _rotation; }
double Star::getRSpeed() const { return _rSpeed; }
double Star::getSpeed() const { return _speed; }
QColor Star::getColor() const { return _color; }

void Star::setPos(double x, double y) { _pos.setX(x); _pos.setY(y); }
void Star::setPos(QPointF *p) { _pos = *p; }
void Star::setAngle(double a) { _angle = a; }
void Star::setRotation(double r) { _rotation = r; }
void Star::setRSpeed(double rs) { _rSpeed = rs; }
void Star::setSpeed(double s) { _speed = s; }
void Star::setColor(double c) { _color = c; }


void Star::operator+(QPointF* p)
{
    this->_pos.setX(this->_pos.x() + p->x());
    this->_pos.setY(this->_pos.y() + p->y());
}

void Star::operator-(QPointF* p)
{
    this->_pos.setX(this->_pos.x() - p->x());
    this->_pos.setY(this->_pos.y() - p->y());
}

void Star::operator+=(QPointF* p) {
    this->_pos = this->_pos + *p;
}


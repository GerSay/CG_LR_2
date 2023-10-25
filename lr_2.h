#ifndef LR_2_H
#define LR_2_H

#include "affinematrix.h"
#include "star.h"


class LR_2
{
public:
    LR_2();
    ~LR_2();

    QPointF transform(QPointF p, _AffineMatrix trns);
    void transform(QPointF* p, uint32_t n, _AffineMatrix trns);
    QPolygonF getPolygon(uint32_t n);
    void drawVerticalLine(QPainter& painter);
    void drawHorisontalLine(QPainter& painter);
    QPolygonF drawStar(QPainter& painter, QPointF c, double r, bool rx, bool ry);
    QPolygonF getStar(QPointF c, double r, bool rx, bool ry);

    void keyPressEvent(QKeyEvent* event);

};

#endif // LR_2_H

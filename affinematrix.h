#ifndef AFFINEMATRIX_H
#define AFFINEMATRIX_H

#include "_AffineMatrix.h"

class AffineMatrix
{
public:
    static _AffineMatrix rotation(double angle);
    static _AffineMatrix translation(double dx, double dy);
    static _AffineMatrix scale(double kx, double ky);
    static _AffineMatrix reflection(bool rx, bool ry);
    static _AffineMatrix sequence(_AffineMatrix* seq, int count);

};

#endif // AFFINEMATRIX_H

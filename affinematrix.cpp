#include "affinematrix.h"

#include <QtMath>

_AffineMatrix AffineMatrix::rotation(double angle)
{
    auto m = _AffineMatrix::identical(3);

    m.at(0, 0) = qCos(angle);
    m.at(0, 1) = -qSin(angle);
    m.at(1, 0) = qSin(angle);
    m.at(1, 1) = qCos(angle);

    return m;
}

_AffineMatrix AffineMatrix::translation(double dx, double dy)
{
    auto m = _AffineMatrix::identical(3);
    m.at(0, 2) = dx;
    m.at(1, 2) = dy;

    return mat;
}

_AffineMatrix AffineMatrix::scale(double kx, double ky)
{
    auto m = _AffineMatrix::identical(3);
    m.at(0, 0) = kx;
    m.at(1, 1) = ky;

    return m;
}

_AffineMatrix AffineMatrix::reflection(bool rx, bool ry)
{
    auto m = _AffineMatrix::identical(3);
    m.at(0, 0) = rx ? -1 : 1;
    m.at(1, 1) = ry ? -1 : 1;

    return m;
}

_AffineMatrix AffineMatrix::sequence(_AffineMatrix* seq, int count)
{
    auto m = _AffineMatrix::identical(3);
    for (int i = count - 1; i >= 0; i--) m = m.multiply(seq[i]);

    return m;
}

#include "_affinematrix.h"

_AffineMatrix::_AffineMatrix(uint32_t nRows, uint32_t nCols)
                                : _nRows(nRows),
                                  _nCols(nCols),
                                  _data(new double[nRows * nCols]) {}
_AffineMatrix::_AffineMatrix(uint32_t nRows, uint32_t nCols, double* data)
                                : _AffineMatrix(nRows, nCols)
{
    for (uint32_t i = 0; i < nRows * nCols; i++) _data[i] = data[i];
}
_AffineMatrix::_AffineMatrix(const _AffineMatrix& other)
                                : _AffineMatrix(other._nRows, other._nCols, other._data) {}


_AffineMatrix::~_AffineMatrix() { delete[] _data; }


_AffineMatrix& _AffineMatrix::operator=(const _AffineMatrix& other)
{
    _nCols = other._nCols;
    _nRows = other._nRows;
    _data = new double[_nRows * _nCols];

    for (uint32_t i = 0; i < _nRows * _nCols; i++) _data[i] = other._data[i];

    return *this;
}

uint32_t _AffineMatrix::nRows() const { return _nRows; }
uint32_t _AffineMatrix::nCols() const { return _nCols; }
double& _AffineMatrix::at(uint32_t nRow, uint32_t nCol) { return _data[nCol + nRow * _nCols]; }
const double& _AffineMatrix::at(uint32_t nRow, uint32_t nCol) const { return _data[nCol + nRow * _nCols]; }
double* _AffineMatrix::data() { return _data; }


_AffineMatrix _AffineMatrix::multiply(const _AffineMatrix& other) const
{
    _AffineMatrix res = zero(_nRows, other._nCols);
    for (uint32_t iRow = 0; iRow < _nRows; iRow++)
        for (uint32_t iCol = 0; iCol < other._nCols; iCol++)
            for (uint32_t i = 0; i < _nCols; i++)
                res.at(iRow, iCol) += at(iRow, i) * other.at(i, iCol);

    return res;
}

_AffineMatrix _AffineMatrix::zero(uint32_t nRows, uint32_t nCols)
{
    auto zero = _AffineMatrix(nRows, nCols);
    for (uint32_t i = 0; i < nRows * nCols; i++) zero._data[i] = 0;

    return zero;
}

_AffineMatrix _AffineMatrix::identical(uint32_t n)
{
    auto identical = zero(n, n);
    for (uint32_t i = 0; i < n; i++) identical.at(i, i) = 1;

    return identical;
}

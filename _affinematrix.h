#ifndef _AFFINEMATRIX_H
#define _AFFINEMATRIX_H

#include <ios>

class _AffineMatrix
{
public:
    _AffineMatrix(uint32_t nRows, uint32_t nCols);
    _AffineMatrix(uint32_t nRows, uint32_t nCols, double* data);
    _AffineMatrix(const _AffineMatrix& other);

    ~_AffineMatrix();


    _AffineMatrix& operator=(const _AffineMatrix& other);

    uint32_t nRows() const;
    uint32_t nCols() const;
    double& at(uint32_t nRow, uint32_t nCol);
    const double& at(uint32_t nRow, uint32_t nCol) const;
    double* data();

    _AffineMatrix multiply(const _AffineMatrix& other) const;

    static _AffineMatrix zero(uint32_t nRows, uint32_t nCols);
    static _AffineMatrix identical(uint32_t n);


private:
    double* _data;
    uint32_t _nRows;
    uint32_t _nCols;

};

#endif // _AFFINEMATRIX_H

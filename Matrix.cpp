#include "Matrix.h"
#include <vector>
Matrix::Matrix(int row, int coll) {
    this->row = row,
    this->coll = coll,
    this->data = std::vector<double>(coll * row, 0.0);
}


Matrix::~Matrix() = default;

double& Matrix::operator()(int i, int j) {
    if (i < 0 || i >= row || j < 0 || j >= coll) {
        throw std::out_of_range("Matrix indices out of range");
    }
    return data[i * coll + j];
}

const double& Matrix::operator()(int i, int j) const {
    if (i < 0 || i >= row || j < 0 || j >= coll) {
        throw std::out_of_range("Matrix indices out of range");
    }
    return data[i * coll + j];
}

Matrix Matrix::operator*(const Matrix &other) const {
    // For multiplication, the number of columns of the left matrix must equal the number of rows of the right matrix.
    if (coll != other.row) {
        throw std::invalid_argument("Matrix dimensions are incompatible for multiplication.");
    }
    // The result matrix will have 'row' rows and 'other.coll' columns.
    Matrix result(row, other.coll);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < other.coll; ++j) {
            for (int k = 0; k < coll; ++k) {
                result(i, j) += (*this)(i, k) * other(k, j);
            }
        }
    }
    return result;
}





//
// Created by faikz on 13/03/2025.
//

#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <iostream>
class Matrix{
private:
    int row, coll;
    std::vector<double> data;
public:
    Matrix(int row, int coll);
    ~Matrix();
    Matrix operator*(const Matrix &other) const;
    const double& operator()(int i, int j) const;
    double& operator()(int i, int j);
};
#endif //MATRIX_H

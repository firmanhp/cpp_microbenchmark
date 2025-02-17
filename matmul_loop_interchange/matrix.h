#pragma once

#include <vector>
#include <cassert>
#include <cstdint>

namespace mat {

struct Matrix {
  int rows, cols;
  std::vector<double> data;

  Matrix(int r, int c) : data(r*c), rows(r), cols(c) {}

  const double* operator[](int row) const {
    return &data[row * cols];
  }

  double* operator[](int row) {
    return &data[row * cols];
  }

};

void Randomize(Matrix& mat);
void Zero(Matrix& mat);
void Identity(Matrix& mat);
void Multiply(const Matrix& a, const Matrix& b, Matrix& result);
void Pow(Matrix a, int32_t pow, Matrix& result);


}
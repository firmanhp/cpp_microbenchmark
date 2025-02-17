#include "matrix.h"

#include <random>

namespace mat {

void Randomize(Matrix& matrix) {
  std::default_random_engine generator;
  std::uniform_real_distribution<float> distribution(-0.95f, 0.95f);

  for (int i = 0; i < matrix.rows; i++) {
    float sum = 0;
    for (int j = 0; j < matrix.cols; j++) {
      float value = distribution(generator);
      sum += value * value;
      matrix[i][j] = value;
    }

    // Normalize rows
    if (sum >= std::numeric_limits<float>::min()) {
      float scale = 1.0f / std::sqrt(sum);
      for (int j = 0; j < matrix.cols; j++) {
        matrix[i][j] *= scale;
      }
    }
  }
}

void Zero(Matrix& mat) {
  std::fill(mat.data.begin(), mat.data.end(), 0);
}

void Identity(Matrix& mat) {
  Zero(mat);
  assert(mat.rows == mat.cols);
  for (int i=0;i<mat.rows;++i) {
    mat[i][i] = 1;
  }
}

void Pow(Matrix a, int32_t pow, Matrix& result) {
  assert(a.rows == a.cols);
  assert(result.rows == a.rows);
  assert(result.cols == a.cols);

  Matrix temp(a.rows, a.cols);
  Identity(result);
  while (pow > 0) {
    if (pow&1) {
      // result = result*a
      Multiply(a, result, temp);
      std::swap(temp, result);
    }

    // a = a*a
    Multiply(a, a, temp);
    std::swap(a, temp);
    pow >>= 1;
  }
}

}
#include "matrix.h"

#include <limits>
#include <iostream>
#include <math.h>
#include <memory>

// src: https://github.com/dendibakh/perf-ninja/tree/main/labs/memory_bound/loop_interchange_1

using mat::Matrix;
using mat::Pow;
using mat::Identity;
using mat::Zero;
using mat::Multiply;
using mat::Randomize;
constexpr int N = 400;

namespace {
  
bool Equals(const Matrix& a, const Matrix& b) {
  constexpr int maxErrors = 10;
  const float epsilon = std::sqrt(std::numeric_limits<float>::epsilon());

  if ((a.rows != b.rows) || (a.cols != b.cols))
    return false;

  int errors = 0;
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.cols; j++) {
      float va = a[i][j];
      float vb = b[i][j];
      float error = std::abs(va - vb);
      if (error >= epsilon) {
        std::cerr << "Result[" << i << ", " << j << "] = " << va
                  << ". Expected[" << i << ", " << j << "] = " << vb
                  << std::endl;
        if (++errors >= maxErrors)
          return false;
      }
    }
  }
  return 0 == errors;
}


}


int main() {
  constexpr int k = 15;
  constexpr int k1 = 5;

  std::unique_ptr<Matrix> a = std::make_unique<Matrix>(N, N);
  std::unique_ptr<Matrix> b = std::make_unique<Matrix>(N, N);
  std::unique_ptr<Matrix> c = std::make_unique<Matrix>(N, N);
  std::unique_ptr<Matrix> d = std::make_unique<Matrix>(N, N);

  Randomize(*a);
  Zero(*b);
  Identity(*c);
  Identity(*d);
  {
    Multiply(*a, *d, *b);
    if (!Equals(*b, *a)) {
      std::cerr << "Validation Failed. a * 1" << std::endl;
      return 1;
    }
  }
  {
    Multiply(*a, *a, *b);
    Pow(*a, 2, *c);
    if (!Equals(*b, *c)) {
      std::cerr << "Validation Failed. a^2" << std::endl;
      return 1;
    }
  }
  Pow(*a, k, *b);
  Pow(*a, k1, *c);
  Pow(*a, k - k1, *d);
  Multiply(*c, *d, *a);
  if (!Equals(*a, *b)) {
    std::cerr << "Validation Failed. a^k" << std::endl;
    return 1;
  }

  std::cout << "Validation Successful" << std::endl;
  return 0;
}
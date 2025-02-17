#include "matrix.h"
#include <cassert>

namespace mat {

void Multiply(const Matrix& a, const Matrix& b, Matrix& result) {
  assert(a.cols == b.rows);
  assert(result.rows == a.rows);
  assert(result.cols == b.cols);

  Zero(result);
  for (int i=0;i<a.rows;++i) {
    for (int j=0;j<b.cols;++j) {
      for (int k=0;k<a.cols;++k) {
        result[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}

}
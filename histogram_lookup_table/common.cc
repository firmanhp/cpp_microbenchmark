#include "histogram.h"

#include <random>

namespace hist {

std::vector<uint8_t> GenerateRandom(size_t n) {
  std::vector<uint8_t> ret(n);
  std::random_device r;
  std::default_random_engine generator(r());
  // generate random integer in the closed interval [0,255]
  // the chance of selecting the default bucket is ~33%
  std::uniform_int_distribution<uint8_t> distribution(0, 255);
  for (int i = 0; i < (int)n; i++) {
    ret[i] = distribution(generator);
  }

  return ret;
}

}
#include "histogram.h"

namespace hist {

namespace {

inline int MapToBucket(uint8_t val) {
  if      (val < 13)  return 0; //   13
  else if (val < 29)  return 1; //   16
  else if (val < 41)  return 2; //   12
  else if (val < 53)  return 3; //   12
  else if (val < 71)  return 4; //   18
  else if (val < 83)  return 5; //   12
  else if (val < 100) return 6; //   17
  return 7;
}

}

std::array<size_t, NUM_BUCKETS> GroupToHistogram(std::span<const uint8_t> values) {
  std::array<size_t, NUM_BUCKETS> ret = {0};
  for (uint8_t val : values) {
    ret[MapToBucket(val)]++;
  }
  return ret;
}

}
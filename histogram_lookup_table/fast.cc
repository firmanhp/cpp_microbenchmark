#include "histogram.h"

namespace hist {

namespace {

constexpr std::array<uint8_t, 256> BUCKET_MAP = []() {
  std::array<uint8_t, 256> map = {0};
  for (int i=0;i<256;++i) {
    if      (i < 13)  map[i] = 0; //   13
    else if (i < 29)  map[i] = 1; //   16
    else if (i < 41)  map[i] = 2; //   12
    else if (i < 53)  map[i] = 3; //   12
    else if (i < 71)  map[i] = 4; //   18
    else if (i < 83)  map[i] = 5; //   12
    else if (i < 100) map[i] = 6; //   17
    else map[i] = 7;
  }
  return map;
}();

}

std::array<size_t, NUM_BUCKETS> GroupToHistogram(std::span<const uint8_t> values) {
  std::array<size_t, NUM_BUCKETS> ret = {0};
  for (uint8_t val : values) {
    ret[BUCKET_MAP[val]]++;
  }
  return ret;
}

}
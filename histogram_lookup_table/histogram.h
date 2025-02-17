#pragma once

#include <array>
#include <span>
#include <cstdint>
#include <vector>

namespace hist {

constexpr size_t NUM_BUCKETS = 8;
std::vector<uint8_t> GenerateRandom(size_t n);
std::array<size_t, NUM_BUCKETS> GroupToHistogram(std::span<const uint8_t> values);

}

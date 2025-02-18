
#include "benchmark/benchmark.h"
#include "histogram.h"

static void bench1(benchmark::State &state) {
  std::vector<uint8_t> values = hist::GenerateRandom(state.range(0));

  // Run the benchmark
  for (auto _ : state) {
    auto output = hist::GroupToHistogram(values);
    benchmark::DoNotOptimize(output);
  }
}

// Register the function as a benchmark
BENCHMARK(bench1)->Range(100000, 100000000);

// Run the benchmark
BENCHMARK_MAIN();

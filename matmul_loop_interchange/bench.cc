#include "benchmark/benchmark.h"
#include "matrix.h"
#include <memory>

using namespace mat;

static void BM_Pow(benchmark::State &state) {
  const int N = state.range(0);
  std::unique_ptr<Matrix> a = std::make_unique<Matrix>(N, N);
  Randomize(*a);

  std::unique_ptr<Matrix> result = std::make_unique<Matrix>(N, N);
  Zero(*result);

  for (auto _ : state) {
    Pow(*a, 2021, *result);
    benchmark::DoNotOptimize(result);
  }
}

// Register the function as a benchmark
BENCHMARK(BM_Pow)->RangeMultiplier(2)->Range(8, 600);

// Run the benchmark
BENCHMARK_MAIN();



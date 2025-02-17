#include "benchmark/benchmark.h"
#include "matrix.h"
#include <memory>

using namespace mat;

static void BM_Pow(benchmark::State &state) {
  const int N = state.range(0);
  std::unique_ptr<Matrix> a = std::make_unique<Matrix>(N, N);
  Randomize(*a);

  std::unique_ptr<Matrix> b = std::make_unique<Matrix>(N, N);
  Zero(*b);

  for (auto _ : state) {
    Pow(*a, 2021, *b);
    benchmark::DoNotOptimize(b);
  }
}

// Register the function as a benchmark
BENCHMARK(BM_Pow)->Range(8, 600);

// Run the benchmark
BENCHMARK_MAIN();
#include <benchmark/benchmark.h>

#include "gswteos-10.h"

static void BM_specvol(benchmark::State& state) {
  for (auto _  : state) {
    gsw_specvol(10.0, 10.0, 10.0);
  }
}
BENCHMARK(BM_specvol);

static void BM_enthalpy_diff(benchmark::State& state) {
  for (auto _  : state) {
    gsw_enthalpy_diff(33.0, 10.0, 0.0, 100.0);
  }
}
BENCHMARK(BM_enthalpy_diff);

BENCHMARK_MAIN();

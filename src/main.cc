#include <benchmark/benchmark.h>

#include "gswteos-10.h"

// ---------------------------
// Volume
// ---------------------------

static void BM_specvol(benchmark::State& state) {
  for (auto _  : state) {
    gsw_specvol(10.0, 10.0, 10.0);
  }
}
BENCHMARK(BM_specvol);

static void BM_alpha(benchmark::State& state) {
  for (auto _  : state) {
    gsw_alpha(10.0, 10.0, 10.0);
  }
}
BENCHMARK(BM_alpha);

static void BM_beta(benchmark::State& state) {
  for (auto _  : state) {
    gsw_beta(10.0, 10.0, 10.0);
  }
}
BENCHMARK(BM_beta);

static void BM_specvol_sso_0(benchmark::State& state) {
  for (auto _  : state) {
    gsw_specvol_sso_0(10.0);
  }
}
BENCHMARK(BM_specvol_sso_0);

static void BM_specvol_anom_standard(benchmark::State& state) {
  for (auto _  : state) {
    gsw_specvol_anom_standard(10.0, 10.0, 10.0);
  }
}
BENCHMARK(BM_specvol_anom_standard);

static void BM_specvol_alpha_beta(benchmark::State& state) {
  for (auto _  : state) {
    double a, b, c;
    gsw_specvol_alpha_beta(10.0, 10.0, 10.0, &a, &b, &c);
  }
}
BENCHMARK(BM_specvol_alpha_beta);

static void BM_rho(benchmark::State& state) {
  for (auto _  : state) {
    gsw_rho(10.0, 10.0, 10.0);
  }
}
BENCHMARK(BM_rho);

static void BM_rho_alpha_beta(benchmark::State& state) {
  for (auto _  : state) {
    double a, b, c;
    gsw_rho_alpha_beta(10.0, 10.0, 10.0, &a, &b, &c);
  }
}
BENCHMARK(BM_rho_alpha_beta);

static void BM_sigma0(benchmark::State& state) {
  for (auto _  : state) {
    gsw_sigma0(10.0, 10.0);
  }
}
BENCHMARK(BM_sigma0);

static void BM_sigma1(benchmark::State& state) {
  for (auto _  : state) {
    gsw_sigma1(10.0, 10.0);
  }
}
BENCHMARK(BM_sigma1);

static void BM_sigma2(benchmark::State& state) {
  for (auto _  : state) {
    gsw_sigma2(10.0, 10.0);
  }
}
BENCHMARK(BM_sigma2);

static void BM_sigma3(benchmark::State& state) {
  for (auto _  : state) {
    gsw_sigma3(10.0, 10.0);
  }
}
BENCHMARK(BM_sigma3);

static void BM_sigma4(benchmark::State& state) {
  for (auto _  : state) {
    gsw_sigma4(10.0, 10.0);
  }
}
BENCHMARK(BM_sigma4);

static void BM_sound_speed(benchmark::State& state) {
  for (auto _  : state) {
    gsw_sound_speed(10.0, 10.0, 10.0);
  }
}
BENCHMARK(BM_sound_speed);

static void BM_dynamic_enthalpy(benchmark::State& state) {
  for (auto _  : state) {
    gsw_dynamic_enthalpy(10.0, 10.0, 10.0);
  }
}
BENCHMARK(BM_dynamic_enthalpy);

static void BM_sa_from_rho(benchmark::State& state) {
  for (auto _  : state) {
    gsw_sa_from_rho(10.0, 10.0, 10.0);
  }
}
BENCHMARK(BM_sa_from_rho);

static void BM_specvol_first_derivatives(benchmark::State& state) {
  for (auto _  : state) {
    double a, b, c;
    gsw_specvol_first_derivatives(10.0, 10.0, 10.0, &a, &b, &c);
  }
}
BENCHMARK(BM_specvol_first_derivatives);

static void BM_specvol_second_derivatives(benchmark::State& state) {
  for (auto _  : state) {
    double a, b, c, d, e;
    gsw_specvol_second_derivatives(10.0, 10.0, 10.0, &a, &b, &c, &d, &e);
  }
}
BENCHMARK(BM_specvol_second_derivatives);

static void BM_alpha_on_beta(benchmark::State& state) {
  for (auto _  : state) {
    gsw_alpha_on_beta(10.0, 10.0, 10.0);
  }
}
BENCHMARK(BM_alpha_on_beta);

static void BM_rho_first_derivatives(benchmark::State& state) {
  for (auto _  : state) {
    double a, b, c;
    gsw_rho_first_derivatives(10.0, 10.0, 10.0, &a, &b, &c);
  }
}
BENCHMARK(BM_rho_first_derivatives);

static void BM_thermobaric(benchmark::State& state) {
  for (auto _  : state) {
    gsw_thermobaric(10.0, 10.0, 10.0);
  }
}
BENCHMARK(BM_thermobaric);

static void BM_enthalpy(benchmark::State& state) {
  for (auto _  : state) {
    gsw_enthalpy(10.0, 10.0, 10.0);
  }
}
BENCHMARK(BM_enthalpy);

static void BM_enthalpy_diff(benchmark::State& state) {
  for (auto _  : state) {
    gsw_enthalpy_diff(33.0, 10.0, 0.0, 100.0);
  }
}
BENCHMARK(BM_enthalpy_diff);

static void BM_kappa(benchmark::State& state) {
  for (auto _  : state) {
    gsw_kappa(10.0, 10.0, 10.0);
  }
}
BENCHMARK(BM_kappa);

static void BM_internal_energy(benchmark::State& state) {
  for (auto _  : state) {
    gsw_internal_energy(10.0, 10.0, 10.0);
  }
}
BENCHMARK(BM_internal_energy);

static void BM_ct_maxdensity(benchmark::State& state) {
  for (auto _  : state) {
    gsw_ct_maxdensity(10.0, 10.0);
  }
}
BENCHMARK(BM_ct_maxdensity);

// ---------------------------
// Practical Salinity
// ---------------------------

static void BM_sp_from_c(benchmark::State& state) {
  for (auto _  : state) {
    gsw_sp_from_c(10.0, 10.0, 10.0);
  }
}
BENCHMARK(BM_sp_from_c);

static void BM_c_from_sp(benchmark::State& state) {
  for (auto _  : state) {
    gsw_c_from_sp(10.0, 10.0, 10.0);
  }
}
BENCHMARK(BM_c_from_sp);

static void BM_sp_salinometer(benchmark::State& state) {
  for (auto _  : state) {
    gsw_sp_salinometer(10.0, 10.0);
  }
}
BENCHMARK(BM_sp_salinometer);

// ---------------------------
// Conversions
// ---------------------------

static void BM_z_from_p(benchmark::State& state) {
  for (auto _  : state) {
    gsw_z_from_p(10.0, 10.0, 10.0, 10.0);
  }
}
BENCHMARK(BM_z_from_p);

BENCHMARK_MAIN();

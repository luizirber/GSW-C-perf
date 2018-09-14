# Distributed under the MIT license
cmake_minimum_required(VERSION 3.5)
project("gsw_bench")

file(GLOB gsw_SRC
  "./src/main.cc"
  "./src/gsw_saar.c"
  "./src/gsw_oceanographic_toolbox.c")

add_executable(gsw_bench ${gsw_SRC})
set_target_properties(gsw_bench PROPERTIES CXX_STANDARD 20)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# build google benchmark (target: benchmark)
# do not build tests of benchmarking lib
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Suppressing benchmark's tests" FORCE)
#add_subdirectory(vendor/google/benchmark)

# build tests (targets: gtest_main, gtest)
#add_subdirectory(vendor/google/googletest/googletest)

# google benchmark
target_link_libraries(gsw_bench PRIVATE benchmark Threads::Threads m)
target_include_directories(gsw_bench PRIVATE src/)

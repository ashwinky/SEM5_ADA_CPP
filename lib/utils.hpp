#pragma once

#include <iomanip>
#include <iostream>

#if CMAKE_BUILD_TYPE == Debug
#define D(x...) x
#else
#define D(x...)
#endif

/**
 * Prints an array
 * @param arr Array to print
 */
#define ARR_PRINT(arr)                      \
  {                                         \
    int __n = sizeof(arr) / sizeof(arr[0]); \
    std::cout << #arr << " = [ ";           \
    for (int i = 0; i < __n; i++) {         \
      std::cout << arr[i];                  \
      if (i < __n - 1) std::cout << ", ";   \
    }                                       \
    std::cout << " ]" << std::endl;         \
  }

/**
 * Prints a matrix
 * @param arr Matrix to print
 */
#define MAT_PRINT(arr)                                                      \
  {                                                                         \
    int __x = sizeof(arr) / sizeof(arr[0]);                                 \
    int __y = sizeof(arr[0]) / sizeof(arr[0][0]);                           \
    int __padvar = std::string(#arr).length();                              \
    int __padnum = 0;                                                       \
    for (int i = 0; i < __x; i++) {                                         \
      for (int j = 0; j < __y; j++) {                                       \
        int len = std::to_string(arr[i][j]).length();                       \
        if (len > __padnum) __padnum = len;                                 \
      }                                                                     \
    }                                                                       \
    for (int i = 0; i < __x; i++) {                                         \
      if (i == 0) {                                                         \
        std::cout << std::endl                                              \
                  << #arr << " = | ";                                       \
      } else {                                                              \
        std::cout << std::setw(__padvar + 5) << std::setfill(' ') << " | "; \
      }                                                                     \
      for (int j = 0; j < __y; j++) {                                       \
        std::cout << std::setw(__padnum) << std::setfill(' ') << arr[i][j]; \
        if (j < __y - 1) std::cout << ", ";                                 \
      }                                                                     \
      std::cout << " |";                                                    \
      std::cout << std::endl;                                               \
    }                                                                       \
    std::cout << std::endl;                                                 \
  }

#define TEST(name, tests...)     \
  int main() {                   \
    std::string testname = name; \
    int failed = 0;              \
    tests;                       \
    if (failed) {                \
      return 1;                  \
    } else {                     \
      return 0;                  \
    }                            \
  }

#define UNIT(name, expr...)                                                            \
  {                                                                                    \
    char unitname[] = name;                                                            \
    int unitfailed = 0;                                                                \
    expr;                                                                              \
    if (unitfailed) {                                                                  \
      std::cout << "\033[31m[FAILED] " << testname << ": " << unitname << "\033[0m\n"; \
      failed++;                                                                        \
    } else {                                                                           \
      std::cout << "\033[32m[PASSED] " << testname << ": " << unitname << "\033[0m\n"; \
    }                                                                                  \
  }

#define ASSERT(A, B) \
  if (A != B) {      \
    unitfailed++;    \
  }

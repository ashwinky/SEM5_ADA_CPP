#pragma once

#include <climits>

#include "utils.hpp"

template <typename T, int N>
void floyd_warshall(T (&A)[N][N]) {
  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      if (A[i][k] == INT_MAX) continue;
      for (int j = 0; j < N; ++j) {
        if (A[k][j] == INT_MAX) continue;
        if (A[i][j] > A[i][k] + A[k][j]) {
          A[i][j] = A[i][k] + A[k][j];
        }
      }
    }

    MAT_PRINT(A);
  }
}
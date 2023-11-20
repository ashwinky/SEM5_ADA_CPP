#include "floyd_warshall.hpp"

#include "utils.hpp"

int main() {
  int A[4][4] = {
      {0, 3, INT_MAX, 7},
      {8, 0, 2, INT_MAX},
      {5, INT_MAX, 0, 1},
      {2, INT_MAX, INT_MAX, 0},
  };

  MAT_PRINT(A);

  floyd_warshall(A);

  MAT_PRINT(A);

  int B[4][4] = {
      {0, 2, INT_MAX, 5},
      {INT_MAX, 0, 3, 2},
      {5, INT_MAX, 0, 1},
      {INT_MAX, INT_MAX, INT_MAX, 0},
  };

  MAT_PRINT(B);

  floyd_warshall(B);

  MAT_PRINT(B);

  return 0;
}

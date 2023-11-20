#include "longest_common_subsequence.hpp"

#include "utils.hpp"

int longest_common_subsequence(std::string sequence1, std::string sequence2) {
  int X = sequence1.size(), Y = sequence2.size();

  int A[X + 1][Y + 1];

  for (int i = 0; i <= X; i++) A[i][0] = 0;

  for (int i = 0; i <= Y; i++) A[0][i] = 0;

  for (int i = 1; i <= X; i++) {
    for (int j = 1; j <= Y; j++) {
      if (sequence1[i - 1] == sequence2[j - 1]) {
        A[i][j] = 1 + A[i - 1][j - 1];
      } else {
        A[i][j] = std::max(A[i - 1][j], A[i][j - 1]);
      }
    }
  }

  D(MAT_PRINT(A));

  return A[X][Y];
}
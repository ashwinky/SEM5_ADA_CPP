#include <climits>
#include <iostream>

#include "utils.hpp"

using namespace std;


int min_multiplications(int P[], int n) {
  int M[n][n];
  int S[n][n];

  // fill everything with 0
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      M[row][col] = 0;
      S[row][col] = 0;
    }
  }

  for (int row = 0; row < n; row++) {
    M[row][row] = 0;        // Fill M diagonal with 0
    S[row][row] = row + 1;  // Fill S diagonal with the index of the matrix
  }

  for (int clen = 1; clen < n; clen++) {
    for (int row = 0; row < n - clen; row++) {
      int col = row + clen;

      M[row][col] = INT_MAX;

      for (int k = row; k < col; k++) {
        int q = M[row][k] + M[k + 1][col] + P[row] * P[k + 1] * P[col + 1];

        if (q < M[row][col]) {
          M[row][col] = q;
          S[row][col] = k + 1;

          std::cout << "\nL " << clen << " | R " << row << " | C " << col << " | K " << k << " | Q "
                    << q << endl;
          std::cout << "M[" << row + 1 << ", " << col + 1 << "] = "
                    << "M[" << row + 1 << ", " << k + 1 << "] + "
                    << "M[" << k + 2 << ", " << col + 1 << "] + "
                    << "P[" << row << "] * P[" << k + 1 << "] * P[" << col + 1 << "]" << endl;
          std::cout << std::setw(("M[, ] = " + to_string(row + 1) + to_string(col + 1)).length())
                    << std::setfill(' ') << " = " << M[row][k] << " + " << M[row + 1][col] << " + "
                    << P[row] << " * " << P[k + 1] << " * " << P[col + 1] << " = " << q << endl;
          std::cout << "S[" << row + 1 << ", " << col + 1 << "] = " << k + 1 << endl;

          MAT_PRINT(M);
          MAT_PRINT(S);
        }
      }
    }
  }

  return M[0][n - 1];
}

int main() {
  int P[] = {10, 15, 20, 25, 30, 35};
  int n = sizeof(P) / sizeof(P[0]);

  ARR_PRINT(P);

  int result = min_multiplications(P, n - 1);

  std::cout << "Minimum number of multiplications is " << result << endl;

  return 0;
}
// C++ program to solve N Queen Problem using backtracking

#include <bits/stdc++.h>

#include "utils.hpp"

using namespace std;

#define N 4

bool is_free(int board[N][N], int row, int col) {
  int i, j;

  // Check this row on left side
  for (i = 0; i < col; i++) {
    if (board[row][i]) return false;
  }

  // Check upper diagonal on left side
  for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j]) return false;
  }

  // Check lower diagonal on left side
  for (i = row, j = col; j >= 0 && i < N; i++, j--) {
    if (board[i][j]) return false;
  }

  return true;
}

bool nqueens_solve(int board[N][N], int col) {
  // base case: If all queens are placed then return true
  if (col >= N) return true;

  // Consider this column and try placing
  // this queen in all rows one by one
  for (int i = 0; i < N; i++) {
    // Check if the queen can be placed on
    // board[i][col]
    if (is_free(board, i, col)) {
      // Place this queen in board[i][col]
      board[i][col] = 1;

      // recur to place rest of the queens
      if (nqueens_solve(board, col + 1)) return true;

      // If placing queen in board[i][col]
      // doesn't lead to a solution, then
      // remove queen from board[i][col]
      board[i][col] = 0;  // BACKTRACK
    }
  }

  // If the queen cannot be placed in any row in
  // this column col then return false
  return false;
}

// Driver program to test above function
int main() {
  int board[N][N] = {{0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0}};

  if (nqueens_solve(board, 0) == false) {
    cout << "Solution does not exist" << endl;
    return 1;
  } else {
    MAT_PRINT(board);
    return 0;
  }
}

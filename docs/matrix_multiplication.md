# Matrix Multiplication

Matrix multiplication is a binary operation that takes a pair of matrices with real or complex entries, and produces another matrix. If A is an n × m matrix and B is an m × p matrix, their matrix product AB is an n × p matrix, in which the m entries across a row of A are multiplied with the m entries down a column of B and summed to produce an entry of AB. When two linear transformations are represented by matrices, then the matrix product represents the composition of the two transformations.

### Find number of operations required to multiply two matrices

Given two matrices A and B, the task is to find the number of operations needed to multiply the two matrices.

$$
\begin{aligned}
A = \begin{bmatrix}
1 & 2 & 3 \\
4 & 5 & 6 \\
\end{bmatrix}

B = \begin{bmatrix}
1 \\
4 \\
7 \\
\end{bmatrix}

A \times B = \begin{bmatrix}
A_{1,1} \times B_{1,1} + A_{1,2} \times B_{2,1} + A_{1,3} \times B_{3,1} & \cdots & A_{1,1} \times B_{1,n} + A_{1,2} \times B_{2,n} + A_{1,3} \times B_{3,n} \\
A_{2,1} \times B_{1,1} + A_{2,2} \times B_{2,1} + A_{2,3} \times B_{3,1} & \cdots & A_{2,1} \times B_{1,n} + A_{2,2} \times B_{2,n} + A_{2,3} \times B_{3,n} \\
\end{bmatrix}
\end{aligned}
$$

The number of operations required to multiply two matrices is equal to the number of rows in the first matrix multiplied by the number of columns in the second matrix multiplied by the number of elements in each row/column. In the above example, the number of operations required to multiply the two matrices is 2 × 1 × 3 = 6.

### Matrix Chain Multiplication

Given a sequence of matrices, the goal is to find the most efficient way to multiply these matrices. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.

We have many options to multiply a chain of matrices because matrix multiplication is associative. In other words, no matter how we parenthesize the product, the result will be the same. For example, if we had four matrices A, B, C, and D, we would have:

$$
\begin{aligned}
(AB)(CD) &= A(BC)D = ABCD \\
(AB)(CD) &= (AB)(CD) = (AB)(CD) \\
\end{aligned}
$$

However, the order in which we parenthesize the product affects the number of simple arithmetic operations needed to compute the product, or the efficiency. For example, suppose A is a 10 × 30 matrix, B is a 30 × 5 matrix, and C is a 5 × 60 matrix. Then,

$$
\begin{aligned}
(AB)C &= (10 \times 30 \times 5) + (10 \times 5 \times 60) = 1500 + 3000 = 4500 \text{ operations} \\
A(BC) &= (30 \times 5 \times 60) + (10 \times 30 \times 60) = 9000 + 18000 = 27000 \text{ operations} \\
\end{aligned}
$$

Clearly the first parenthesization requires less number of operations.

Algorithm:

1. Create a table that stores the minimum number of operations required to multiply the matrices.
2. The table is filled in a manner similar to Matrix Chain Multiplication DP solution. The only difference here is that we need to find the minimum number of operations to multiply the matrices.
3. The minimum number of operations required to multiply the matrices is stored in the top right corner of the table.

```cpp
#include <climits>
#include <iostream>

#include "utils.hpp"

using namespace std;

int matrixChainOrder(int P[], int n) {
  int M[n][n];
  int S[n][n];

  // fill matrix with 0
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
        }
      }
    }
  }

  return M[0][n - 1];
}
```

Example:

$$
P = { 5, 4, 6, 2, 7 }
$$

$$
M = \begin{bmatrix}
0 & \cdot & \cdot & \cdot & \cdot \\
\cdot & 0 & \cdot & \cdot & \cdot \\
\cdot & \cdot & 0 & \cdot & \cdot \\
\cdot & \cdot & \cdot & 0 & \cdot \\
\cdot & \cdot & \cdot & \cdot & 0 \\
\end{bmatrix}

\qquad

S = \begin{bmatrix}
1 & \cdot & \cdot & \cdot & \cdot \\
\cdot & 2 & \cdot & \cdot & \cdot \\
\cdot & \cdot & 3 & \cdot & \cdot \\
\cdot & \cdot & \cdot & 4 & \cdot \\
\cdot & \cdot & \cdot & \cdot & 5 \\
\end{bmatrix}
$$

$$
\begin{aligned}
M_{1,2} &= M_{1,1} + M_{2,2} + P_0 \times P_1 \times P_2 \\
&= 0 + 0 + 5 \times 4 \times 6 \\
&= 120 \\
S_{1,2} &= 1 \\

\\

M_{2,3} &= M_{2,2} + M_{3,3} + P_1 \times P_2 \times P_3 \\
&= 0 + 0 + 4 \times 6 \times 2 \\
&= 48 \\
S_{2,3} &= 2 \\

\\

M_{3,4} &= M_{3,3} + M_{4,4} + P_2 \times P_3 \times P_4 \\
&= 0 + 0 + 6 \times 2 \times 7 \\
&= 84 \\
S_{3,4} &= 3 \\

\\

M_{1,3} &= M_{1,1} + M_{2,3} + P_0 \times P_1 \times P_3 \\
&= 0 + 48 + 5 \times 4 \times 2 \\
&= 88 \\
S_{1,3} &= 2 \\
\end{aligned}
$$

$$
M = \begin{bmatrix}
0 & 120 & 88 & 158 \\
\cdot & 0 & 48 & 104 \\
\cdot & \cdot & 0 & 84 \\
\cdot & \cdot & \cdot & 0 \\
\end{bmatrix}

\qquad

S = \begin{bmatrix}
1 & 1 & 1 & 3 \\
\cdot & 2 & 2 & 3 \\
\cdot & \cdot & 3 & 3 \\
\cdot & \cdot & \cdot & 4 \\
\end{bmatrix}
$$
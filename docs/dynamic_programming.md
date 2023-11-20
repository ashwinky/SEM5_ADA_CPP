# Dynamic Programming

Dynamic programming is a method for solving a complex problem by breaking it down into a collection of simpler subproblems, solving each of those subproblems just once, and storing their solutions using a memory-based data structure (array, map,etc). Each of the subproblem solutions is indexed in some way, typically based on the values of its input parameters, so as to facilitate its lookup. So the next time the same subproblem occurs, instead of recomputing its solution, one simply looks up the previously computed solution, thereby saving computation time at the expense of a (hopefully) modest expenditure in storage space. (Each of the subproblem solutions is indexed in some way, typically based on the values of its input parameters, so as to facilitate its lookup. So the next time the same subproblem occurs, instead of recomputing its solution, one simply looks up the previously computed solution, thereby saving computation time at the expense of a (hopefully) modest expenditure in storage space.)

##### Dynamic Programming vs Divide and Conquer

| Dynamic Programming     | Divide and Conquer      |
| ----------------------- | ----------------------- |
| Overlapping subproblems | Overlapping subproblems |
| Optimal substructure    | Optimal substructure    |
| Memoization             | Recursion               |
| Bottom-up               | Top-down                |

## Examples

### Fibonacci

<table><tr>

<th>Fibonacci</th>
<th>Fibonacci with memoization</th>

</tr>

<tr><td>

```cpp
int fib(int n) {
    if (n <= 1) return n; // O(1)
    return fib(n - 1) + fib(n - 2); // O(2^n)
}
```

</td><td>

```cpp
std::vector<int> memo(10, -1); // O(n)

int fib(int n) {
    if (n <= 1) return n; // O(1)
    if (memo[n] != -1) return memo[n]; // O(1)

    memo[n] = fib(n - 1) + fib(n - 2); // O(2^n)
    return memo[n];
}
```

</td></tr></table>

### Knapsack

<table><tr>

<th>Knapsack</th>
<th>Knapsack with memoization</th>

</tr>

<tr><td>

```cpp
int knapsack(int W, int wt[], int val[], int n) {
  if (n == 0 || W == 0) return 0;                                        // O(1)
  if (wt[n - 1] > W) return knapsack(W, wt, val, n - 1);                 // O(1)
  return std::max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1),  // O(2^n)
                  knapsack(W, wt, val, n - 1));
}
```

</td><td>

```cpp
std::vector<std::vector<int>> memo(10, std::vector<int>(10, -1));  // O(n)

int knapsack(int W, int wt[], int val[], int n) {
  if (n == 0 || W == 0) return 0;                                      // O(1)
  if (memo[n][W] != -1) return memo[n][W];                             // O(1)
  if (wt[n - 1] > W) return memo[n][W] = knapsack(W, wt, val, n - 1);  // O(1)
  return memo[n][W] = std::max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1),
                               knapsack(W, wt, val, n - 1));  // O(2^n)
}
```

</td></tr></table>

```cpp
std::vector<std::vector<int>> C(n + 1, std::vector<int>(W + 1, 0));
int knapsack(std::vector<std::vector<int>> C, int W, int wt[], int val[], int n) {

  for (int i = 0; i <= n; i++) {
    for (int w = 0; w <= W; w++) {
      if (i == 0 || w == 0)
        C[i][w] = 0;  // Base case

      else if (wt[i - 1] > w) {                    // If weight is greater than capacity
        C[i][w] = C[i - 1][w];                     // Set the value to the previous value
      } else {                                     // Max of including or excluding
        C[i][w] = std::max(                        // Max of including or excluding
            val[i - 1] + C[i - 1][w - wt[i - 1]],  // Include
            C[i - 1][w]                            // Exclude
        );
      };
    }
  }
}
```

## Floyd-Warshall Algorithm

Floyd-Warshall algorithm is used to find all pair shortest path problem from a given weighted graph. As a result of this algorithm, it will generate a matrix, which will represent the minimum distance from any node to all other nodes in the graph.

### Algorithm

- First, we will create a matrix `dist` of size `V x V` (where `V` is the number of vertices) and initialize it with the same value as the adjacency matrix as a first step.
- Then, we will update the `dist` matrix by considering each vertex as an intermediate vertex. The idea is to one by one pick all vertices and updates all shortest paths which include the picked vertex as an intermediate vertex in the shortest path.
- After the update step, we will check if the intermediate vertex distance is less than the direct edge distance between the two vertices. If the condition is true, then we will update the `dist` matrix.
- We will repeat the above steps for all the vertices in the graph.

### Example

$$
\begin{aligned}

A^{0} &= \begin{bmatrix}
0 & 3 & \infty & 7 \\
8 & 0 & 2 & \infty \\
5 & \infty & 0 & 1 \\
2 & \infty & \infty & 0
\end{bmatrix} \\\\

A^{(n)}_{[i,j]} &= \min(A^{(n-1)}_{[i,j]}, A^{(n-1)}_{[i,k]} + A^{(n-1)}_{[k,j]}) \\\\

A^{1}_{i,j} &= \min(A^{0}_{i,j}, A^{0}_{i,k} + A^{0}_{k,j}) \\

A^{1}_{3,2} &= \min(A^{0}_{3,2}, A^{0}_{3,1} + A^{0}_{1,2}) = \min(\infty, \infty + 3) = \infty \\
A^{1}_{4,2} &= \min(A^{0}_{4,2}, A^{0}_{4,1} + A^{0}_{1,2}) = \min(\infty, 7 + 8) = 15 \\
A^{1}_{4,3} &= \min(A^{0}_{4,3}, A^{0}_{4,1} + A^{0}_{1,3}) = \min(\infty, 7 + 5) = 12 \\
A^{1}_{2,3} &= \min(A^{0}_{2,3}, A^{0}_{2,1} + A^{0}_{1,3}) = \min(\infty, 3 + 5) = 8 \\
A^{1}_{2,4} &= \min(A^{0}_{2,4}, A^{0}_{2,1} + A^{0}_{1,4}) = \min(\infty, 3 + 2) = 5 \\
A^{1}_{3,4} &= \min(A^{0}_{3,4}, A^{0}_{3,1} + A^{0}_{1,4}) = \min(\infty, \infty + 2) = \infty \\

A^{1} &= \begin{bmatrix}
0 & 3 & \infty & 7 \\
8 & 0 & 2 & 15 \\
5 & 8 & 0 & 1 \\
2 & 5 & \infty & 0
\end{bmatrix} \\\\

A^{2}_{i,j} &= \min(A^{1}_{i,j}, A^{1}_{i,k} + A^{1}_{k,j}) \\

A^{2}_{3,2} &= \min(A^{1}_{3,2}, A^{1}_{3,2} + A^{1}_{2,2}) = \min(2, \infty + 8) = 2 \\
A^{2}_{4,2} &= \min(A^{1}_{4,2}, A^{1}_{4,2} + A^{1}_{2,2}) = \min(15, 7 + 8) = 15 \\
A^{2}_{4,3} &= \min(A^{1}_{4,3}, A^{1}_{4,2} + A^{1}_{2,3}) = \min(1, 7 + 5) = 1 \\
A^{2}_{2,3} &= \min(A^{1}_{2,3}, A^{1}_{2,2} + A^{1}_{2,3}) = \min(8, 3 + 5) = 8 \\
A^{2}_{2,4} &= \min(A^{1}_{2,4}, A^{1}_{2,2} + A^{1}_{2,4}) = \min(5, 3 + 2) = 5 \\
A^{2}_{3,4} &= \min(A^{1}_{3,4}, A^{1}_{3,2} + A^{1}_{2,4}) = \min(\infty, 2 + 5) = 7 \\

A^{2} &= \begin{bmatrix}
0 & 3 & 5 & 7 \\
8 & 0 & 2 & 15 \\
5 & 8 & 0 & 1 \\
2 & 5 & 7 & 0
\end{bmatrix} \\\\

A^{3}_{i,j} &= \min(A^{2}_{i,j}, A^{2}_{i,k} + A^{2}_{k,j}) \\

A^{3}_{3,2} &= \min(A^{2}_{3,2}, A^{2}_{3,3} + A^{2}_{3,2}) = \min(2, 5 + 8) = 2 \\
A^{3}_{4,2} &= \min(A^{2}_{4,2}, A^{2}_{4,3} + A^{2}_{3,2}) = \min(15, 7 + 8) = 15 \\
A^{3}_{4,3} &= \min(A^{2}_{4,3}, A^{2}_{4,3} + A^{2}_{3,3}) = \min(1, 7 + 5) = 1 \\
A^{3}_{2,3} &= \min(A^{2}_{2,3}, A^{2}_{2,3} + A^{2}_{3,3}) = \min(8, 3 + 5) = 8 \\
A^{3}_{2,4} &= \min(A^{2}_{2,4}, A^{2}_{2,3} + A^{2}_{3,4}) = \min(5, 3 + 2) = 5 \\
A^{3}_{3,4} &= \min(A^{2}_{3,4}, A^{2}_{3,3} + A^{2}_{3,4}) = \min(7, 2 + 5) = 7 \\



\end{aligned}
$$

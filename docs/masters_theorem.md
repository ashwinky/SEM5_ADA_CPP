# Masters Theorem

Masters Theorem is a method for solving recurrence relations of the form:

- $T(n) = aT(n-b) + f(n)$ where $a \geq 1$ and $b > 0$ are constants and $f(n)$ is an asymptotically positive function.
- $T(n) = aT(n/b) + f(n)$ where $a \geq 1$ and $b > 1$ are constants and $f(n)$ is an asymptotically positive function.

## $T(n) = aT(n-b) + f(n)$

$$
a > 0 \qquad b > 0 \qquad f(n) = O(n^k) \implies k > 0 \\
$$

$$
\begin{aligned}
  O =
  \begin{dcases}
      a = 1 &\implies O(n \cdot f(n)) \\
      a > 1 &\implies O(n^k \cdot a^\frac{n}{b}) \\
      a < 1 &\implies O(f(n)) \\
  \end{dcases}
\end{aligned}
$$

## $T(n) = aT(n/b) + f(n)$

$$
a \ge 1 \qquad b > 1 \qquad f(n) = O(n^k \cdot \log^p(n)) \\
$$

$$
\begin{aligned}
  O =
  \begin{dcases}
      \log_b a > k &\implies O(n^{\log_b a}) \\\\
      \log_b a = k &\implies \begin{dcases}
        p > -1 &\implies O(n^k \cdot \log^{p+1}(n)) \\
        p = -1 &\implies O(n^k \cdot \log \log n) \\
        p < -1 &\implies O(n^k) \\
      \end{dcases}\\\\
      \log_b a < k &\implies \begin{dcases}
        p \ge 0 &\implies O(n^k \cdot \log^p(n)) \\
        p < 0 &\implies O(n^k) \\
      \end{dcases}
  \end{dcases}
\end{aligned}
$$

## Example 1

Algorithm:

$$
T(n) = 2T(n/2) + n
$$

Given:

$$
\begin{aligned}
a &= 2 \\
b &= 2 \\
f(n) &= n \\
\end{aligned}
$$

$$
\begin{aligned}
\log_b a &= \log_2 2 \\
&= 1 \\
k &= 1 \\
p &= 0 & \text{(Since $n^0 = 1$)} \\
\end{aligned}
$$

$$
\begin{aligned}
O(n^k \cdot \log^{p+1}(n)) &= O(n^1 \cdot \log^{0+1}(n)) \\
&= O(n \cdot \log n) \\
\end{aligned}
$$

Therefore, time complexity is $O(n \cdot \log n)$

### Example 2

Algorithm:

$$
T(n) = 2T(n/2) + \frac{n}{\log^2 n}
$$

Given:

$$
\begin{aligned}
a &= 2 \\
b &= 2 \\
f(n) &= \frac{n}{\log^2 n} \\
\end{aligned}
$$

$$
\begin{aligned}
\log_b a &= \log_2 2 \\
&= 1 \\
k &= 1 \\
p &= -2 & \text{(Since $\log^{-2} n = \frac{1}{\log^2 n}$)} \\
\end{aligned}
$$

$$
\begin{aligned}
O(n^k) &= O(n^1) \\
&= O(n) \\
\end{aligned}
$$

### Example 3

$$
T(n) = 2T(n/2) + n^2 \cdot \log^2 n
$$

Given:

$$
\begin{aligned}
a &= 2 \\
b &= 2 \\
f(n) &= n^2 \cdot \log^2 n \\
\end{aligned}
$$

$$
\begin{aligned}
\log_b a &= \log_2 2 \\
&= 1 \\
k &= 2 \\
p &= 2 & \text{(Since $\log^2 n = \log^2 n$)} \\
\end{aligned}
$$

$$
\begin{aligned}
O(n^k \cdot \log^{p}(n)) &= O(n^2 \cdot \log^{2}(n)) \\
&= O(n^2 \cdot \log^2 n) \\
\end{aligned}
$$

# Recurrence Relation

Recurrence relation is a way to represent a sequence of numbers. It is a recursive definition of a sequence of terms. Each term of the sequence is defined by a function of the preceding terms.

## Recursion

Recursion is a method of solving a problem where the solution depends on solutions to smaller instances of the same problem. It is a process where a function calls itself directly or indirectly.

### Direct Recursion

A function is called direct recursive if it calls the same function again.

```c
void T(int n) {
  if (n > 0) {
    T(n - 1);
  }
}
```

### Indirect Recursion

A function is called indirect recursive if it calls another function which in turn calls the first function.

```c
void T(int n) {
  if (n > 0) {
    S(n - 1);
  }
}

void S(int n) {
  if (n > 0) {
    T(n - 1);
  }
}
```

## Recurrence Relation

A recurrence relation is an equation that recursively defines a sequence where the next term is a function of the previous terms. It is a way to represent a sequence of numbers. It is a recursive definition of a sequence of terms. Each term of the sequence is defined by a function of the preceding terms.

### Example

$$
\begin{aligned}
T(0) &= 1 \\
T(n) &= T(n-1) + 1 \\
\end{aligned}
$$

### Solving Recurrence Relation

There are 3 methods to solve recurrence relation:

1. Substitution Method
2. Master Method
3. Recursion Tree

#### Substitution Method

In this method, we substitute the value of n in the recurrence relation and try to find a pattern. We can use this method to find the upper bound of the recurrence relation.

#### Example 1

Algorithm:

```
T(n) {
  if (n > 0) {
    for (int i = 0; i < n; i++) {
      // O(1)
    }
    T(n - 1);
  }
}
```

Using substitution method, we can find the upper bound of the recurrence relation as follows:

$$
\begin{aligned}
T(n) &= T(n-1) + n \\
T(n-1) &= T(n-2) + n-1 \\
T(n-2) &= T(n-3) + n-2 \\
\end{aligned}
$$

We can see that the recurrence relation follows the pattern $T(n) = T(n-1) + n$. We can expand the relation as follows:

$$
\begin{aligned}
T(n) &= T(n-1) + n \\
T(n) &= T(n-2) + n-1 + n \\
T(n) &= T(n-3) + n-2 + n-1 + n \\
T(n) &= T(n-k) + n-k+1 + n-k+2 + ... + n-1 + n \\
T(n) &= T(n-n) + n-n+1 + n-n+2 + ... + n-1 + n \\
T(n) &= T(0) + 1 + 2 + ... + n-1 + n \\
T(n) &= 1 + 2 + ... + n-1 + n \\
T(n) &= n(n+1)/2 \\
T(n) &= O(n^2) \\
\end{aligned}
$$

Therefore, time complexity is O(n^2)

#### Example 2

Algorithm:

```
T(n) {
  1           : n = 1;
  T(n/2) + 1  : n > 1;
}
```

$$
\begin{aligned}
T(n) &= T(n/2) + 1 \\
T(n) &= T(n/4) + 1 + 1 \\
T(n) &= T(n/8) + 1 + 1 + 1 \\
T(n) &= T(n/2^k) + k \\
T(n) &= T(1) + log_2(n) \\
T(n) &= 1 + log_2(n) \\
T(n) &= O(log_2(n)) \\
\end{aligned}
$$

Therefore, time complexity is $O(log_2(n))$

# Simple Algorithm Analysis

#### Example

Algorithm:

```
F(n) {
  count = 0
  for (int i = n; i > 0; i /= 2) {
    for (int j = 0; j < i; j++) {
      count++
    }
  }
}
```

Outer loop:

$$
\begin{aligned}
i &= \frac{n}{1} , \frac{n}{2} , \frac{n}{4} , \frac{n}{8} , ... , 1 \\
i &= \frac{n}{2^0} , \frac{n}{2^1} , \frac{n}{2^2} , \frac{n}{2^3} , ... , \frac{n}{2^k} \\
1 &= \frac{n}{2^k} \\
2^k &= n \\
k &= log_2(n) \\
&= O(log_2(n))
\end{aligned}
$$

Inner loop:

$$
\begin{aligned}
j &= 0, 1, 2, 3, ... , i \\
j &= 0, 1, 2, 3, ... , 2^k \\
j &= 0, 1, 2, 3, ... , 2^{log_2(n)} \\
j &= 0, 1, 2, 3, ... , n \\
&= O(n)
\end{aligned}
$$
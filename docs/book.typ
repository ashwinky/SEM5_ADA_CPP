// Algorithm Design and Analysis Notebook

#set page(
  paper: "a4",
  margin: (x: 1.2cm, y: 2.4cm),
  header-ascent: 40%,
  header: [
    #set text(10pt)
    *Module 1*: Analyzing Algorithms
    #h(1fr)
    #smallcaps[Algorithm Design and Analysis]
  ],
  footer-descent: 40%,
  footer: [
    #set align(right)
    #set text(8pt)
    #counter(page).display(
      "1/1",
      both: true,
    )
  ]
)

#set heading(numbering: "1.1.1.")
#show heading: h => [
  #v(0.8cm) #h #v(0.5cm)
]

#show figure: f => [
  #v(0.8cm) #f #v(0.5cm)
]

#set par(justify: true, leading: 0.52em)

#set text(12pt)



= Class (Growth) of Functions

Class or growth of functions is a set of functions that have similar growth behavior. The growth behavior of a function is determined by the highest order term in the function. The highest order term is the term with the highest exponent. For example, in the function $f(n) = 3n^2 + 2n + 1$, the highest order term is $3n^2$. The highest order term is also called the dominant term. The dominant term determines the growth behavior of the function. The dominant term is also called the asymptotic term.

#figure(
  caption: "Examples of functions and their dominant terms",
  table(
    columns: 4,
    inset: 10pt,
    align: horizon,

    [*Class*], [*Example Function*], [*Dominant Term*], [*Example Algorithm*],
    [Constant], [$f(n) = 5$], [5], [Adding two numbers],
    [Logarithmic], [$f(n) = log_2n$], [$log_2n$], [Binary search],
    [Linear], [$f(n) = 3n + 2$], [$3n$], [Finding the maximum element in an array],
    [Quadratic], [$f(n) = 3n^2 + 2n + 1$], [$3n^2$], [Insertion sort],
    [Polynomial], [$f(n) = 3n^3 + 2n^2 + 1$], [$3n^3$], [Matrix multiplication],
    [Exponential], [$f(n) = 3^n + 2n + 1$], [$3^n$], [Towers of Hanoi],
  )
)

Ordered by increasing growth behavior, the classes of functions are:

$O(1) < O(log_2n) < O(n) < O(n log_2n) < O(n^2) < O(n^3) < O(2^n) < O(n!) < O(n^n)$

= Asymptotic Notations (Big-$O$, Big-$Omega$, Big-$Theta$)

Asymptotic notations are used to describe the running time of an algorithm. They are used to describe the running time in terms of input size. Asymptotic notations are used to describe the growth behavior of a function. The asymptotic notations are:

- *Big-$O$ notation*: Maximum number of steps taken by the algorithm to solve a problem of size $n$. $f(n) = O(g(n))$ means that $f(n)$ is bounded above by $g(n)$.
- *Big-$Omega$ notation*: Minimum number of steps taken by the algorithm to solve a problem of size $n$. $f(n) = Omega(g(n))$ means that $f(n)$ is bounded below by $g(n)$.
- *Big-$Theta$ notation*: Average number of steps taken by the algorithm to solve a problem of size $n$. $f(n) = Theta(g(n))$ means that $f(n)$ is bounded both above and below by $g(n)$.

= The Big-$O$ Notation

The Big-$O$ notation is used to describe the worst-case running time of an algorithm.

$O(g(n)) = {f(n) : 0 <= f(n) <= "cg"(n) " " exists c > 0, n_0 > 0 " " forall n >= n_0}$

$O(g(n))$ is the set of all functions $f(n)$ where there exists a constant $c > 0$ and a constant $n_0 > 0$ such that $0 <= f(n) <= "cg"(n)$ for all $n >= n_0$.

*Examples*:

Let $f(n) = 2n + 3$, then we can write:

$
2n + 3 <= 5 dot n &-> f(n) = O(n) : c = 5 and n_0 = 1 \
2n + 3 <= 5 dot n^2 &-> f(n) = O(n^2) : c = 5 and n_0 = 1 \
2n + 3 <= 5 dot 2^n &-> f(n) = O(2^n) : c = 5 and n_0 = 1 \
$

But only $f(n) = O(n)$ is useful.

- $f(n) = n^2 = O(n^2)$ where $c = 1$ and $n_0 = 1$
- $f(n) = 2n^2 + 3n + 1 = O(n^2)$ where $c = 3$ and $n_0 = 1$
- $f(n) = 2^n = O(2^n)$ where $c = 1$ and $n_0 = 1$
- $f(n) = frac(n^2, log n) = O(n^2)$ where $c = 1$ and $n_0 = 1$


*Note*: Since changing base of logarithm only changes the value by a constant factor, the base of the logarithm is usually not specified. For example, $O(log_2 n)$ is written as $O(log n)$.

= The Big-$Omega$ Notation

The Big-$Omega$ notation is used to describe the best-case running time of an algorithm.

$Omega(g(n)) = {f(n) : 0 <= "cg"(n) <= f(n) " " exists c > 0, n_0 > 0 " " forall n >= n_0}$

$Omega(g(n))$ is the set of all functions $f(n)$ where there exists a constant $c > 0$ and a constant $n_0 > 0$ such that $0 <= "cg"(n) <= f(n)$ for all $n >= n_0$.

*Examples*:

Let $f(n) = 2n + 3$, then we can write:

$
5 dot n <= 2n + 3 &-> f(n) = Omega(n) : c = 5 and n_0 = 1 \
5 dot n^2 <= 2n + 3 &-> f(n) = Omega(n^2) : c = 5 and n_0 = 1 \
5 dot 2^n <= 2n + 3 &-> f(n) = Omega(2^n) : c = 5 and n_0 = 1 \
$

But only $f(n) = Omega(n)$ is useful.

- $f(n) = n^2 = Omega(n^2)$ where $c = 1$ and $n_0 = 1$
- $f(n) = 2n^2 + 3n + 1 = Omega(n^2)$ where $c = 2$ and $n_0 = 1$
- $f(n) = 2^n = Omega(2^n)$ where $c = 1$ and $n_0 = 1$
- $f(n) = frac(n^2, log n) = Omega(n^2)$ where $c = 1$ and $n_0 = 1$

= The Big-$Theta$ Notation

The Big-$Theta$ notation is used to describe the average-case running time of an algorithm.

$Theta(g(n)) = {f(n) : 0 <= "c"_1"g"(n) <= f(n) <= "c"_2"g"(n) " " exists c_1 > 0, c_2 > 0, n_0 > 0 " " forall n >= n_0}$

$Theta(g(n))$ is the set of all functions $f(n)$ where there exists a constant $c_1 > 0$, a constant $c_2 > 0$ and a constant $n_0 > 0$ such that $0 <= "c"_1"g"(n) <= f(n) <= "c"_2"g"(n)$ for all $n >= n_0$.

*Examples*:

Let $f(n) = 2n + 3$, then we can write:

$
5 dot n <= 2n + 3 <= 5 dot n &-> f(n) = Theta(n) : c_1 = 5, c_2 = 5 and n_0 = 1 \
5 dot n^2 <= 2n + 3 <= 5 dot n^2 &-> f(n) = Theta(n^2) : c_1 = 5, c_2 = 5 and n_0 = 1 \
5 dot 2^n <= 2n + 3 <= 5 dot 2^n &-> f(n) = Theta(2^n) : c_1 = 5, c_2 = 5 and n_0 = 1 \
$

But only $f(n) = Theta(n)$ is useful.

- $f(n) = n^2 = Theta(n^2)$
- $f(n) = 2n^2 + 3n + 1 = Theta(n^2)$
- $f(n) = 2^n = Theta(2^n)$
- $f(n) = frac(n^2, log n) = Theta(n^2)$


= Practice Problems

#[#set enum(numbering: n => [Q #counter(heading).display()#n])
+ For the function defined by $f(n) = 2n^2 + 3n + 1$, proove/disprove the following statements:
  #[#set enum(numbering: "i.")
    + $f(n) = O(n^2)$
    + $f(n) = O(n^3)$
    + $n^2 = O(f(n))$
    + $f(n) != O(n)$
    + $n^3 != O(f(n))$
  ]

+ For the function defined by $f(n) = 2n^3 + 3n^2 + 1$ and $g(n) = 2n^2 + 3$, proove/disprove the following statements:
  #[#set enum(numbering: "i.")
    + $f(n) = Omega(g(n))$
    + $g(n) != Omega(f(n))$
    + $n^3 = Omega(g(n))$
    + $f(n) != Omega(n^4)$
    + $n^2 != Omega(f(n))$
  ]

+ For the function defined by $f(n) = 2n^3 + 3n^2 + 1$ and $g(n) = 2n^3 + 1$, show that:
  #[#set enum(numbering: "i.")
    + $f(n) = Theta(g(n))$
    + $f(n) != Theta(n^2)$
    + $n^4 != Theta(g(n))$
  ]
]
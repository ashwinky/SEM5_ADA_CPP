# Largest Common Subsequence

Largest Common Subsequence is a dynamic programming algorithm that finds the longest common subsequence between two strings. A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements. For example, the sequence $\{A, B, D\}$ is a subsequence of $\{A, B, C, D, E, F\}$ obtained by removing elements $\{C, E, F\}$. The longest common subsequence problem is finding the longest subsequence that is common to two given sequences. For example, the longest common subsequence of $\{A, B, C, D, E, F\}$ and $\{A, C, B, D, A, F\}$ is $\{A, B, D, F\}$.

### Algorithm

1. Create a table that stores the length of the longest common subsequence between two strings.
2. The table is filled in a manner similar to Matrix Chain Multiplication DP solution.
   - If the characters at the current index of both strings are equal, then the length of the longest common subsequence is equal to the length of the longest common subsequence of the two strings without the current characters plus one.
   - If the characters at the current index of both strings are not equal, then the length of the longest common subsequence is equal to the maximum of the length of the longest common subsequence of the first string without the current character and the length of the longest common subsequence of the second string without the current character.
3. The length of the longest common subsequence is stored in the bottom right corner of the table.


#### Example 1

$$
x = abaaba \\
y = babbab
$$

$$
\begin{matrix}
\cdot & 0 & b & a & b & b & a & b \\
    0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\
    a & 0 & 0 & 1 & 1 & 1 & 1 & 1 \\
    b & 0 & 1 & 1 & 2 & 2 & 2 & 2 \\
    a & 0 & 1 & 2 & 2 & 2 & 3 & 3 \\
    a & 0 & 1 & 2 & 2 & 2 & 3 & 3 \\
    b & 0 & 1 & 2 & 3 & 3 & 3 & 4 \\
    a & 0 & 1 & 2 & 3 & 3 & 4 & 4 \\
\end{matrix}
$$

#### Example 2

$$
x = abccda \\
y = bccdab
$$

$$
\begin{matrix}
\cdot & | & 0 & b & c & c & d & a & b \\
    — & | & — & — & — & — & — & — & — \\
    0 & | & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\
    a & | & 0 & 0 & 0 & 0 & 0 & 1 & 1 \\
    b & | & 0 & 1 & 1 & 1 & 1 & 1 & 2 \\
    c & | & 0 & 1 & 2 & 2 & 2 & 2 & 2 \\
    c & | & 0 & 1 & 2 & 3 & 3 & 3 & 3 \\
    d & | & 0 & 1 & 1 & 1 & 4 & 4 & 4 \\
    a & | & 0 & 1 & 1 & 1 & 1 & 5 & 5 \\
\end{matrix}
$$

# Divide and Conquer

```mermaid
graph TD;
    A[Divide] --> B[Divide];
    A --> C[Divide];
    B --> D[Divide];
    B --> E[Divide];
    C --> F[Divide];
    C --> G[Divide];
    D --> H[Conquer];
    D --> I[Conquer];
    E --> J[Conquer];
    E --> K[Conquer];
    F --> L[Conquer];
    F --> M[Conquer];
    G --> N[Conquer];
    G --> O[Conquer];
    H --> P[Combine];
    I --> P;
    J --> Q[Combine];
    K --> Q;
    L --> R[Combine];
    M --> R;
    N --> S[Combine];
    O --> S;
    P --> T[Combine];
    Q --> T;
    R --> U[Combine];
    S --> U;
    T --> V[Combine];
    U --> V;
```

## Applications

- Searching
  - Binary Search
- Sorting
  - Merge Sort
  - Quick Sort

## Sorting

### Merge Sort

Merge Sort is a Divide and Conquer algorithm. It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves. The merge() function is used for merging two halves. The merge(arr, l, m, r) is key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one.

```cpp
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray

    while (i < n1 && j < n2) { // As long as both L and R have elements
        if (L[i] <= R[j]) { // If L[i] is smaller than R[j]
            arr[k] = L[i]; // Copy L[i] to arr[k]
            i++; // Next element in L
        } else {
            arr[k] = R[j]; // Copy R[j] to arr[k]
            j++; // Next element in R
        }
        k++; // Next element in arr
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1) { // As long as L has elements
        arr[k] = L[i]; // Copy L[i] to arr[k]
        i++; // Next element in L
        k++; // Next element in arr
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2) { // As long as R has elements
        arr[k] = R[j]; // Copy R[j] to arr[k]
        j++; // Next element in R
        k++; // Next element in arr
    }
}

void merge_sort(int arr[], int l, int r) {
    if (l < r) { // As long as l < r
        int m = l + (r - l) / 2; // Find the middle point

        merge_sort(arr, l, m); // Sort first half
        merge_sort(arr, m + 1, r); // Sort second half

        merge(arr, l, m, r); // Merge the sorted halves
    }
}
```

Complexity:

$$
\begin{aligned}
T(n) = aT(\frac{n}{b}) + C(n) + D(n)
&= 2T(\frac{n}{2}) + \theta(n) \\
&= 2(2T(\frac{n}{4}) + \theta(\frac{n}{2})) + \theta(n) \\
&= 2^2T(\frac{n}{2^2}) + 2\theta(n) \\
&= 2^2(2T(\frac{n}{2^3}) + \theta(\frac{n}{2^2})) + 2\theta(n) \\
&= 2^3T(\frac{n}{2^3}) + 3\theta(n) \\
&= 2^kT(\frac{n}{2^k}) + k\theta(n) \\
&= 2^{\log_2 n}T(\frac{n}{2^{\log_2 n}}) + \log_2 n\theta(n) \\
&= nT(1) + n\theta(\log_2 n) \\
&= n\theta(\log_2 n) \\
&= \theta(n\log_2 n) \\
\end{aligned}
$$

Example:

```mermaid
graph TD;
    A[8 3 2 9 7 1 5 4] --> B[8 3 2 9]
    A --> C[7 1 5 4]
    B --> D[8 3]
    B --> E[2 9]
    C --> F[7 1]
    C --> G[5 4]
    D --> H[8]
    D --> I[3]
    E --> J[2]
    E --> K[9]
    F --> L[7]
    F --> M[1]
    G --> N[5]
    G --> O[4]
    I --> P[3 8]
    H --> P
    J --> Q[2 9]
    K --> Q
    M --> R[1 7]
    L --> R
    O --> S[4 5]
    N --> S
    P --> T[2 3 8 9]
    Q --> T
    R --> U[1 3 7 8]
    S --> U
    T --> V[1 2 3 4 5 7 8 9]
    U --> V
```

Question: Illustrate the operation of merge sort on the array A = {3, 41, 52, 26, 38, 57, 9, 49}.

```mermaid
graph TD;
    A[3 41 52 26 38 57 9 49] --> B[3 41 52 26]
    A --> C[38 57 9 49]
    B --> D[3 41]
    B --> E[52 26]
    C --> F[38 57]
    C --> G[9 49]
    D --> H[3]
    D --> I[41]
    E --> J[52]
    E --> K[26]
    F --> L[38]
    F --> M[57]
    G --> N[9]
    G --> O[49]
    I --> P[3 41]
    H --> P
    J --> Q[26 52]
    K --> Q
    L --> R[38 57]
    M --> R
    O --> S[9 49]
    N --> S
    P --> T[3 26 41 52]
    Q --> T
    R --> U[9 38 49 57]
    S --> U
    T --> V[3 9 26 38 41 49 52 57]
    U --> V
```

Question: IApply merge sort to sort the list E X A M P L E in alphabetical order.

```mermaid
graph TD;
    A["E X A M P L E"] --> B["E X A M"]
    A --> C["P L E"]
    B --> D["E X"]
    B --> E["A M"]
    C --> F["P L"]
    C --> G["E"]
    D --> H["E"]
    D --> I["X"]
    E --> J["A"]
    E --> K["M"]
    F --> L["P"]
    F --> M["L"]
    G --> N["E"]
    H --> O["E X"]
    I --> O
    J --> P["A M"]
    K --> P
    L --> Q["P L"]
    M --> Q
    N --> R["E"]
    O --> S["A E M X"]
    P --> S
    Q --> T["E L P"]
    R --> T
    S --> U["A E E M M P X"]
    T --> U
```

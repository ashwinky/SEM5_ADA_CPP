#include "merge_sort.hpp"

void merge(int arr[], int l, int m, int r) {
  int n1 = m - l + 1, n2 = r - m;  // Sizes of left and right subarrays

  int* L = new int[n1];  // Left subarray
  int* R = new int[n2];  // Right subarray

  for (int i = 0; i < n1; i++) L[i] = arr[l + i];      // Copy data to left subarray
  for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];  // Copy data to right subarray

  int i = 0, j = 0, k = l;  // Initial indices of left, right and merged subarrays

  // Merge left and right subarrays
  while (i < n1 && j < n2) {
    if (L[i] <= R[j])
      arr[k++] = L[i++];  // If left element is smaller, copy it
    else
      arr[k++] = R[j++];  // Else copy right element
  }

  while (i < n1) arr[k++] = L[i++];  // Copy remaining elements of left subarray
  while (j < n2) arr[k++] = R[j++];  // Copy remaining elements of right subarray

  // Free memory
  delete[] L;
  delete[] R;
}

void merge_sort(int arr[], int l, int r) {
  if (l >= r) return;  // Base case

  int m = l + (r - l) / 2;  // Middle index

  merge_sort(arr, l, m);      // Sort left subarray
  merge_sort(arr, m + 1, r);  // Sort right subarray

  merge(arr, l, m, r);  // Merge sorted subarrays
}

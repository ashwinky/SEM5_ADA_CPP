#include "quick_sort.hpp"

void quick_sort(vector<int> &arr, int left, int right) {
  if (left >= right) return;  // base case
  int pivot = arr[left];      // choose pivot
  int i = left + 1, j = right;
  while (i <= j) {
    while (i <= j && arr[i] <= pivot) i++;  // find element larger than pivot
    while (i <= j && arr[j] > pivot) j--;   // find element smaller than pivot
    if (i < j) swap(arr[i], arr[j]);        // swap the two elements
  }
  swap(arr[left], arr[j]);  // move pivot to its correct position
  quick_sort(arr, left, j - 1);
  quick_sort(arr, j + 1, right);
}

#include "binary_search.hpp"

int binary_search(vector<int> &arr, int target) {
  int left = 0, right = arr.size() - 1;  // set search space
  while (left <= right) {                // search space is not empty
    int mid = (left + right) / 2;        // get the middle element
    if (arr[mid] == target)
      return mid;  // found target
    else if (arr[mid] < target) {
      left = mid + 1;  // target is in the right half
    } else
      right = mid - 1;  // target is in the left half
  }
  return -1;  // target not found
}

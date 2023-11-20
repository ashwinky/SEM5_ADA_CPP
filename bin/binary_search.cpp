// binary search iterative

#include "binary_search.hpp"

int main() {
  vector<int> arr;
  cout << "Enter the elements of the array: ";
  int temp;
  while (cin >> temp) {
    arr.push_back(temp);
  }

  int target;
  cout << "Enter the element to be searched: ";
  cin >> target;

  sort(arr.begin(), arr.end());

  int index = binary_search(arr, target);

  if (index != -1) {
    cout << "Element found at index " << index << endl;
    return 0;
  } else {
    cout << "Element not found in the array" << endl;
    return 1;
  }
}
// Quick Sort Example

#include "quick_sort.hpp"

#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> arr;
  cout << "Enter the elements of the array" << endl;
  cout << "> ";
  string line;
  while (getline(cin, line) && !line.empty()) {
    int temp = stoi(line);
    arr.push_back(temp);
    cout << "> ";
  }

  quick_sort(arr, 0, arr.size() - 1);

  cout << "The sorted array is: { ";
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << ", ";
  }
  cout << "}" << endl;

  return 0;
}
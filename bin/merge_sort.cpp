#include "merge_sort.hpp"

#include <iostream>

#include "utils.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
  int arr[] = {5, 3, 2, 4, 1};

  ARR_PRINT(arr);
  merge_sort(arr, 0, 4);
  ARR_PRINT(arr);

  return 0;
}

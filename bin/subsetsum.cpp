#include <iostream>

#include "utils.hpp"

using namespace std;

int w[] = {5, 10, 12, 13, 15, 18};
int n = 6;
int m = 30;
int x[6] = {0, 0, 0, 0, 0, 0};

void sum_of_subset(int s, int k, int r) {
  x[k] = 1;
  if (s + w[k] == m) {
    ARR_PRINT(x);
  } else if (s + w[k] + w[k + 1] <= m) {
    sum_of_subset(s + w[k], k + 1, r - w[k]);
  }
  if ((s + r - w[k] >= m) && (s + w[k + 1] <= m)) {
    x[k] = 0;
    sum_of_subset(s, k + 1, r - w[k]);
  }
}

int main() {
  int sum = 0;

  for (int i = 0; i < n; i++) sum += w[i];

  sum_of_subset(0, 0, sum);

  return 0;
}

#include <iostream>
#include <string>

#include "longest_common_subsequence.hpp"

int main(int argc, char const *argv[]) {
  int lcs = longest_common_subsequence("ACBAED", "ABCADF");

  std::cout << "Length of LCS: " << lcs << std::endl;

  return 0;
}

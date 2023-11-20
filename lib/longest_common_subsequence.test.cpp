#include "longest_common_subsequence.hpp"

#include "utils.hpp"

TEST("longest common subsequence", {
  UNIT("simple", {
    int lcs = longest_common_subsequence("ABAABA", "BABBAB");

    ASSERT(lcs, 4);
  });
})
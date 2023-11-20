#include <stdio.h>

int main() {
  int A[] = {0, 1, 2, 3, 4};

  int I = 2;

  printf("A[%d]: %d\n", I, A[I]);
  printf("%d[A]: %d\n", I, I[A]);

  return 0;
}

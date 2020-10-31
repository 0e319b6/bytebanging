#include <stdio.h>
#include <stdlib.h>
int main() {
  int prev = 0;
  for (int t = 0;; t++) {
    int output = t*(t+(t>>9|t>>13))%40&120;
    prev = prev * 0.8 + output * 0.2;
    putchar(prev);
  }
}


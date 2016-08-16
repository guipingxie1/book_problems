#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y, c = 1;

  while (scanf("%d %d", &x, &y), (x || y)) {
    if (c > 1)
      printf("\n");

    printf("Field #%d:\n", c++);

    char a[x + 2][y + 2];
    int b[x + 2][y + 2];
    for (int i = 1; i <= x; ++i) 
      for (int j = 1; j <= y; ++j) {
        scanf(" %c", &a[i][j]);
        b[i][j] = 0;
      }

    for (int j = 0; j < y + 2; ++j) 
      b[0][j] = b[x + 1][j] = 0;

    for (int i = 0; i < x + 2; ++i)
      b[i][0] = b[i][y + 1] = 0;

    for (int i = 1; i <= x; ++i)
      for (int j = 1; j <= y; ++j) 
        if (a[i][j] == '*') {
          b[i][j] = -10000000;

          ++b[i - 1][j - 1];
          ++b[i - 1][j];
          ++b[i - 1][j + 1];
          ++b[i][j - 1];
          ++b[i][j + 1];
          ++b[i + 1][j - 1];
          ++b[i + 1][j];
          ++b[i + 1][j + 1];
        }

    for (int i = 1; i <= x; ++i) {
      for (int j = 1; j <= y; ++j) {
        if (b[i][j] > -1)
          printf("%d", b[i][j]);
        else printf("*");
      }

      printf("\n");
    }
  }

  return 0;
}

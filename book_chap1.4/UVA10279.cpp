#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, c = 0;
  scanf("%d", &t);

  while (t--) {
    if (c++)
      printf("\n");

    int x;
    scanf("%d", &x);

    char a[x + 2][x + 2];
    char d[x + 2][x + 2];
    int b[x + 2][x + 2];
    for (int i = 1; i <= x; ++i) 
      for (int j = 1; j <= x; ++j) {
        scanf(" %c", &a[i][j]);
        b[i][j] = 0;
      }

    for (int i = 1; i <= x; ++i) 
      for (int j = 1; j <= x; ++j) 
        scanf(" %c", &d[i][j]);

    for (int j = 0; j < x + 2; ++j) 
      b[0][j] = b[x + 1][j] = 0;

    for (int i = 0; i < x + 2; ++i)
      b[i][0] = b[i][x + 1] = 0;

    bool touched = false;

    for (int i = 1; i <= x; ++i)
      for (int j = 1; j <= x; ++j) 
        if (a[i][j] == '*') {
          if (d[i][j] == 'x')
            touched = true;

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
      for (int j = 1; j <= x; ++j) {
        if (d[i][j] == 'x') {
          if (b[i][j] > -1)
            printf("%d", b[i][j]);
          else printf("*");
        } else {
          if (touched) {
            if (a[i][j] == '*')
              printf("*");
            else printf(".");
          } else {
            printf(".");
          }
        }
      }

      printf("\n");
    }
  }

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

char a[100][100];
char b[100][100];

int beats(int x1, int y1, int x2, int y2) {
  if (a[x1][y1] == 'R' && a[x2][y2] == 'S')
    return 1;

  if (a[x1][y1] == 'P' && a[x2][y2] == 'R')
    return 1;

  if (a[x1][y1] == 'S' && a[x2][y2] == 'P')
    return 1;

  if (a[x1][y1] == a[x2][y2])
    return 2;

  return 0;
}

int main() {
  int t, r, c, n, k, x = 0;
  scanf("%d", &t);

  while (t--) {
    if (x++)
      printf("\n");

    scanf("%d %d %d", &r, &c, &n);

    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j) 
        a[i][j] = b[i][j] = 0;

    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j)
        cin >> a[i][j];

    while (n--) {
      for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
          b[i][j] = 0;

      for (int i = 0; i < r; ++i) 
        for (int j = 0; j < c; ++j) {
          if (i != r - 1) {
            if ((k = beats(i, j, i + 1, j)) == 1) 
              b[i + 1][j] = a[i][j];
            else if (k == 0) b[i][j] = a[i + 1][j];
          }

          if (j != c - 1) {
            if ((k = beats(i, j, i, j + 1)) == 1) 
              b[i][j + 1] = a[i][j];
            else if (k == 0) b[i][j] = a[i][j + 1];
          }
        }

      if (r > 1 && c > 0) {
        if ((k = beats(r - 1, c - 1, r - 2, c - 1)) == 1)
          b[r - 2][c - 1] = a[r - 1][c - 1];
        else if (k == 0) b[r - 1][c - 1] = a[r - 2][c - 1];
      }

      if (c > 1 && r > 0) {
        if ((k = beats(r - 1, c - 1, r - 1, c - 2)) == 1)
          b[r - 1][c - 2] = a[r - 1][c - 1];
        else if (k == 0) b[r - 1][c - 1] = a[r - 1][c - 2];
      }

      for (int i = 0; i < r; ++i) 
        for (int j = 0; j < c; ++j) 
          if (b[i][j] != 0) 
            a[i][j] = b[i][j];
    }

    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j)
        printf("%c", a[i][j]);
      printf("\n");
    }
  }

  return 0;
}

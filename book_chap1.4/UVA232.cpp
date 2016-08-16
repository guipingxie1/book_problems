#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y, p = 1;
  cin >> x >> y;

  while (x) {
    if (p > 1)
      cout << "\n";

    cout << "puzzle #" << p++ << ":\n";
    char a[x][y];
    for (int i = 0; i < x; ++i) 
      for (int j = 0; j < y; ++j)
        cin >> a[i][j];

    int b[x][y];
    for (int i = 0; i < x; ++i) 
      for (int j = 0; j < y; ++j)
        b[i][j] = -1;

    bool prev = true;
    int c = 1;
    for (int i = 0; i < x; ++i) 
      for (int j = 0; j < y; ++j) {
        if (a[i][j] == '*')
          prev = true;

        if (i)
          if (a[i - 1][j] == '*')
            prev = true;

        if (a[i][j] != '*') 
          if (prev) {
            b[i][j] = c++;
            prev = false;
          }

        if (i == 0 || j == y - 1)     // 1st row or 1st column
          prev = true;
      }

    // across first
    cout << "Across\n";
    for (int i = 0; i < x; ++i)
      for (int j = 0; j < y; ++j) 
        if (b[i][j] != -1) 
          if (j == 0 || a[i][j - 1] == '*') {
            if (b[i][j] < 10)
              cout << "  ";
            else cout << " ";

            cout << b[i][j] << ".";
            int k = j;
            while (k != y && a[i][k] != '*') 
              cout << a[i][k++];
            cout << "\n";
          }

    // down
    cout << "Down\n";
    for (int i = 0; i < x; ++i)
      for (int j = 0; j < y; ++j)
        if (b[i][j] != -1) 
          if (i == 0 || a[i - 1][j] == '*') {
            if (b[i][j] < 10)
              cout << "  ";
            else cout << " ";

            cout << b[i][j] << ".";
            int k = i;
            while (k != x && a[k][j] != '*')
              cout << a[k++][j];
            cout << "\n";
          }

    cin >> x >> y;
  }

  return 0;
}

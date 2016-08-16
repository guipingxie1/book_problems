#include <bits/stdc++.h>
using namespace std;

char b[3][3];

bool won(char c) {
  int diag = 0;
  int rdiag = 0;
  for (int i = 0; i < 3; ++i) {
    if ((b[i][0] == c) && (b[i][1] == c) && (b[i][2] == c)) 
      return true;

    if ((b[0][i] == c) && (b[1][i] == c) && (b[2][i] == c)) 
      return true;

    if (b[i][i] == c)
      ++diag;

    if (b[i][2 - i] == c)
      ++rdiag;
  }

  if (diag == 3 || rdiag == 3)
    return true;

  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
        cin >> b[i][j];

    int o, x;
    x = o = 0;

    for (int i = 0; i < 3; ++i) 
      for (int j = 0; j < 3; ++j) {
        if (b[i][j] == 'X')
          ++x;
        else if (b[i][j] == 'O')
          ++o;
      }

    if (o > x || x > 5 || o > 4 || x - o > 1) {
      cout << "no\n";
    } else {
      bool xwon = false;
      bool ywon = false;
      if (won('X'))
        xwon = true;

      if (won('O'))
        ywon = true;

      if (ywon && (x != o)) {
        cout << "no\n";
      } else if (xwon && ywon) {
        cout << "no\n";
      } else if (xwon && (x - o != 1)) {
        cout << "no\n";
      } else {
        cout << "yes\n";
      }
    }
  }

  return 0;
}

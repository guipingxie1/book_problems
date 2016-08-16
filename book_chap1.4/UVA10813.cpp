#include <bits/stdc++.h>
using namespace std;

int b[5][5];
int a[75];

bool bingo() {
  int diag = 0;
  int rdiag = 0;
  for (int i = 0; i < 5; ++i) {
    if (!b[i][0] && !b[i][1] && !b[i][2] && !b[i][3] && !b[i][4])
      return true;

    if (!b[0][i] && !b[1][i] && !b[2][i] && !b[3][i] && !b[4][i])
      return true;

    if (!b[i][i])
      ++diag;

    if (!b[i][4 - i])
      ++rdiag;
  }

  if (diag == 5 || rdiag == 5)
    return true;
  return false;
}

bool add(int k) {
  for (int i = 0; i < 5; ++i) 
    for (int j = 0; j < 5; ++j) 
      if (b[i][j] == k) {
        b[i][j] = 0;
        break;
      }

  if (bingo())
    return true;
  return false;
}

int main() {
  int n;
  cin >> n;

  while (n--) {
    for (int i = 0; i < 5; ++i)
      for (int j = 0; j < 5; ++j) {
        if (i == 2 && j == 2)
          b[2][2] = 0;
        else cin >> b[i][j];
      }

    for (int i = 0; i < 75; ++i)
      cin >> a[i];

    bool won = false;
    int c = 0;
    for (int i = 0; i < 75 && !won; ++i, ++c) {
      if (add(a[i]))
        won = true;
    }

    cout << "BINGO after " << c << " numbers announced\n";
  }

  return 0;
}

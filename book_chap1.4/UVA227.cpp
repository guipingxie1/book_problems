#include <bits/stdc++.h>
using namespace std;

int main() {
  char c[5][5];
  string s;
  int n = 1;

  while (1) {
    getline(cin, s);
    if (s.compare("Z") == 0)
      break;

    if (n > 1)
      cout << "\n";

    int ii, jj;
    int t = 4;
    int k = 1;
    for (int i = 0; i < 5; ++i) {
      c[0][i] = s[i];
      if (s[i] == ' ') {
        ii = 0;
        jj = i;
      }
    }

    while (t--) {
      getline(cin, s);
      for (int i = 0; i < 5; ++i) {
        c[k][i] = s[i];
        if (s[i] == ' ') {
          ii = k;
          jj = i;
        }
      }

      ++k;
    }

    string m = "";
    string tt;

    while (1) {
      getline(cin, tt);
      m += tt;

      if (tt[tt.length() - 1] == '0') 
        break;
    }

    bool ill = false;

    for (int i = 0; i < (m.length() - 1) && !ill; ++i) {
      if (m[i] == 'A') {
        if (ii == 0) {
          ill = true;
        } else {
          c[ii][jj] = c[ii - 1][jj];
          --ii;
          c[ii][jj] = ' ';
        }
      } else if (m[i] == 'B') {
        if (ii == 4) {
          ill = true;
        } else {
          c[ii][jj] = c[ii + 1][jj];
          ++ii;
          c[ii][jj] = ' ';
        }
      } else if (m[i] == 'R') {
        if (jj == 4) {
          ill = true;
        } else {
          c[ii][jj] = c[ii][jj + 1];
          ++jj;
          c[ii][jj] = ' ';
        }
      } else if (m[i] == 'L') {
        if (jj == 0) {
          ill = true;
        } else {
          c[ii][jj] = c[ii][jj - 1];
          --jj;
          c[ii][jj] = ' ';
        }
      } else {
        ill = true;
      }
    }

    cout << "Puzzle #" << n++ << ":\n";

    if (ill) {
      cout << "This puzzle has no final configuration.\n";
    } else {
      for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 4; ++j)
          cout << c[i][j] << " ";
        cout << c[i][4] << "\n";
      }
    }
  }

  return 0;
}

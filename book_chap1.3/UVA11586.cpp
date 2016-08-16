#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  scanf("%d\n", &t);

  while (t--) {
    string s;
    getline(cin, s);

    int m = 0;
    int f = 0;
    int len = s.length();

    for (int i = 0; i < len; ++i) {
      if (s[i] == 'M')
        ++m;

      if (s[i] == 'F')
        ++f;
    }

    if (m != f) {
      cout << "NO LOOP\n";
    } else {
      int mm = 0;
      int ff = 0;
      int rest = 0;
      for (int i = 0; i < len; i += 3) {
        if (s[i] == 'M' && s[i + 1] == 'M') {
          ++mm;
        } else if (s[i] == 'F' && s[i + 1] == 'F') {
          ++ff;
        } else {
          ++rest;
        }
      }

      if (mm == ff) {
        if (mm == 0 && rest == 1)
          cout << "NO LOOP\n";
        else cout << "LOOP\n";
      } else {
        cout << "NO LOOP\n";
      }
    }
  }

  return 0;
}

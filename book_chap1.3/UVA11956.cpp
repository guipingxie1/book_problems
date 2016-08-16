#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, c = 1;
  cin >> t;
  string s;

  while (t--) {
    int a[100];
    for (int i = 0; i < 100; ++i)
      a[i] = 0;

    cout << "Case " << c++ << ": ";
    cin >> s;

    int p = 0;
    int len = s.length();
    for (int i = 0; i < len; ++i) {
      if (s[i] == '>') {
        p = (p + 1) % 100;
      } else if (s[i] == '<') {
        p = (p + 100 - 1) % 100;
      } else if (s[i] == '+') {
        ++a[p];
      } else if (s[i] == '-') {
        --a[p];
      } else {
        /* nothing */
      }
    }

    for (int i = 0; i < 99; ++i) {
      a[i] = ((a[i] % 256) + 256) % 256;
      printf("%02X ", a[i]);
    }

    a[99] = ((a[99] % 256) + 256) % 256;
    printf("%02X\n", a[99]);
  }

  return 0;
}

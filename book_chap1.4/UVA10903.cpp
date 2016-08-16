#include <bits/stdc++.h>
using namespace std;

int main() {
  int p, n, x, y, k = 0;
  string s, t;
  cin >> p >> n;
 
  while (p) {
    if (k++)
      cout << "\n";

    double a[p + 1];
    double b[p + 1];
    for (int i = 1; i <= p; ++i)
      a[i] = b[i] = 0;

    int num = (n * p * (p - 1));
    num >>= 1;
    while (num--) {
      cin >> x >> s >> y >> t;
      if (s[0] == 'r' && t[0] == 's') {
        ++a[x];
        ++b[y];
      } else if (s[0] == 'p' && t[0] == 'r') {
        ++a[x];
        ++b[y];
      } else if (s[0] == 's' && t[0] == 'p') {
        ++a[x];
        ++b[y];
      } else if (s[0] == t[0]) {

      } else {
        ++b[x];
        ++a[y];
      }
    }

    for (int i = 1; i <= p; ++i) { 
      if (a[i] + b[i]) 
        printf("%.3f\n", (a[i]/(a[i] + b[i])));
      else cout << "-\n";
    }

    cin >> p >> n;
  }

  return 0;
}

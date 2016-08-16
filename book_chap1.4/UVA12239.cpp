#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;

  while (x || y) {
    int a[y];
    for (int i = 0; i < y; ++i)
      cin >> a[i];

    int b[x + 1];
    for (int i = 1; i <= x; ++i) 
      b[i] = 0;

    sort(a, a + y);
    for (int i = 0; i < y; ++i) 
      for (int j = i + 1; j < y; ++j) 
        b[a[j] - a[i]] = 1;

    bool yes = true;
    for (int i = 1; i <= x; ++i)
      if (b[i] == 0)
        yes = false;

    if (yes)
      cout << "Y\n";
    else cout << "N\n";

    cin >> x >> y;
  }

  return 0;
}

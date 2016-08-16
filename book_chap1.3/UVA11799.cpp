#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, n, c = 1;
  cin >> t;

  while (t--) {
    cin >> n;
    int m = 0;
    int k;

    for (int i = 0; i < n; ++i) {
      cin >> k;
      m = max(m, k);
    }

    cout << "Case " << c++ << ": " << m << "\n";
  }
  
  return 0;
}

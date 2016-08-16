#include <bits/stdc++.h>
using namespace std;

bool check_str(string s, int mi, int ma) {
  char c = s[mi];
  for (int j = mi + 1; j <= ma; ++j) {
    if (s[j] != c)
      return false;
  }

  return true;
}

int main() {
  string s;
  int c = 1;
  cin >> s;

  while (!cin.eof()) {
    if (s.compare("\n") == 0)
      break;

    int n, mi, ma, x, y;
    cin >> n;

    cout << "Case " << c++ << ":\n";

    for (int i = 0; i < n; ++i) {
      cin >> x >> y;
      mi = min(x, y);
      ma = max(x, y);

      if (check_str(s, mi, ma))
        cout << "Yes\n";
      else cout << "No\n";
    }

    cin >> s;
  }

  return 0;
}



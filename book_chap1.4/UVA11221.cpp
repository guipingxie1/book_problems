#include <bits/stdc++.h>
using namespace std;

bool is_pali(string s) {
  int len = s.length();

  for (int i = 0; i < len / 2; ++i)
    if (s[i] != s[len - 1 - i])
      return false;

  return true;
}

bool is_alpha(char c) {
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int main() {
  int t;
  scanf("%d\n", &t);

  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ":\n";
    string s, t;
    getline(cin, s);
    int len = s.length();

    for (int j = 0; j < len; ++j)
      if (is_alpha(s[j]))
        t += tolower(s[j]);

    if (is_pali(t)) {
      int l = t.length();
      int ans = sqrt(l);
      if (ans * ans == l) 
        cout << ans << "\n";
      else cout << "No magic :(\n";
    } else { cout << "No magic :(\n"; }
  }

  return 0;
}


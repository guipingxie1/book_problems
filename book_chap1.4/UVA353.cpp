#include <bits/stdc++.h>
using namespace std;

bool is_palin(string s) {
  int len = s.length();

  for (int i = 0; i < len / 2; ++i) {
    if (s[i] != s[len - 1 - i])
      return false;
  }

  return true;
}

int main() {
  string s;
  while (getline(cin, s)) {
    set<string> k;
    int plen = 1;
    int len = s.length();

    while (plen <= len) {
      for (int i = 0; i <= len - plen; ++i) {
        string t = s.substr(i, plen);
        if (is_palin(t))
          k.insert(t);
      }

      ++plen;
    }

    cout << "The string '" << s << "' contains " << k.size() << " palindromes.\n";
  }

  return 0;
}

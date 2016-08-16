#include <bits/stdc++.h>
using namespace std;

bool is_pali(string s) {
  int len = s.length();
  for (int i = 0; i < len / 2; ++i)
    if (s[i] != s[len - 1 - i])
      return false;

  return true;
}

bool is_valid(char c) {
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int main() {
  string s;
  getline(cin, s);
  while (s.compare("DONE") != 0) {
    int len = s.length();
    string t;
    for (int i = 0; i < len; ++i) {
      if (is_valid(s[i]))
        t += tolower(s[i]);
    }

    if (is_pali(t))
      cout << "You won't be eaten!\n";
    else cout << "Uh oh..\n";

    getline(cin, s);
  }

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (!cin.eof()) {
    string s[t];
    for (int i = 0; i < t; ++i)
      cin >> s[i];

    string pay, get;
    int c, n;

    map<string, int> p;

    for (int i = 0; i < t; ++i)
      p[s[i]] = 0;

    for (int i = 0; i < t; ++i) {
      cin >> pay >> c >> n;
      if (n != 0)
        p[pay] -= (c - c % n);

      for (int j = 0; j < n; ++j) {
        cin >> get;
        if (n != 0)
          p[get] += c / n;
      }
    }

    for (int i = 0; i < t; ++i) 
      cout << s[i] << " " << p[s[i]] << "\n";

    cin >> t;

    if (!cin.eof())
      cout << "\n";
  }

  return 0;
}



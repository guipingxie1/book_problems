#include <bits/stdc++.h>
using namespace std;

bool is_pali(string s) {
  for (int i = 0; i < s.length() / 2; ++i)
    if (s[i] != s[s.length() - 1 - i])
      return false;

  return true;
}

int main() {
  int n;
  cin >> n;

  while (n--) {
    string s;
    cin >> s;

    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    ++m;

    while (1) {
      if (m == 60) {
        ++h;
        m = 0;
        if (h == 24)
          h = 0;
      }

      if (is_pali(to_string(100 * h + m))) {
        if (h == 0) {
          cout << "00";
        } else if (h < 10) {
          cout << "0";
          cout << h;
        } else {
          cout << h;
        }

        cout << ":";

        if (m == 0) {
          cout << "00";
        } else if (m < 10) {
          cout << "0";
          cout << m;
        } else {
          cout << m;
        }

        cout << "\n";
        break;
      }

      ++m;
    }
  }

  return 0;
}

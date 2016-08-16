#include <bits/stdc++.h>
using namespace std;

bool is_pali(unsigned int n) {
  string s = to_string(n);
  int len = s.length();
  for (int i = 0; i < len / 2; ++i)
    if (s[i] != s[len - i - 1])
      return false;

  return true;
}

unsigned int add_rev(unsigned int n) {
  unsigned int copy = n;
  unsigned int rev = 0;

  while (copy) {
    rev *= 10;
    rev += copy % 10;
    copy /= 10;
  }

  return n + rev;
}

int main() {
  unsigned int k;
  int n;
  cin >> n;

  while (n--) {
    cin >> k;
    int c = 0;
    k = add_rev(k);
    ++c;

    while (!is_pali(k)) {
      ++c;
      k = add_rev(k);
    }

    cout << c << " " << k << "\n";
  }

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int num_digits(int k) {
  int c = 0;
  while (k) {
    k /= 10;
    ++c;
  }

  return c;
} 

int main() {
  string s;
  cin >> s;

  while (s.compare("END") != 0) {
    if (s.compare("1") == 0) {
      cout << 1 << "\n";
    } else {
      int c = 1;
      int len = s.length();

      while (len != 1) {
        ++c;
        len = num_digits(len);
      }

      cout << ++c << "\n";
    }
   
    cin >> s;
  }

  return 0;
}

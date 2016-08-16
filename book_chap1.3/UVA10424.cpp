#include <bits/stdc++.h>
using namespace std;

int to_num(char c) {
  if (isalpha(c) == 0)
    return 0;

  if (c >= 'a' && c <= 'z')
    return (int)(c - 'a') + 1;
  return (int)(c - 'A') + 1;
}

int get_num(int n) {
  if (n / 10 == 0)
    return n;

  int k = 0;

  while (n) {
    k += n % 10;
    n /= 10;
  }

  return get_num(k);
}

int main() {
  string s, t;

  while(1) {
    getline(cin, s);
    getline(cin, t);

    if (cin.eof())
      break;

    int mi, ma, si, ti;
    si = ti = 0;
    for (int i = 0; i < s.length(); ++i)
      si += to_num(s[i]);

    for (int i = 0; i < t.length(); ++i)
      ti += to_num(t[i]);

    int sii = get_num(si);
    int tii = get_num(ti);

    mi = min(sii, tii);
    ma = max(sii, tii);

    if (ma != 0) {
      printf("%.2f ", 100 * (double)mi / (double)ma);
      cout << "%";
    } 

    if (!cin.eof())
      cout << "\n";
  }

  return 0;
}

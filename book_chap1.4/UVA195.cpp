#include <bits/stdc++.h>
using namespace std;

int map_char(char c) {
  if (c > 'Z') {
    int x = (int)c;
    return (x << 1) + 1;
  } 

  int x = (int)(c + 'a' - 'A');
  x <<= 1;
  return x;
}

char map_int(int n) {
  if (n % 2) 
    return (char)((n - 1) >> 1);  

  return (char)((n >> 1) - 'a' + 'A');
}

int main() {
  int t;
  cin >> t;
  string s;

  while (t--) {
    cin >> s;
    vector<string> v;
    int len = s.length();
    int a[len];
    for (int i = 0; i < len; ++i)
      a[i] = map_char(s[i]);

    sort(a, a + len);
    string k = "";

    do {
      k = "";
      for (int i = 0; i < len; ++i) 
        k += map_int(a[i]);

      v.push_back(k);
    } while (next_permutation(a, a + len));

    for (int i = 0; i < v.size(); ++i)
      cout << v[i] << "\n";
  }

  return 0;
}


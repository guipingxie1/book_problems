#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  
  while(1) {
    getline(cin, s);
    if (s.compare("Game Over") == 0)
      break;

    int c = 0;
    vector<char> a[12];
    int frame = 0;
    int k = 0;
    int len = s.length();
    while (k < len) {
      vector<char> v;

      if (s[k] == 'X') {
        v.push_back('X');
      } else {
        v.push_back(s[k]);
        k += 2;
        if (k < len)
          v.push_back(s[k]);
      }
      
      a[frame++] = v;
      k += 2;
    }

    for (int i = 0; i < 10; ++i) {
      if (a[i][0] == 'X') {
        c += 10;
        if (a[i + 1][0] == 'X') {
          c += 10;
          if (a[i + 2][0] == 'X')
            c += 10;
          else c += (int)(a[i + 2][0] - '0');
        } else {
          if (a[i + 1][1] == '/')
            c += 10;
          else c = c + (int)(a[i + 1][0] - '0') + (int)(a[i + 1][1] - '0');
        }
      } else if (a[i][1] == '/') {
        c += 10;
        if (a[i + 1][0] == 'X')
          c += 10;
        else c += (int)(a[i + 1][0] - '0');
      } else {
        c = c + (int)(a[i][0] - '0') + (int)(a[i][1] - '0');
      }
    }

    cout << c << endl;
  }

  return 0;
}

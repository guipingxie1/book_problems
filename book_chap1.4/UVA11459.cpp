#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, a, b, c, k;
  cin >> t;

  while (t--) {
    cin >> a >> b >> c;
    int sl1, sl2;
    map<int, int> m;
    for (int i = 0; i < b; ++i) {
      cin >> sl1 >> sl2;
      m[sl1] = sl2;
    }

    bool won = false;
    int moves[c];
    int pos[a];
    for (int i = 0; i < a; ++i)
      pos[i] = 1;

    for (int i = 0; i < c; ++i) 
      cin >> moves[i];

    for (int i = 0; i < c; ++i) {
      if (!won) {
        int temp = pos[i % a] + moves[i];
        if (m.find(temp) != m.end())
          pos[i % a] = m[temp];
        else pos[i % a] = temp;

        if (pos[i % a] >= 100)
          won = true;
      }
    }

    for (int i = 0; i < a; ++i)
      cout << "Position of player " << i + 1 << " is " << pos[i] << ".\n";
  }

  return 0;
}

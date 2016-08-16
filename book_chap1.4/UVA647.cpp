#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v;
  int k, p, len, s, x, y;
  cin >> k;
  while (k) {
    v.push_back(k);
    cin >> k;
  }

  len = v.size();
  cin >> p;
  while (p) {
    int a[p];
    for (int i = 0; i < p; ++i)
      a[i] = 0;

    cin >> x >> y;
    map<int, int> m;
    while (x && y) {
      m[x] = y;
      cin >> x >> y;
    }

    set<int> skip;
    set<int> again;
    queue<int> skipped;
    cin >> s;
    while (s) {
      if (s > 0)
        again.insert(s);
      else skip.insert(-s);

      cin >> s;
    }

    int turn = 0;
    bool won = false;
    for (int i = 0; i < len && !won; ++i) {
      int temp = v[i] + a[turn];

      while (!skipped.empty() && turn == skipped.front()) {
        turn = (turn + 1) % p;
        skipped.pop();
      }

      if (m.find(temp) != m.end()) {
        a[turn] = m[temp];
        turn = (turn + 1) % p;
      } else if (skip.find(temp) != skip.end()) {
        a[turn] = temp;
        skipped.push(turn);
        turn = (turn + 1) % p;
      } else if (again.find(temp) != again.end()) {   // same turn
        a[turn] = temp;
      } else {
        if (temp == 100) {
          won = true;
        } else if (temp > 100) {
          // nothing
          turn = (turn + 1) % p;
        } else {
          a[turn] = temp;
          turn = (turn + 1) % p;
        }
      }
    }

    cout << turn + 1 << "\n";

    cin >> p;
  }

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t) {
    int m[2 * t][2];
    char a[2 * t];

    for (int i = 0; i < 2 * t; ++i)
      cin >> m[i][0] >> m[i][1] >> a[i];

    set< set<int> > s;
    set<int> s1, s2, s3, s4;
    int t1, t2, t3, t4;
    int play = 1;
    int move = 0;
    bool won = false;

    for (int i = 0; i < 2 * t && !won; ++i) {
      ++move;

      /* 0 rotation */
      t1 = t * m[i][0] + m[i][1];
      /* 90 rotation */
      t2 = t * m[i][1] + t - m[i][0] + 1;
      /* 180 rotation */
      t3 = t * (t - m[i][0] + 1) + t - m[i][1] + 1;
      /* 270 rotation */
      t4 = t * (t - m[i][1] + 1) + m[i][0];

      if (a[i] == '+') {
        s1.insert(t1);
        s2.insert(t2);
        s3.insert(t3);
        s4.insert(t4);
      } else {
        s1.erase(t1);
        s2.erase(t2);
        s3.erase(t3);
        s4.erase(t4);
      }

      if (s.find(s1) != s.end() || s.find(s2) != s.end() || s.find(s3) != s.end() || s.find(s4) != s.end()) {
        cout << "Player " << play + 1 << " wins on move " << move << "\n";
        won = true;
      } else {
        s.insert(s1);
        s.insert(s2);
        s.insert(s3);
        s.insert(s4);
      }

      play = 1 - play;
    }

    if (!won)
      cout << "Draw\n";

    cin >> t;
  }

  return 0;
}

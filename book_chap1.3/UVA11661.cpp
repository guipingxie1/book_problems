#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  while(scanf("%d", &t), t) {
    int d = t;
    char c;
    int count = 0;
    int rest = 0;
    int drug = 0;
    for (int i = 0; i < t; ++i) {
      cin >> c;
      if (c == 'Z') {
        d = 0;
      } else if (c == 'R') {
        if (drug) {
          ++count;
          drug = 0;
          if (count < d)
            d = count;
        }

        count = 0;
        rest = 1;
      } else if (c == 'D') {
        if (rest) {
          ++count;
          rest = 0;
          drug = 1;
          if (count < d)
            d = count;
        }

        count = 0;
        drug = 1;
      } else {
        ++count;
      }
    }

    printf("%d\n", d);
  }

  return 0;
}


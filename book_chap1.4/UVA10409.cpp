#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  string s;

  while (scanf("%d", &t), t) {
    int one = 2;
    int three = 1;
    int four = 4;
    int temp;
    for (int i = 0; i < t; ++i) {
      cin >> s;

      if (s.compare("north") == 0) {
        temp = three;
        three = 7 - one;
        one = temp;
      } else if (s.compare("south") == 0) {
        temp = three;
        three = one;
        one = 7 - temp;
      } else if (s.compare("east") == 0) {
        temp = three;
        three = 7 - four;
        four = temp;
      } else { /* west */
        temp = three;
        three = four;
        four = 7 - temp;
      }
    }

    printf("%d\n", three);
  }

  return 0;
}

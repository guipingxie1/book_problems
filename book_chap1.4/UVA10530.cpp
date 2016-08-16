#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  string a;
  int b[11];
  int c[11];
  for (int i = 0; i < 11; ++i)
    b[i] = c[i] = 0;

  while (scanf("%d\n", &t), t) {
    getline(cin, a);

    switch (a[4]) {
      case 'h' :
        c[t] = 1;
        break;

      case 'l' :
        b[t] = 1;
        break;

      case 't' :
        bool flag = false;

        for (int i = t; i < 11; ++i) 
          if (b[i] == 1) 
            flag = true;

        for (int i = 1; i <= t; ++i)
          if (c[i] == 1)
            flag = true;

        for (int i = 1; i < 11; ++i)
          if (c[i] && b[i])
            flag = true;

        if (flag)
          printf("Stan is dishonest\n");
        else printf("Stan may be honest\n");

        for (int i = 0; i < 11; ++i)
          b[i] = c[i] = 0;
    }
  }

  return 0;
}

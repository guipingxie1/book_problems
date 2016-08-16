#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;

  while (scanf("%d %d", &x, &y), (x || y)) {
    int a[y];
    for (int i = 0; i < y; ++i)  
      scanf("%d", &a[i]);

    int c = 0;

    for (int i = 0; i < x; ++i) {
      int j = 0;

      while (j < y) {
        if (a[j] <= i) {
          ++c;
          while (a[j] <= i) 
            ++j;
        }

        ++j;
      }
    }

    printf("%d\n", c);
  }

  return 0;
}

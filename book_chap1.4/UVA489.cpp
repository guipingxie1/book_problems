#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  string s, k;

  while (scanf("%d", &t)) {
    if (t == -1)
      break;

    printf("Round %d\n", t);
    int a[26];
    for (int i = 0; i < 26; ++i) 
      a[i] = 0;

    cin >> s >> k;

    int miss = 0;
    bool lose = false;
    set<char> ss;
    set<char> kk;

    for (int i = 0; i < s.length(); ++i) 
      ++a[s[i] - 'a'];

    for (int i = 0; i < 26; ++i) 
      if (a[i]) 
        ss.insert((char)(i + 'a'));

    for (int i = 0; i < k.length(); ++i) {
      if (!a[k[i] - 'a']) { 
        if (kk.find(k[i]) == kk.end()) {
          ++miss;
          kk.insert(k[i]);
        }

        if (miss >= 7 && ss.size()) {
          lose = true;
          break;
        } 
      } else {
        if (ss.find(k[i]) != ss.end())
          ss.erase(k[i]);
      }
    }

    if (lose) {
      if (miss >= 7)
        printf("You lose.\n");
      else printf("You chickened out.\n");
    } else {
      if (ss.size() == 0)
        printf("You win.\n");
      else printf("You chickened out.\n");
    }
  }

  return 0;
}


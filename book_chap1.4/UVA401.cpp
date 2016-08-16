#include <bits/stdc++.h>
using namespace std;

map<char, char> mirror;

void fill_map() {
  mirror['A'] = 'A';
  mirror['E'] = '3';
  mirror['H'] = 'H';
  mirror['I'] = 'I';
  mirror['J'] = 'L';
  mirror['L'] = 'J';
  mirror['M'] = 'M';
  mirror['O'] = 'O';
  mirror['S'] = '2';
  mirror['T'] = 'T';
  mirror['U'] = 'U';
  mirror['V'] = 'V';
  mirror['W'] = 'W';
  mirror['X'] = 'X';
  mirror['Y'] = 'Y';
  mirror['Z'] = '5';
  mirror['1'] = '1';
  mirror['2'] = 'S';
  mirror['3'] = 'E';
  mirror['5'] = 'Z';
  mirror['8'] = '8';
}

bool is_pali(string s) {
  int len = s.length();
  for (int i = 0; i < len / 2; ++i) 
    if (s[i] != s[len - 1 - i])
      return false;

  return true;
}

bool is_mirror(string s) {
  int len = s.length();
  int c = 0;
  for (int i = 0; i < len / 2; ++i) 
    if (mirror.find(s[i]) != mirror.end()) 
      if (mirror[s[i]] == s[len - 1 - i])
        ++c;

  if (len & 1)
    if (mirror.find(s[len / 2]) != mirror.end())
      if (mirror[s[len / 2]] == s[len / 2])
        ++c;

  if (c == (len + 1) / 2)
    return true;
  return false;
}

int main() {
  string s;
  fill_map();
  while (getline(cin, s)) {
    if (is_pali(s)) {
      if (is_mirror(s)) 
        cout << s << " -- is a mirrored palindrome.\n\n";
      else cout << s << " -- is a regular palindrome.\n\n";
    } else if (is_mirror(s)) {
      cout << s << " -- is a mirrored string.\n\n";
    } else {
      cout << s << " -- is not a palindrome.\n\n";
    }
  }

  return 0;
}

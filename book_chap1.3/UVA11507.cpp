#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  while (n != 0) {
    string s[n - 1];

    for (int i = 0; i < n - 1; ++i)
      cin >> s[i];

    /*
     * +x: 0
     * -x: 1
     * +y: 2
     * -y: 3
     * +z: 4
     * -z: 5
     */


    int start = 0;

    for (int i = 0; i < n - 1; ++i) {
      if (s[i].compare("+y") == 0) {
        if (start == 0) {
          start = 2;
        } else if (start == 1) {
          start = 3;
        } else if (start == 2) {
          start = 1; 
        } else if (start == 3) {
          start = 0;
        } else {
          /* nothing */
        }
      } else if (s[i].compare("-y") == 0) {
        if (start == 0) {
          start = 3;
        } else if (start == 1) {
          start = 2;
        } else if (start == 2) {
          start = 0; 
        } else if (start == 3) {
          start = 1;
        } else {
          /* nothing */
        }
      } else if (s[i].compare("+z") == 0) {
        if (start == 0) {
          start = 4;
        } else if (start == 1) {
          start = 5;
        } else if (start == 4) {
          start = 1; 
        } else if (start == 5) {
          start = 0;
        } else {
          /* nothing */
        }
      } else if (s[i].compare("-z") == 0) {
        if (start == 0) {
          start = 5;
        } else if (start == 1) {
          start = 4;
        } else if (start == 4) {
          start = 0; 
        } else if (start == 5) {
          start = 1;
        } else {
          /* nothing */
        }
      } else {
        /* nothing */
      }
    }

    if (start == 0) {
      cout << "+x\n";
    } else if (start == 1) {
      cout << "-x\n";
    } else if (start == 2) { 
      cout << "+y\n";
    } else if (start == 3) {
      cout << "-y\n";
    } else if (start == 4) {
      cout << "+z\n";
    } else {
      cout << "-z\n";
    }

    cin >> n;
  }

  return 0;
}

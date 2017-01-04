#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, l, n;
    int k;
    string s;
    cin >> t;
    while (t--) {
        cin >> l >> n;
        l *= 100;
        queue<int> left;
        queue<int> right;

        while (n--) {
            cin >> k >> s;
            if (s[0] == 'l') {
                left.push(k);
            } else {
                right.push(k);
            }
        }
        
        int m = 0;
        bool is_left = true;
        while (1) {
            if (left.empty() && right.empty())
                break;

            int curr = 0;
            int top;
            if (is_left) {
                while (!left.empty()) {
                    top = left.front();
                    if (curr + top <= l) {
                        curr += top;
                        left.pop();
                    } else {
                        break;
                    }
                }
                
                is_left = false;
            } else {
                while (!right.empty()) {
                    top = right.front();
                    if (curr + top <= l) {
                        curr += top;
                        right.pop();
                    } else {
                        break;
                    }
                }
                
                is_left = true;
            }
            
            ++m;
        }
        
        cout << m << "\n";
    }

    return 0;
}

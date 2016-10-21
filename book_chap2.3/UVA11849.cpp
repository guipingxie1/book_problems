#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x;
    while (cin >> n >> m, n || m) {
        int tot = n + m;
        set<int> s;
        while (n--) {
            cin >> x;
            s.insert(x);
        }
        
        while (m--) {
            cin >> x;
            s.insert(x);
        }
        
        cout << tot - s.size() << "\n";
    }
}

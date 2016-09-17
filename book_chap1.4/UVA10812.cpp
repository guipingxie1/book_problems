#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t, a, b;
    cin >> t;

    while (t--) {
        cin >> a >> b;

        long long x, y;
        if ((a + b) % 2) {
            cout << "impossible\n";
        } else {
            x = (a + b) / 2;
            y = a - x;

            if (x >= 0 && y >= 0)
                cout << x << " " << y << "\n";
            else cout << "impossible\n";
        }
    }

    return 0;
}

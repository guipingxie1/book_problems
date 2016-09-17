#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, k, l;
    cin >> t;
    while (t--) {
        cin >> k;
        char c;
        int p;
        map<char, int> m;
        for (int i = 0; i < k; ++i) {
            cin >> c >> p;
            m[c] = p;
        }

        cin >> l;

        string s;
        int cost = 0;
        ++l;
        while (l--) {
            getline(cin ,s);

            int len = s.length();
            for (int i = 0; i < len; ++i)
                if (m.find(s[i]) != m.end())
                    cost += m[s[i]];
        }

        if (cost > 100) {
            cout << cost / 100 << ".";
        } else {
            cout << "0.";
        }

        int rem = cost % 100;
        if (rem > 9) {
            cout << rem << "$\n";
        } else {
            cout << 0 << rem << "$\n";
        }
    }

    return 0;
}

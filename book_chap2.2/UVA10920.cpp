#include <bits/stdc++.h>
using namespace std;

vector<long long> v;
map<long long, int> m;

int find(long long n) {
    if (m.find(n) != m.end())
        return m[n];

    auto it = m.upper_bound(n);
    return it -> second;
}

int main() {
    long long n, t;
    for (long long i = 1; i <= 99999; i += 2) {
        v.push_back(i * i);
        m[i * i] = i;
    }

    while (cin >> n >> t, n || t) {
        long long r = find(t); 
        int line;
        int column;

        if (r * r == t) {
            line = column = (n + 1) / 2 + r / 2;
        } else if (t > r * r - r) {
            long long diff = r * r - t; 
            column = (n + 1) / 2 + r / 2;
            line = (n + 1) / 2 + r / 2 - diff;
        } else if (t > r * r - 2 * r + 1) {
            long long diff = r * r - r + 1 - t;
            line = (n + 1) / 2 - r / 2;
            column = (n + 1) / 2 + r / 2 - diff;
        } else if (t > r * r - 3 * r + 2) {
            long long diff = t - (r * r - 3 * r + 2);
            column = (n + 1) / 2 - r / 2;
            line = (n + 1) / 2 + r / 2 - diff + 1;
        } else {
            long long diff = t - (r * r - 4 * r + 3);
            line = (n + 1) / 2 + r / 2;
            column = (n + 1) / 2 + r / 2 - diff + 1;
        }

        cout << "Line = " << line << ", column = " << column << ".\n";
    }

    return 0;
}

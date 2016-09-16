#include <bits/stdc++.h>
using namespace std;

void convert(int t) {
    int h = t / 3600;
    int m = t % 3600;
    int s = m % 60;
    m /= 60;

    cout << "0" << h << ":";
    if (m < 10) 
        cout << "0" << m << ":";
    else cout << m << ":";

    if (s < 10)
        cout << "0" << s << "\n";
    else cout << s << "\n";
}

int main() {
    int x;

    vector<int> v;
    while (1) {
        cin >> x;
        if (x == 0) {
            if (v.size() == 0) 
                break;

            // do things
            int a[18005];
            for (int i = 1; i < 18001; ++i)
                a[i] = 0;

            int mi = 10000;
            int len = v.size();
            for (int i = 0; i < len; ++i) {
                int e = 0;
                while (e < 18001) {
                    for (int j = 0; j < v[i] - 5 && e <= 18000; ++j) {
                        ++a[e];
                        ++e;
                    }

                    e += v[i] + 5;
                }

                if (v[i] < mi)
                    mi = v[i];
            }

            bool hit = false;
            for (int i = mi - 4; i <= 18000; ++i) 
                if (a[i] == len) {
                    convert(i);
                    hit = true;
                    break;
                }

            if (!hit) 
                cout << "Signals fail to synchronise in 5 hours\n";

            v.clear();
        } else {
            v.push_back(x);
        }
    }

    return 0;
}

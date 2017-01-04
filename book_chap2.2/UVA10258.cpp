#include <bits/stdc++.h>
using namespace std;

int score[101][10];
bool solved[101][10];
bool submitted[101];

struct K {
    int nn;
    int ti;
    int pn;

    bool operator < (const K& k) const {
        if (nn < k.nn)
            return true;

        if (nn == k.nn) {
            if (ti > k.ti) {
                return true;
            }

            if (ti == k.ti) {
                if (pn > k.pn) 
                    return true;
                return false;
            }

            return false;
        }

        return false;
    }
};


int main() {
    int c, p, n, t;
    char r;
    cin >> c;
    cin.ignore();
    string s;
    getline(cin ,s);

    while (getline(cin, s)) {
        if (s.empty()) {
            vector<K> v;
            for (int i = 1; i < 101; ++i) {
                int nn = 0;
                int ti = 0;
                int pn = i;
                for (int j = 1; j < 10; ++j) {
                    if (solved[i][j]) {
                        ++nn;
                        ti += score[i][j];
                    }
                }

                if (submitted[i]) {
                    struct K k;
                    k.nn = nn;
                    k.ti = ti;
                    k.pn = pn;
                    v.push_back(k);
                }
            }

            sort(v.begin(), v.end());

            for (int i = v.size() - 1; i >= 0; --i)
                cout << v[i].pn << " " << v[i].nn << " " << v[i].ti << "\n";
            cout << "\n";

            for (int i = 1; i < 101; ++i) {
                for (int j = 1; j < 10; ++j) {
                    score[i][j] = 0;
                    solved[i][j] = false;
                }
                
                submitted[i] = false;
            }
        } else {
            stringstream ss(s);
            ss >> p >> n >> t >> r;
            if (!solved[p][n]) {
                if (r == 'I') {
                    score[p][n] += 20;
                }

                if (r == 'C') {
                    score[p][n] += t;
                    solved[p][n] = true;
                }
            }
            
            submitted[p] = true;
        }
    }

    vector<K> v;
    for (int i = 1; i < 101; ++i) {
        int nn = 0;
        int ti = 0;
        int pn = i;
        for (int j = 1; j < 10; ++j) {
            if (solved[i][j]) {
                ++nn;
                ti += score[i][j];
            }
        }

        if (submitted[i]) {
            struct K k;
            k.nn = nn;
            k.ti = ti;
            k.pn = pn;
            v.push_back(k);
        }
    }

    sort(v.begin(), v.end());

    for (int i = v.size() - 1; i >= 0; --i)
        cout << v[i].pn << " " << v[i].nn << " " << v[i].ti << "\n";

    return 0;
}

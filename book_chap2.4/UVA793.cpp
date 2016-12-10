#include <bits/stdc++.h>
using namespace std;

int find(int a[], int x) {
    if (a[x] < 0)
        return x;
        
    return a[x] = find(a, a[x]);
}

void union_find(int a[], int x, int y) {
    int xx = find(a, x);
    int yy = find(a, y);
    
    if (xx != yy) {
        if (a[xx] < a[yy]) {
            a[xx] += a[yy];
            a[yy] = xx;
        } else {
            a[yy] += a[xx];
            a[xx] = yy;
        }
    }
}

bool conn(int a[], int x, int y) {
    return find(a, x) == find(a, y);
}

int main() {
    int t, n, x, y;
    char c;
    cin >> t;
    cin.ignore();
    string s;
    
    while (t--) {
        cin >> n;
        int a[n + 1];
        for (int i = 1; i <= n; ++i)
            a[i] = -1;
            
        cin.ignore();
        int succ, unsucc;
        succ = unsucc = 0;
        
        while (1) {
            getline(cin, s);
            if (s.empty())
                break;
                
            stringstream ss(s);
            ss >> c >> x >> y;
            if (c == 'c') {
                union_find(a, x, y);
            } else {
                if (conn(a, x, y))
                    ++succ;
                else ++unsucc;
            } 
        }
        
        cout << succ << "," << unsucc << "\n";
        if (t)
            cout << "\n"; 
    }
    
    return 0;
}

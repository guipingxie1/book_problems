#include <bits/stdc++.h>
using namespace std;

int t, r, k, ai, bi;
char c;
vector<int> a;
vector<int> b;
vector<int> res;

int main() {
    scanf("%d\n", &t);
    
    while (t--) {
        c = 'a';
        while (c != ' ') {
            scanf("%c", &c);
            
            if (c != ' ')
                a.push_back(c - '0');
        }
        
        while (c != '\n') {
            scanf("%c", &c);
            
            if (c != '\n')
               b.push_back(c - '0');
        }
        
        ai = 0;
        bi = 0;
        r = 0;
        
        while (ai != a.size() && bi != b.size()) {
            k = r + a[ai++] + b[bi++];
            r = k / 10;
            k %= 10;
            res.push_back(k);
        } 
        
        while (ai != a.size()) {
            k = r + a[ai++];
            r = k / 10;
            k %= 10;
            res.push_back(k);
        }
        
        while (bi != b.size()) {
            k = r + b[bi++];
            r = k / 10;
            k %= 10;
            res.push_back(k);
        }
        
        if (r)
            res.push_back(r);        
        
        bool f = false;
        for (int i = 0; i < res.size(); ++i) {
            if (f) {
                printf("%d", res[i]);
            } else {
                if (res[i] != 0) {
                    f = true;
                    printf("%d", res[i]);
                }
            }
        }
        printf("\n");
        
        a.clear();
        b.clear();
        res.clear();
    }

    return 0;
}

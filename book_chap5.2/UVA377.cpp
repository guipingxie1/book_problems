#include <bits/stdc++.h>
using namespace std;

map<char, int> m;
int t, n;
char k;
char c[3];
deque<int> a;
deque<int> b;
deque<int> r;

void adde() {
    int re = 0;
    int ai = a.size() - 1;
    int bi = b.size() - 1;
    
    while (ai != -1 && bi != -1) {
        n = a[ai] + b[bi] + re;
        re = n / 4;
        n %= 4;
        b[bi] = n;
        --ai;
        --bi;
    }
    
    if (re) {
        if (bi != -1) {
            while (bi != -1 && re) {
                n = b[bi] + re;
                re = n / 4;
                n %= 4;
                b[bi] = n;
            }
        } else {
            b.push_front(re);
        }
    }
}

bool comp() {
    for (int i = 0; i < 8; ++i)
        if (b[i] != r[i])
            return false;
            
    return true;
}

int main() {
    m['V'] = 0;
    m['U'] = 1;
    m['C'] = 2;
    m['D'] = 3;
    
    printf("COWCULATIONS OUTPUT\n");
    
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 5; ++j) {
                scanf(" %c", &k);
                
                if (i) 
                    b.push_back(m[k]);
                else a.push_back(m[k]);
            }
        
        for (int i = 0; i < 3; ++i)
            scanf(" %c", c + i);    
            
        for (int j = 0; j < 8; ++j) {
            scanf(" %c", &k);
            r.push_back(m[k]);
        }    
        
        for (int i = 0; i < 3; ++i) {
            if (c[i] == 'A') {
                adde();
            } else if (c[i] == 'L') {
                b.push_back(0);
            } else if (c[i] == 'R') {
                b.pop_back();
                b.push_front(0);
            }
        }        
        
        while (b.size() != 8)
            b.push_front(0);
            
        if (comp())
            printf("YES\n");
        else printf("NO\n");
        
        a.clear();
        b.clear();
        r.clear();
    }
    
    printf("END OF OUTPUT\n");
    return 0;
}

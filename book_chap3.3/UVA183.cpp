#include <bits/stdc++.h>
using namespace std;

char mc[205][205];
char build[205][205];
string s;
int idx;
int co = 0;

void get_d(int t, int b, int l, int r) {
    if (t > b || l > r)
        return;
        
    if (t == b && l == r) {
        printf("%c", mc[t][l]);
        
        ++co;
        if (co % 50 == 0) {
            co = 0;
            printf("\n");
        }
    } else {
        bool z = false;
        bool o = false;
        
        for (int i = t; i <= b && !(z && o); ++i)
            for (int j = l; j <= r; ++j) {
                if (mc[i][j] == '0') {
                    z = true;
                    if (o)
                        break;
                } else {
                    o = true;
                    if (z)
                        break;   
                }
            }
                
        if (z && !o) {
            printf("0");
            
            ++co;
            if (co % 50 == 0) {
                co = 0;
                printf("\n");
            }
        } else if (!z && o) {
            printf("1");
            
            ++co;
            if (co % 50 == 0) {
                co = 0;
                printf("\n");
            }
        } else{
            printf("D");
            
            ++co;
            if (co % 50 == 0) {
                co = 0;
                printf("\n");
            }
            
            get_d(t, t + (b - t) / 2, l, l + (r - l) / 2);
            get_d(t, t + (b - t) / 2, 1 + l + (r - l) / 2, r);
            get_d(1 + t + (b - t) / 2, b, l, l + (r - l)  / 2);
            get_d(1 + t + (b - t) / 2, b, 1 + l + (r - l) / 2, r);
        } 
    }    
}

void make(int t, int b, int l, int r) {
    if (idx >= s.size() || t > b || l > r)
        return;
        
    if (t == b && l == r) {
        build[t][l] = s[idx];
        ++idx;
    } else {
        if (s[idx] == 'D') {
            ++idx;
            make(t, t + (b - t) / 2, l, l + (r - l) / 2);
            make(t, t + (b - t) / 2, 1 + l + (r - l) / 2, r);
            make(1 + t + (b - t) / 2, b, l, l + (r - l)  / 2);
            make(1 + t + (b - t) / 2, b, 1 + l + (r - l) / 2, r);
        } else {
            for (int i = t; i <= b; ++i)
                for (int j = l; j <= r; ++j) 
                    build[i][j] = s[idx];
            ++idx;
        }
    }    
}

int main() {
    char c;
    int n, m;
    while (scanf(" %c", &c), c != '#') {
        if (c == 'B') {
            scanf("%d %d", &n, &m);
            
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    scanf(" %c", &mc[i][j]);
            
            int wn = 0;
            int wm = 0;
            
            if (n >= 100)
                wn = 1;
            else if (n >= 10)
                wn = 2;
            else wn = 3;
            
            if (m >= 100)
                wm = 1;
            else if (m >= 10)
                wm = 2;
            else wm = 3;
            
            printf("D"); for (int i = 0; i < wn; ++i) printf(" "); printf("%d", n); for (int i = 0; i < wm; ++i) printf(" "); printf("%d\n", m);   
            co = 0;         
            get_d(0, n - 1, 0, m - 1);
            
            if (co != 0)
                printf("\n");
        } else {
            scanf("%d %d", &n, &m);
            cin >> s;
            
            int wn = 0;
            int wm = 0;
            
            if (n >= 100)
                wn = 1;
            else if (n >= 10)
                wn = 2;
            else wn = 3;
            
            if (m >= 100)
                wm = 1;
            else if (m >= 10)
                wm = 2;
            else wm = 3;
            
            printf("B"); for (int i = 0; i < wn; ++i) printf(" "); printf("%d", n); for (int i = 0; i < wm; ++i) printf(" "); printf("%d\n", m);    
            idx = 0;        
            make(0, n - 1, 0, m - 1);  // may need to change indices
                
            int c = 0;
            for (int i = 0; i < n;  ++i)
                for (int j = 0; j < m; ++j) {
                    printf("%c", build[i][j]);
                    ++c;
                    
                    if (c % 50 == 0) {
                        c = 0;
                        printf("\n");
                    }
                }
            if (c != 0)    
                printf("\n");
        }
    }
    
    return 0;
}   

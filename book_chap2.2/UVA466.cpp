#include <bits/stdc++.h>
using namespace std;

int n, k;
char c[12][12];
char b[12][12];
string m[10];

bool check() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (c[i][j] != b[i][j])
                return false;
                
    return true;
}

void r90() {
    char t[n][n];
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            t[j][n - 1 - i] = b[i][j];
            
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            b[i][j] = t[i][j];
}

void flip() {
    char t[n][n];
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            t[n - 1 - i][j] = b[i][j];
            
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            b[i][j] = t[i][j];
}

int main() {
    int co = 1;
    m[0] = "preserved.";
    m[1] = "rotated 90 degrees.";
    m[2] = "rotated 180 degrees.";
    m[3] = "rotated 270 degrees.";
    m[4] = "reflected vertically.";
    m[5] = "reflected vertically and rotated 90 degrees.";
    m[6] = "reflected vertically and rotated 180 degrees.";
    m[7] = "reflected vertically and rotated 270 degrees.";
    m[8] = "improperly transformed.";
    
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                scanf(" %c", &b[i][j]);
                
            for (int j = 0; j < n; ++j)
                scanf(" %c", &c[i][j]);
        }
              
        k = 0;  
        bool w = false;
        for (int i = 0; i < 4; ++i) {
            if (check()) {
                w = true;
                break;
            }
                
            r90();
            ++k;
        } 
        
        if (!w) {
            flip();
            
            for (int i = 0; i < 4; ++i) {
                if (check())
                    break;
                    
                r90();
                ++k;
            } 
        }
        
        printf("Pattern %d was ", co++);
        cout << m[k] << "\n";
    }
    
    return 0;
}

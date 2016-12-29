#include <bits/stdc++.h>
using namespace std;

string s;
int b[8][8];
int ki[] = {-1, -2, -2, -1, 1, 2, 2, 1}; 
int kj[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int kki[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int kkj[] = {-1, 0, 1, 1, 1, 0, -1, -1}; 

int main() {
    while (getline(cin, s)) {
        memset(b, 0, sizeof(b));
        
        int r = 0;
        int c = 0;
        int rc = r;
        int cc = c;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '/') {
                ++r;
                c = 0;
            } else if (s[i] >= '0' && s[i] <= '8') {
                c += s[i] - '0';
            } else {
                // Is a piece
                b[r][c] = 2;
                ++c;
            }
        }
        
        r = 0;
        c = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '/') {
                ++r;
                c = 0;
            } else if (s[i] >= '0' && s[i] <= '8') {
                c += s[i] - '0';
            } else {
                // Is a piece
                rc = r;
                cc = c;
                
                if (s[i] == 'r' || s[i] == 'R') {
                    rc = r - 1;
                    while (rc >= 0 && b[rc][cc] != 2) {
                        b[rc][cc] = 1;
                        --rc;
                    }
                    
                    rc = r + 1;
                    while (rc < 8 && b[rc][cc] != 2) {
                        b[rc][cc] = 1;
                        ++rc;
                    }
                    
                    rc = r;
                    cc = c - 1;
                    while (cc >= 0 && b[rc][cc] != 2) {
                        b[rc][cc] = 1;
                        --cc;
                    }
                    
                    cc = c + 1;
                    while (cc < 8 && b[rc][cc] != 2) {
                        b[rc][cc] = 1;
                        ++cc;
                    }
                } else if (s[i] == 'n' || s[i] == 'N') {
                    for (int j = 0; j < 8; ++j) {
                        rc = r + ki[j];
                        cc = c + kj[j];
                        if (rc >= 0 && rc < 8 && cc >= 0 && cc < 8 && b[rc][cc] != 2)
                            b[rc][cc] = 1; 
                    }
                } else if (s[i] == 'b' || s[i] == 'B') {
                    rc = r + 1;
                    cc = c + 1;
                    while (rc < 8 && cc < 8 && b[rc][cc] != 2) {
                        b[rc][cc] = 1;
                        ++rc;
                        ++cc;
                    }
                    
                    rc = r + 1;
                    cc = c - 1;
                    while (rc < 8 && cc >= 0 && b[rc][cc] != 2) {
                        b[rc][cc] = 1;
                        ++rc;
                        --cc;
                    }
                    
                    rc = r - 1;
                    cc = c + 1;
                    while (rc >= 0 && cc < 8 && b[rc][cc] != 2) {
                        b[rc][cc] = 1;
                        --rc;
                        ++cc;
                    }
                    
                    rc = r - 1;
                    cc = c - 1;
                    while (rc >= 0 && cc >= 0 && b[rc][cc] != 2) {
                        b[rc][cc] = 1;
                        --rc;
                        --cc;
                    }
                } else if (s[i] == 'q' || s[i] == 'Q') {
                    rc = r - 1;
                    while (rc >= 0 && b[rc][cc] != 2) {
                        b[rc][cc] = 1;
                        --rc;
                    }                                        
                    
                    rc = r + 1;
                    while (rc < 8 && b[rc][cc] != 2) {
                        b[rc][cc] = 1;
                        ++rc;
                    }
                    
                    rc = r;
                    cc = c - 1;
                    while (cc >= 0 && b[rc][cc] != 2) {
                        b[rc][cc] = 1;
                        --cc;
                    }
                    
                    cc = c + 1;
                    while (cc < 8 && b[rc][cc] != 2) {
                        b[rc][cc] = 1;
                        ++cc;
                    }
                    
                    rc = r + 1;
                    cc = c + 1;
                    while (rc < 8 && cc < 8 && b[rc][cc] != 2) {
                        b[rc][cc] = 1;
                        ++rc;
                        ++cc;
                    }
                    
                    rc = r + 1;
                    cc = c - 1;
                    while (rc < 8 && cc >= 0 && b[rc][cc] != 2) {
                        b[rc][cc] = 1;
                        ++rc;
                        --cc;
                    }
                    
                    rc = r - 1;
                    cc = c + 1;
                    while (rc >= 0 && cc < 8 && b[rc][cc] != 2) {
                        b[rc][cc] = 1;
                        --rc;
                        ++cc;
                    }
                    
                    rc = r - 1;
                    cc = c - 1;
                    while (rc >= 0 && cc >= 0 && b[rc][cc] != 2) {
                        b[rc][cc] = 1;
                        --rc;
                        --cc;
                    }
                } else if (s[i] == 'k' || s[i] == 'K') {
                    for (int j = 0; j < 8; ++j) {
                        rc = r + kki[j];
                        cc = c + kkj[j];
                        if (rc >= 0 && rc < 8 && cc >= 0 && cc < 8 && b[rc][cc] != 2)
                            b[rc][cc] = 1; 
                    }
                } else {
                    if (s[i] == 'p') {
                        rc = r + 1;
                        cc = c - 1;
                        if (rc >= 0 && rc < 8 && cc >= 0 && cc < 8 && b[rc][cc] != 2)
                            b[rc][cc] = 1; 
                            
                        rc = r + 1;
                        cc = c + 1;
                        if (rc >= 0 && rc < 8 && cc >= 0 && cc < 8 && b[rc][cc] != 2)
                            b[rc][cc] = 1; 
                    } else {
                        rc = r - 1;
                        cc = c - 1;
                        if (rc >= 0 && rc < 8 && cc >= 0 && cc < 8 && b[rc][cc] != 2)
                            b[rc][cc] = 1; 
                            
                        rc = r - 1;
                        cc = c + 1;
                        if (rc >= 0 && rc < 8 && cc >= 0 && cc < 8 && b[rc][cc] != 2)
                            b[rc][cc] = 1; 
                    }
                }
                
                ++c;
            }            
        }
        
        int co = 0;
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                if (!b[i][j])
                    ++co;
                    
        cout << co << "\n";
    }
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

set<int> s;
set<int> baad;
stack<int> st;
int n, k, t, p;
int a[10];
bool b[10];

bool check(int l) {
    memset(b, false, sizeof(b));
    b[0] = true;
    int c = 1;
    k = a[0] % l;
    
    while (1) {
        if (k == 0 && c == l) {
            return true;
        } else if (b[k]) {
            return false;
        } else {
            b[k] = true;
            k += a[k];
            k %= l;
            ++c;            
        }                
    }
    
    // Never reach
    return false;
}

int main() {
    s.insert(8124956);
    for (int i = 13; i <= 6987543; ++i) {
        k = i;
        
        if (s.find(k) == s.end()) {
            while (!st.empty())
                st.pop();
                
            int c = 0;
            bool w = true;
            memset(b, false, sizeof(b));           
            while (k) {
                p = k % 10;
                st.push(p);
                c += p;
                if (b[p]) {
                    w = false;
                    break;
                }
                
                b[p] = true;
                k /= 10;
            }     
            
            int l = st.size();
            
            if (c % l == 0 && w) {
                for (int j = 0; j < l; ++j) {
                    a[j] = st.top();
                    st.pop();
                }
                
                if (check(l)) {
                    s.insert(i);
                    
                    k = i;
                    t = 1;
                    for (int j = 1; j < l; ++j)
                        t *= 10;
                    
                    for (int j = 1; j < l; ++j) {
                        p = k / t;
                        k %= t;
                        k *= 10;
                        k += p;
                        s.insert(k);
                    }
                } 
            }
        }   
    } 
    
    int c = 1;    
    while (scanf("%d", &n), n)         
        printf("Case %d: %d\n", c++, *(s.lower_bound(n)));    
    
    return 0;
}

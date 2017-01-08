#include <bits/stdc++.h>
using namespace std;

string s, wo;
long long w[15];
map<long long, int> m;
long long k, c, n;
priority_queue<long long> pq;
set<long long> v;

bool test() {
    c = -1 * pq.top();
    pq.pop();
    
    m.clear();
    for (int i = 0; i < n; ++i) {
        k = (c / w[i]) % n;
        
        if (m.find(k) != m.end()) {
            if (v.find(((c / w[i]) + 1) * w[i]) == v.end()) {
                pq.push(-1 * ((c / w[i]) + 1) * w[i]);
                v.insert(((c / w[i]) + 1) * w[i]);
            }
                
            if (v.find(((c / w[m[k]]) + 1) * w[m[k]]) == v.end()) {
                pq.push(-1 * ((c / w[m[k]]) + 1) * w[m[k]]);
                v.insert(((c / w[m[k]]) + 1) * w[m[k]]);
            }
                
            return true;
        } else {
            m[k] = i;
        }
    }
    
    return false;
}

int main() {
    while (getline(cin, s)) {
        stringstream ss(s);
        n = 0;
        
        while (ss >> wo) {
            k = 0;
            for (int i = 0; i < wo.length(); ++i) {
                k *= 32;
                k += (wo[i] - 'a' + 1);
            }
            
            w[n++] = k;
        }
        
        for (int i = 0; i < n; ++i)
            pq.push(-1 * w[i]);
            
        while (test());
        
        cout << s << "\n" << c << "\n\n";
        while (!pq.empty())
            pq.pop();
        m.clear();
        v.clear();
    }
    
    return 0;
}

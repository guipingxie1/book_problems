#include <bits/stdc++.h>
using namespace std;

int a[12];
bool v[10005];
int t, d, k;

int main() {
    int start, end, n;
    int c = 1;
    while (scanf("%d %d %d", &start, &end, &n), start || end || n) {
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
            
        if (start != end) {
            memset(v, false, sizeof(v));
            int ans = 100000;
            
            queue<int> q;
            v[start] = true;
            q.push(10000 * start);
            
            while (!q.empty()) {
                t = q.front();
                q.pop();
                d = t % 10000;
                t /= 10000;
                
                bool br = false;
                for (int i = 0; i < n; ++i) {
                    k = (t + a[i]) % 10000;
                    
                    if (k == end) {
                        ans = d + 1;
                        br = true;
                        break;
                    }
                    
                    if (!v[k]) {
                        v[k] = true;
                        q.push(10000 * k + d + 1);
                    }
                }
                
                if (br)
                    break;
            }
            
            if (ans != 100000)
                printf("Case %d: %d\n", c++, ans);
            else printf("Case %d: Permanently Locked\n", c++);
        } else {
            printf("Case %d: 0\n", c++);
        }
    }
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n, t, k, co, p, s, x;
map<int, int> m;

bool is(int num) {
    for (int i = 2; i * i <= num; ++i)
        if (num % i == 0)
            return false;
            
    return true;
}

int count(int num) {
    int c = 0;
    
    while (num) {
        c += num % 10;
        num /= 10;
    }
    
    return c;
}

int main() {
    m[2] = 2;
    m[3] = 3;
    m[5] = 5;
    m[7] = 7;
    m[11] = 2;
    
    for (int i = 13; i * i < 1000000000; i += 2) 
        if (is(i))
            m[i] = count(i);
    
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d", &n);
        x = n + 1;
        
        while (1) {
            k = x;
            
            if (!is(k)) {
                co = count(k);
                int sum = 0;
                
                for (auto it = m.begin(); it != m.end() && sum < co && k != 1; ++it) {
                    p = it -> first;
                    s = it -> second;
                    
                    if (k % p == 0) 
                        while (k % p == 0) {
                            sum += s;
                            k /= p;
                        }
                }
                
                if (sum == co && k == 1) {
                    printf("%d\n", x);
                    break;
                } else if (sum < co && k != 1) {
                    sum += count(k);
                    
                    if (sum == co) {
                        printf("%d\n", x);
                        break;
                    }
                }
            }
            
            ++x;
        }
    }
    
    return 0;
}

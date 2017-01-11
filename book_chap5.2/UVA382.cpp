#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
long long n;

void get(long long n) {
    long long c = n;
    
    int idx = 0;
    vector< pair<int, int> > v;
    while (c != 1) {
        if (c % primes[idx] == 0) {
            int co = 0;
            
            while (c % primes[idx] == 0) {
                c /= primes[idx];
                ++co;   
            }
            
            v.push_back(make_pair(primes[idx], co));
        }
        
        ++idx;
    }
    
    long long m = 1;
    for (int i = 0; i < v.size(); ++i) {
        long long k = 1;
        
        for (int j = 1; j <= v[i].second; ++j)
            k += pow(v[i].first, j);
            
        m *= k;
    }
    
    if (m == 2 * n) {
        printf("PERFECT\n");
    } else if (m < 2 * n) {
        printf("DEFICIENT\n");
    } else {
        printf("ABUNDANT\n");
    }
}

bool is(int k) {
    for (int i = 3; i * i <= k; ++i)
        if (k % i == 0)
            return false;
            
    return true;
}

void fill() {
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);
    
    for (int i = 7; i < 60000; i += 2)
        if (is(i))
            primes.push_back(i);
}

int main() {
    fill();
    printf("PERFECTION OUTPUT\n");
    
    while (scanf("%lld", &n), n) {
        printf("%5lld  ", n);    
        get(n);
    } 
    
    printf("END OF OUTPUT\n");
    
    return 0;
}

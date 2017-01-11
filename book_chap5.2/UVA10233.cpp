#include <bits/stdc++.h>
using namespace std;

#define SQ 1.7320508075688773

long long n, m, a, b, i1, i2, o1, o2, d;
double xx1, yy1, xx2, yy2;
vector<long long> v;

int main() {
    long long k = 0;
    while (k * k <= 2147483647) {
        v.push_back(k * k);
        ++k;
    }

    while (scanf("%lld %lld", &n, &m) == 2) {
        if (m == n) {
            printf("0.000\n");
        } else {
            i1 = lower_bound(v.begin(), v.end(), n) - v.begin();
            i2 = lower_bound(v.begin(), v.end(), m) - v.begin();
            if (m != v[i2])
                --i2;
                
            if (n != v[i1])
                --i1;
                
            o1 = n - v[i1];
            o2 = m - v[i2];
            
            xx2 = (1.0 + o2) / 2.0;
            if (o2 & 1) 
                yy2 = 1.0 / SQ;
            else yy2 = 1.0 / (2.0 * SQ); 
            
            xx1 = (1.0 + o1) / 2.0;
            if (o1 & 1) 
                yy1 = 1.0 / SQ;
            else yy1 = 1.0 / (2.0 * SQ); 
            
            if (m > n) {
                d = i2 - i1;
                xx1 += (double)d / 2.0;
                yy1 += (double)d * SQ / 2.0;
            } else {
                d = i1 - i2;
                xx2 += (double)d / 2.0;
                yy2 += (double)d * SQ / 2.0;
            }
            
            printf("%.3f\n", sqrt((xx1 - xx2) * (xx1 - xx2) + (yy1 - yy2) * (yy1 - yy2)));
        }
    }
    
    return 0;
}   

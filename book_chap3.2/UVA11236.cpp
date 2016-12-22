#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    
    for (int i = 1; i < 159; ++i)
        for (int j = i; j <= 1600; ++j)
            for (int l = max(j, 159); l <= (2000 - i - j); ++l) 
                if (i * j * l != 1000000) {
                    k = ((long long)(i + j + l) * 1000000) / ((long long)(i * j * l) - 1000000);
                    
                    if (k >= j && k <= l && (i + j + k + l <= 2000)) {
                        long long p = i * j * k * l;
                        long long sum = (i + j + k + l) * 1000000; 
                        
                        if (p == sum)
                            printf("%.2f %.2f %.2f %.2f\n", i / 100.0, j / 100.0, k / 100.0, l / 100.0);  
                    }     
                }
                
    return 0;
}

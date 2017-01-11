#include <bits/stdc++.h>
using namespace std;

int a, b, v, t, s;
double x, y;

# define PI 3.14159265358979323846

int main() {
    while (scanf("%d %d %d %d %d", &a, &b, &v, &t, &s), a) {
        x = v * s * sin(t / 180.0 * PI) / 2.0 + b / 2.0;
        y = v * s * cos(t / 180.0 * PI) / 2.0 + a / 2.0;
        printf("%d %d\n", (int)(y / a), (int)(x / b));
    }
    
    return 0;
}

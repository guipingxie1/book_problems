#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (getline(cin ,s)) {
        if (s == "0:00")
            break;

        int h, m;
        h = stoi(s.substr(0, s.find(":")));
        m = stoi(s.substr(s.find(":") + 1));
        double d;
        if ((double)m / 5.0 - ((double)h + (double)(m) / 60.0) >= 0.0) {
            d = (double)m / 5.0 - ((double)h + (double)(m) / 60.0);
        } else {
            d = ((double)h + (double)m / 60.0) - (double)m / 5.0;
        }

        d *= 30.0;
        if (d >= 180.0) 
            d = 180.0 - (d - 180.0);

        printf("%.3f\n", d);
    }

    return 0;
}

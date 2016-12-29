#include <bits/stdc++.h>
using namespace std;

int n, p, met;
string s, ig;
double bestcost, co;
string best;

int main() {
    int c = 1;
    while (cin >> n >> p, n || p) {
        cin.ignore();
        if (c != 1)
            printf("\n");
            
        for (int i = 0; i < n; ++i)
            getline(cin, ig);
            
        int ma = 0;
        bestcost = 100000000;
        
        for (int i = 0; i < p; ++i) {
            getline(cin, s);
            cin >> co >> met;
            cin.ignore();
            
            for (int j = 0; j < met; ++j)
                getline(cin, ig);
            
            if (met == ma) {
                if (co < bestcost) {
                    best = s;
                    bestcost = co; 
                }
            } else if (met > ma) {
                ma = met;
                best = s;
                bestcost = co; 
            }   
        }
        
        printf("RFP #%d\n", c++);
        cout << best << "\n";
    }
    
    return 0;
}

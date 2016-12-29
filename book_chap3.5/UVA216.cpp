#include <bits/stdc++.h>
using namespace std;

int n;
int a[10][2];
double dp[10][260];
int dir[10][260];

double dist(int i, int j) {
    return (double)16 + sqrt((a[i][0] - a[j][0]) * (a[i][0] - a[j][0]) + (a[i][1] - a[j][1]) * (a[i][1] - a[j][1]));
}

double tsp(int curr, int k, vector<int> v) {
    if (k == (1 << n) - 1)
        return 0;
    
    if (dp[curr][k] >= 0)
        return dp[curr][k];
    
    double ans = 1000000;  
    double d = 0;
    int idx = 0;
    for (int i = 0; i < n; ++i)
        if (!(k & 1 << i)) {
            v.push_back(i);
            
            d = dist(curr, i) + tsp(i, k | (1 << i), v);
            if (d < ans) {
                idx = i;
                ans = d;
            }
            
            v.pop_back();
        }
    
    dir[curr][k] = idx;    
    return dp[curr][k] = ans;
}

int main() {
    int c = 1;
    while (scanf("%d", &n), n) {
        for (int i = 0; i < n; ++i)
            scanf("%d %d", &a[i][0], &a[i][1]);        
        
        double real_ans = 1000000;
        vector<int> real_sol;
        
        for (int i = 0; i < n; ++i) {        
            memset(dp, -1, sizeof(dp));
                    
            vector<int> sol;
            sol.push_back(i);
            double ans = tsp(i, 1 << i, sol);
            
            int idx = 1;
            int k = 1 << i;
            int town = i;
            int co = i;
            while (idx != n) {
                sol.push_back(dir[town][k]);
                co = town;
                town = dir[town][k];
                k |= 1 << dir[co][k];
                ++idx;
            }
            
            if (ans < real_ans) {
                real_ans = ans;
                real_sol = sol;
            }
        }
            
        printf("**********************************************************\n");
        printf("Network #%d\n", c++);
        
        for (int i = 0; i < n - 1; ++i) 
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n", a[real_sol[i]][0], a[real_sol[i]][1], a[real_sol[i + 1]][0], a[real_sol[i + 1]][1], dist(real_sol[i], real_sol[i + 1]));
        
        printf("Number of feet of cable required is %.2f.\n", real_ans);
    }
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > a[17];
vector<int> in[17];

void get(int idx, int end, vector<int> v, int k) {
    if (idx == end) {
        if (v[end - 1] == 2 || v[end - 1] == 4 || v[end - 1] == 6 || v[end - 1] == 10 || v[end - 1] == 12 || v[end - 1] == 16)
            a[end].push_back(v);
        return;
    }

    for (int i = 0; i < in[v[idx - 1]].size(); ++i) { 
        int val = in[v[idx - 1]][i];
        
        if (val <= end) {
            if (!(k & 1 << val)) { 
                int m = k;
                m |= 1 << val;
                v[idx] = val;
                get(idx + 1, end, v, m);
            }
        } else {
            break;
        }
    }
}

int main() {
    vector<int> in1 = {2, 4, 6, 10, 12, 16};
    in[1] = in1;
    vector<int> in2 = {1, 3, 5, 9, 11, 15};
    in[2] = in2;
    vector<int> in3 = {2, 4, 8, 10, 14, 16};
    in[3] = in3;
    vector<int> in4 = {1, 3, 7, 9, 13, 15};
    in[4] = in4;
    vector<int> in5 = {2, 6, 8, 12, 14};
    in[5] = in5;
    vector<int> in6 = {1, 5, 7, 11, 13};
    in[6] = in6;
    vector<int> in7 = {4, 6, 10, 12, 16};
    in[7] = in7;
    vector<int> in8 = {3, 5, 9, 11, 15};
    in[8] = in8;
    vector<int> in9 = {2, 4, 8, 10, 14};
    in[9] = in9;
    vector<int> in10 = {1, 3, 7, 9, 13};
    in[10] = in10;
    vector<int> in11 = {2, 6, 8, 12};
    in[11] = in11;
    vector<int> in12 = {1, 5, 7, 11};
    in[12] = in12;
    vector<int> in13 = {4, 6, 10, 16};
    in[13] = in13;
    vector<int> in14 = {3, 5, 9, 15};
    in[14] = in14;
    vector<int> in15 = {2, 4, 8, 14, 16};
    in[15] = in15;
    vector<int> in16 = {1, 3, 7, 13, 15};
    in[16] = in16;
    
    vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);
    a[2].push_back(v2);
    
    for (int i = 4; i <= 16; i += 2) {
        vector<int> v(i);
        v[0] = 1;
        int k = 0;
        k |= 1 << 1;
        
        get(1, i, v, k);
    }
    
    int n;
    int c = 1;
    while (scanf("%d", &n) != EOF) {
        if (c != 1)
            printf("\n");
        printf("Case %d:\n", c++);
        
        for (int i = 0; i < a[n].size(); ++i) {
            for (int j = 0; j < n - 1; ++j)
                printf("%d ", a[n][i][j]);
            printf("%d\n", a[n][i][n - 1]);
        }
    }
    
    return 0;
}

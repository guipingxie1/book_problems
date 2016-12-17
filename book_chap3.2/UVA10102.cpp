#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;	
    int a[] = {1, 0, 0, -1};
    int b[] = {0, 1, -1, 0};
	
	while (scanf("%d\n", &n) != EOF) {
		char c[n][n];
		
		vector<int> v;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				scanf(" %c", &c[i][j]);
				//cin >> c[i][j];
				if (c[i][j] == '1')
					v.push_back(i * n + j);	
			}
				
		int ma = 0;
		
		for (int i = 0; i < v.size(); ++i) {
			queue< pair<int, int> > q;
			q.push(make_pair(v[i], 0));
			bool visit[n * n];
			memset(visit, false, sizeof(visit));
			visit[v[i]] = true;
			bool flag = true;
			int x, y, temp, d, xx, yy, k;
			
			while (!q.empty() && flag) {
				temp = q.front().first;
				d = q.front().second;
				q.pop();
				x = temp / n;
				y = temp % n;
				
				for (int j = 0; j < 4; ++j) {
				    xx = x + a[j];
				    yy = y + b[j];
				    
				    if (xx >= 0 && xx < n && yy >= 0 && yy < n) {
				        k = xx * n + yy;
				        if (!visit[k]) {
				            if (c[xx][yy] == '3') {
				                ma = max(ma, d + 1);
				                flag = false;
				                break;
				            }
				            
				            visit[k] = true;
				            q.push(make_pair(k, d + 1));
				        }
				    }
				}   
			}
		}
		
		printf("%d\n", ma);
	}
	
	return 0;
}

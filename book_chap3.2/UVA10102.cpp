#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		char c[n][n];
		
		vector<int> v;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				scanf("%c", &c[i][j]);
				if (c[i][j] == 1)
					v.push_back(i * n + j);	
			}
				
		int ma = 0;
		
		for (int i = 0; i < v.size(); ++i) {
			queue< pair<int, int> > q;
			q.push(v[i]);
			bool visit[n * n];
			memset(visit, false, sizeof(visit));
			visit[v[i]] = true;
			bool flag = true;
			
			while (!q.empty() && flag) {
				int temp = q.front().first;
				int d = q.front().second;
				q.pop();
				int x = temp / n;
				int y = temp % n;
				
				if (x == 0) {
					if (y == 0) {
						if (!visit[1]) {
							if (c[0][1] == 3) {
								ma = max(d + 1, ma);
								flag = false;
								break;
							}
							
							q.push(make_pair(1, d + 1));
							visit[1] = true;
						}
						
						if (!visit[n]) {
							if (c[1][0] == 3) {
								ma = max(d + 1, ma);
								flag = false;
								break;
							}
							
							q.push(make_pair(n, d + 1));
							visit[n] = true;
						}
					} else if (y == n) {
						if (!visit[n - 1]) {
							if (c[0][n - 1] == 3) {
								ma = max(d + 1, ma);
								flag = false;
								break;
							}
							
							q.push(1);
							visit[1] = true;
						}
						
						if (!visit[2 * n]) {
							q.push();
							visit[n] = true;
						}
					} else {
						
					}
				} else if (x == n) {
				
				} else {
				
				}
			}
		}
	}
	
	return 0;
}

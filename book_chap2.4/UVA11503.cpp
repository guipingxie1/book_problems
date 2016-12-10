#include <bits/stdc++.h>
using namespace std;

int find(int a[], int x) {
	if (a[x] < 0)
		return x;
		
	return a[x] = find(a, a[x]);
}

void union_find(int a[], int x, int y) {
	int xx = find(a, x);
	int yy = find(a, y);
	
	if (xx != yy) {
		if (a[xx] < a[yy]) {
			a[xx] += a[yy];
			a[yy] = xx;
			cout << -1 * a[xx] << "\n";
		} else {
			a[yy] += a[xx];
			a[xx] = yy;
			cout << -1 * a[yy] << "\n";
		}
	} 
	else {
		cout << -1 * a[xx] << "\n";
	}
}

int main() {
	int t, n;
	cin >> t;
	
	while (t--) {
		cin >> n;
		string s, r;
		map<string, int> m;
		int j = 1;
		int a[100005];
		a[0] = -1;
		for (int i = 0; i < n; ++i) {
			cin >> s >> r;
			if (m.find(s) == m.end()) {
				m[s] = j;
				a[j] = -1;
				++j;
			}
			
			if (m.find(r) == m.end()) {
				m[r] = j;
				a[j] = -1;
				++j;
			}
			
			union_find(a, m[s], m[r]);
		}
	}
	
	return 0;
}

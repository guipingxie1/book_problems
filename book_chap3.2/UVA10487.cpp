#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, q;
	int c = 1;
	while (scanf("%d", &n), n) {
		int a[n];
		for (int i = 0; i < n; ++i)
			scanf("%d", a + i);
			
		set<int> s;
		for (int i = 1; i < n; ++i)
			for (int j = 0; j < i; ++j)
				s.insert(a[i] + a[j]);	
		
		scanf("%d", &m);
		printf("Case %d:\n", c++);
		for (int i = 0; i < m; ++i) {
			scanf("%d", &q);
			
			int res;
			auto it = s.lower_bound(q);
			if (*it == q) {
				res = q;
			} else if (it != s.begin()) {
				int val = *it;
				--it;
				if (abs(*it - q) < abs(val - q))
					res = *it;
				else res = val;
			} else if (it == s.end()) {
				--it;
				res = *it;
			} else {
				res = *it;
			}
			
			printf("Closest sum to %d is %d.\n", q, res);
		}
	}
	
	return 0;
}

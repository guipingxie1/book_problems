#include <bits/stdc++.h>
using namespace std;

long long power(int j, int b) {
	long long res = 1;
	for (int i = 0; i < b; ++i)
		res *= j;
	
	return res;
}

long long get(int j, int a[], int n) {
	long long res = 0;
	for (int i = 0; i <= n; ++i) 
		res += ((long long)a[i] * power(j, i));
		
	return res;
}

int main() {
	int t, n, d, k;
	cin >> t;
	
	while (t--) {
		cin >> n;
		int a[n + 1];
		for (int i = 0; i <= n; ++i)
			cin >> a[i];
			
		cin >> d >> k;
		
		long long c = 0;
		int j = 1;
		while (c < k) {
			c += d * j;
			++j;
		}
		
		cout << get(j - 1, a, n) << "\n";
	}
	 
	return 0;
}

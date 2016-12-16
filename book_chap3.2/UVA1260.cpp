#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n;
	scanf("%d", &t);
	
	while (t--) {
		scanf("%d", &n);
		int a[n];
		
		for (int i = 0; i < n; ++i)
			scanf("%d", a + i);
		
		int c = 0;	
		for (int i = 1; i < n; ++i)
			for (int j = 0; j < i; ++j) 
				if (a[i] >= a[j])
					++c;
					
		printf("%d\n", c);		
	}
	
	return 0;
}

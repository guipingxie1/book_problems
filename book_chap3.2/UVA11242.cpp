#include <bits/stdc++.h>
using namespace std;

int main() {
	int f, r;
	
	while (scanf("%d %d\n", &f, &r), f) {
		int a[f];
		int b[r];
		int size = f * r;
		
		for (int i = 0; i < f; ++i)
			scanf("%d", a + i);
			
		for (int i = 0; i < r; ++i)
			scanf("%d", b + i);
		
		double d[size];
		for (int i = 0; i < f; ++i)
			for (int j = 0; j < r; ++j)
				d[i * r + j] = (double)b[j] / (double)a[i];
				
		sort(d, d + size);
		double max_spread = 0;
		for (int i = 1; i < size; ++i)
			max_spread = max(max_spread, d[i] / d[i - 1]);
			
		printf("%.2f\n", max_spread);
	}
	
	return 0;
}

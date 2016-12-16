#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	bool b = false;
	while (scanf("%d", &n), n) {
		if (b) 
			printf("\n");
		else b = true;
		
		int a[n];
		for (int i = 0; i < n; ++i)
			scanf("%d", a + i);
			
		for (int i = 0; i < n; ++i) 
			for (int j = i + 1; j < n; ++j)
				for (int k = j + 1; k < n; ++k)
					for (int l = k + 1; l < n; ++l)
						for (int m = l + 1; m < n; ++m)
							for (int o = m + 1; o < n; ++o)
								printf("%d %d %d %d %d %d\n", a[i], a[j], a[k], a[l], a[m], a[o]);
	}
	
	return 0;
}

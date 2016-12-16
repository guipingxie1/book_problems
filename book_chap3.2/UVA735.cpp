#include <bits/stdc++.h>
using namespace std;
					

int main() {
	int n;
	while (scanf("%d", &n), n > 0) {
		int c = 0;
		int p = 0;
		int bound = min(20, n);
		for (int i = 1; i <= bound; ++i)
			for (int j = i; j <= bound; ++j)
				for (int k = j; k <= bound; ++k) 
					for (int x = 1; x <= 3; ++x) {
						for (int y = 1; y <= 3; ++y) {
							for (int z = 1; z <= 3; ++z) {
								if (i * x + j * y + k * z == n) {
									cerr << i << " " << j << " " << k << " " << x << " " << y << " " << z << "\n";
									++c;
								}
								
								if (i * x + k * z + 50 == n || i * x + k * z == n) {
									cerr << i << " " << j << " " << k << " " << x << " " << y << " " << z << "\n";
									++c;
								}
					
								if (j * y + k * z + 50 == n || j * y + k * z == n) {
									cerr << i << " " << j << " " << k << " " << x << " " << y << " " << z << "\n";
									++c;
								}								
									
								if (k * z + 100 == n || k * z + 50 == n || k * z == n) {
									cerr << i << " " << j << " " << k << " " << x << " " << y << " " << z << "\n";
									++c;
								}
							}
							
							if (i * x + j * y + 50 == n || i * x + j * y == n) {
								cerr << i << " " << j << " " << k << " " << x << " " << y << "\n";
								++c;
							}
								
							if (j * y + 100 == n || j * y + 50 == n || j * y == n) {
								cerr << i << " " << j << " " << k << " " << x << " " << y << "\n";
								++c;
							}
						}
						
						if (i * x + 100 == n || i * x + 50 == n || i * x == n) {
							cerr << i << " " << j << " " << k << " " << x << "\n";
							++c;
						}
					}
	
		if (n == 150)
			++c;
			
		if (c) {
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, c);
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, p);
		} else {
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
		}
		
		printf("**********************************************************************\n");
	}
	
	printf("END OF OUTPUT\n");
	
	return 0;
}	

#include <bits/stdc++.h>
using namespace std;

int valid[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 24, 26, 27, 28, 30, 32, 33, 34, 36, 38, 39, 40, 42, 45, 48, 50, 51, 54, 57, 60};					

int main() {
	int n;
	while (scanf("%d", &n), n > 0) {
		int c = 0;
		int p = 0;
		
		int bound = 43;
		for (int i = 0; i < 43; ++i)
			if (valid[i] > n) {
				bound = i;
				break;
			}
			
		for (int i = 0; i < bound; ++i)
			for (int j = 0; j < bound; ++j)
				if ((valid[i] + valid[j]) <= n)
					for (int k = 0; k < bound; ++k) {
						if (valid[i] + valid[j] + valid[k] == n) {
							if (i <= j && j <= k) {
								++c;	
								++p;
							} else {
								++p;
							}
						} else if (valid[i] + valid[j] + valid[k] > n) {
							break;
						}
					}
						
			
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

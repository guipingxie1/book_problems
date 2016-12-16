#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (scanf("%d\n", &n) != EOF) {
		set< pair<int, int> > s;
		
		// n < y <= 2 * n
		for (int y = n << 1; y > n; --y) 
			if ((n * y) % (y - n) == 0)
				s.insert(make_pair((n * y) / (y - n), y));  	
		
		printf("%d\n", s.size());
		for (auto it = s.rbegin(); it != s.rend(); ++it) 
			printf("1/%d = 1/%d + 1/%d\n", n, (*it).first, (*it).second);
	}
	
	return 0;
}

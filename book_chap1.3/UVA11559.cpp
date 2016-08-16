#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, b, h, w;
	while (scanf("%d %d %d %d\n", &n, &b, &h, &w) != EOF) {
	  int p[h];
	  int s[h][w];
	  
	  for (int i = 0; i < h; ++i) {
	    cin >> p[i];
	    
	    for (int j = 0; j < w; ++j)
	      cin >> s[i][j];
	  }
	  
	  int cost = 10000000;
	  int minc = 10000000;
	  
	  for (int j = 0; j < w; ++j) {
	    for (int i = 0; i < h; ++i) {
	      if (s[i][j] >= n) {
	        minc = min(minc, p[i]);
	      }
	    }
	    
	    cost = min(cost, n * minc);
	    minc = 10000000;
	  }
	  
	  if (cost >= 10000000 || cost > b) 
	    cout << "stay home\n";
    else cout << cost << "\n"; 
	}
	
	return 0;
}

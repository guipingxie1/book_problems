#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b;
	cin >> n;
	
	while (n--) {
	  cin >> a >> b;
	  
	  if (a == b) {
	    cout << "=\n";
	  } else if (a > b) {
	    cout << ">\n";
	  } else {
	    cout << "<\n";
	  } 
	}
	
	return 0;
}

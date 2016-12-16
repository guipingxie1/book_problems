#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, d, x, y, q, n;
	string s;
	cin >> t;
	
	while (t--) {
		cin >> d;
		map< string, pair<int, int> > m;		
		
		for (int i = 0; i < d; ++i) {
			cin >> s >> x >> y;
			m[s] = make_pair(x, y);
		}
		
		cin >> q;
		for (int i = 0; i < q; ++i) {
			cin >> n;
			int c = 0;
			
			for (auto it = m.begin(); it != m.end() && c != 2; ++it) 
				if (n >= (it -> second).first && n <= (it -> second).second) {
					++c;
					s = it -> first;
				}		
			
			if (c == 0 || c == 2) 
				cout << "UNDETERMINED\n";
			else cout << s << "\n";			
		}		
		
		if (t != 0)
			cout << "\n";	
	}
	
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	char c[3];
	
	while (cin >> n >> m) {
		if (cin.eof())
			break;
			
		for (int i = 0; i < 3; ++i)
			cin >> c[i];
			
		string s[m];
			
		for (int i = 0; i < m; ++i) 
			cin >> s[i];
			
		map<char, int> k;
		k[c[0]] = 0;
		k[c[1]] = 0;
		k[c[2]] = 0;
		
		bool wake[26];
		memset(wake, false, sizeof(wake));
		wake[c[0] - 'A'] = true;
		wake[c[1] - 'A'] = true;
		wake[c[2] - 'A'] = true;
		
		set<char> counts[26];	
		
		int count = 3;
		int next = 3;
		
		do {
			count = next;
			set<int> ss;
			for (int i = 0; i < m; ++i) {
				if (!wake[s[i][0] - 'A'] && wake[s[i][1] - 'A']) {
					counts[s[i][0] - 'A'].insert(s[i][1]);
					
					if (counts[s[i][0] - 'A'].size() >= 3) 
						ss.insert(s[i][0] - 'A');
						
				} else if (wake[s[i][0] - 'A'] && !wake[s[i][1] - 'A']) {
					counts[s[i][1] - 'A'].insert(s[i][0]);
					
					if (counts[s[i][1] - 'A'].size() >= 3) 
						ss.insert(s[i][1] - 'A');
				} 
			}
			
			for (auto it = ss.begin(); it != ss.end(); ++it) {
				set<char> sss = counts[*it];
				wake[*it] = true;
				int ma = 0;
				for (auto itt = sss.begin(); itt != sss.end(); ++itt) 
					ma = max(ma, k[*itt]);
					
				k[(char)(*it + 'A')] = ma + 1;
			}
			
			next += ss.size();
		}
		while (next != count);
		
		if (count == n) {
			int ma = 0;
			for (auto it = k.begin(); it != k.end(); ++it) 
				if (it -> second > ma)
					ma = it -> second;
					
			cout << "WAKE UP IN, " << ma << ", YEARS\n";
		} else {
			cout << "THIS BRAIN NEVER WAKES UP\n";
		}
	}
	
	return 0;
}

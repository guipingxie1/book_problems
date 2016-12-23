#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>
#include <iomanip>

#include <algorithm>
#include <utility>
#include <tuple>
#include <string>
#include <iterator>
#include <regex>
#include <bitset>

#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <list>

//#inclue <bits/stdc++.h>
using namespace std;

double fx(double p, double q, double r, double s, double t, double u, double x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u; 
} 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int p, q, r, s, t, u;
	string line;
	while (getline(cin, line)) {		// decreasing function
		stringstream ss;
		ss << line;
		ss >> p >> q >> r >> s >> t >> u;

		double ans = 0.5;
		double high = 1.0;
		double low = 0.0;
		double small = 0.000001;

		if (fx(p, q, r, s, t, u, low) < 0 || fx(p, q, r, s, t, u, high) > 0) {
			cout << "No solution\n";	
		}
		else {
			while (abs(fx(p, q, r, s, t, u, ans)) > small) {
				if (fx(p, q, r, s, t, u, ans) > 0) {
					low = ans;
					ans = (ans + high) / 2;
				}
				else {
					high = ans;
					ans = (ans + low) / 2;
				}
			}

			cout << fixed << setprecision(4) << ans << "\n";
		}
	}

	return 0;
}

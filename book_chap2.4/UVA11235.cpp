#include <bits/stdc++.h>
using namespace std;

struct node {
	// inclusive
	int start;
	int end;
	
	int most;	// the count
	
	// since it is sorted, we can do this
	int mincount;
	int maxcount;
};

node a[400005];
int arr[100005];
bool done[400005];
map<int, node> m;

void create_seg_tree(int n) {
	a[1].start = 1;
	a[1].end = n;
/*	
	queue<int> q;
	q.push(1);
	
	while (!q.empty()) {
		int idx = q.front();
		q.pop();
		
		int start = a[idx].start;
		int end = a[idx].end;
		
		if (start != end) {
			a[idx << 1].start = start;
			a[idx << 1].end = start + (end - start) >> 1;
			a[1 + idx << 1].start = 1 + start + (end - start) >> 1;
			a[1 + idx << 1].end = end;
			q.push(idx << 1);
			q.push(1 + idx << 1);
		}
	}
*/	
	stack<int> s;
	s.push(1);
	
	while (!s.empty()) {
		int idx = s.top();
		
		int start = a[idx].start;
		int end = a[idx].end;
		
		a[idx << 1].start = start;
		a[idx << 1].end = start + ((end - start) >> 1);
		a[1 + (idx << 1)].start = 1 + start + ((end - start) >> 1);
		a[1 + (idx << 1)].end = end;
		
		if (start == end) {
			a[idx].most = a[idx].mincount = a[idx].maxcount = 1;
			//cerr << start << "\t" << end << "\t--------------------------------\n";
			done[idx] = true;
			s.pop();
		} else {
			if (done[idx << 1] && done[1 + (idx << 1)]) {
				//cerr << start << "\t" << end << "\t--------------------------------\n";
				int ma = 0;
				//cerr << (idx << 1) << " : " << a[idx << 1].end << " = " << arr[a[idx << 1].end] << "\t" << (1 + (idx << 1)) << " : " << a[1 + (idx << 1)].start << " = " << arr[a[1 + (idx << 1)].start] << "\n";
				if (arr[a[idx << 1].end] == arr[a[1 + (idx << 1)].start]) 
					ma = a[idx << 1].maxcount + a[1 + (idx << 1)].mincount;
					
				ma = max(ma, max(a[idx << 1].most, a[1 + (idx << 1)].most));
				
				a[idx].most = ma;
				
				if (arr[a[idx << 1].start] == arr[a[1 + (idx << 1)].end]) {
					a[idx].mincount = a[idx].maxcount = ma;
				} else if (arr[a[idx << 1].start] == arr[a[1 + (idx << 1)].start]) {
					a[idx].mincount = a[idx << 1].mincount + a[1 + (idx << 1)].mincount;
					a[idx].maxcount = a[1 + (idx << 1)].maxcount;
				} else if (arr[a[idx << 1].end] == arr[a[1 + (idx << 1)].end]) {
					a[idx].mincount = a[idx << 1].mincount;
					a[idx].maxcount = a[idx << 1].maxcount + a[1 + (idx << 1)].maxcount;
				} else {
					a[idx].mincount = a[idx << 1].mincount;
					a[idx].maxcount = a[1 + (idx << 1)].maxcount;
				}
				
				done[idx] = true;
				s.pop();
			} else {
				s.push(idx << 1);
				s.push(1 + (idx << 1));
			}
		}
	}
/*
	for (int idx = 1; idx <= 40; ++idx) 
		if (done[idx])
			cerr << idx << " " << a[idx].start << "\t" << a[idx].end << "\t" << a[idx].most << "\t" << a[idx].mincount << "\t" << a[idx].maxcount << "\n";
*/
}

void fill_map(int idx) {
	node temp;
	temp.start = m[idx << 1].start;
	temp.end = m[1 + (idx << 1)].end;
	
	int ma = 0;
	if (arr[m[idx << 1].end] == arr[m[1 + (idx << 1)].start]) 
		ma = m[idx << 1].maxcount + m[1 + (idx << 1)].mincount;
		
	ma = max(ma, max(m[idx << 1].most, m[1 + (idx << 1)].most));
	
	temp.most = ma;
	
	if (arr[m[idx << 1].start] == arr[m[1 + (idx << 1)].end]) {
		temp.mincount = temp.maxcount = ma;
	} else if (arr[a[idx << 1].start] == arr[a[1 + (idx << 1)].start]) {
		temp.mincount = m[idx << 1].mincount + m[1 + (idx << 1)].mincount;
		temp.maxcount = m[1 + (idx << 1)].maxcount;
	} else if (arr[a[idx << 1].end] == arr[a[1 + (idx << 1)].end]) {
		temp.mincount = m[idx << 1].mincount;
		temp.maxcount = m[idx << 1].maxcount + m[1 + (idx << 1)].maxcount;
	} else {
		temp.mincount = m[idx << 1].mincount;
		temp.maxcount = m[1 + (idx << 1)].maxcount;
	}
	
	m[idx] = temp;
}

void solve(int x, int y) {
	stack<int> s;
	stack<int> sx;
	stack<int> sy;
	s.push(1);
	sx.push(x);
	sy.push(y);
	
	m.clear();
	
	while (!s.empty()) {
		int idx = s.top();
		int xx = sx.top();
		int yy = sy.top();
		
		cerr << idx << "\t" << xx << "\t" << yy << "\t" << a[idx].start << "\t" << a[idx].end << "\n";
		
		if (a[idx].start == xx && a[idx].end == yy) {
			m[idx] = a[idx];
			s.pop();
			sx.pop();
			sy.pop();
		} else if (a[idx].start >= xx && a[idx].end <= yy) {
			m[idx] = a[idx];
			s.pop();
			sx.pop();
			sy.pop();
		} else if (a[idx].start == xx) {
			int mid = a[idx].start + ((a[idx].end - a[idx].start) >> 1);
			
			if (yy > mid) {
				if (m.find(1 + (idx << 1)) == m.end()) {
					s.push(1 + (idx << 1));
					sx.push(mid + 1);
					sy.push(yy);
					m[idx << 1] = a[idx << 1];
				} else {
					fill_map(idx);
					s.pop();
					sx.pop();
					sy.pop();
				}
			} else if (yy == mid) {
				m[idx << 1] = a[idx << 1];
				m[idx] = a[idx << 1];
				s.pop();
				sx.pop();
				sy.pop();
			} else {
				if (m.find(idx << 1) == m.end()) {
					s.push(idx << 1);
					sx.push(xx);
					sy.push(yy);
				} else {
					m[idx] = m[idx << 1];
					s.pop();
					sx.pop();
					sy.pop();
				}
			}
		} else if (a[idx].end == yy) {
			int mid = a[idx].start + ((a[idx].end - a[idx].start) >> 1);
			
			if (xx <= mid) {
				if (m.find(idx << 1) == m.end()) {
					s.push(idx << 1);
					sx.push(xx);
					sy.push(mid);
					m[1 + (idx << 1)] = a[1 + (idx << 1)];
				} else {
					fill_map(idx);
					s.pop();
					sx.pop();
					sy.pop();
				}
			} else if (xx == mid + 1) {
				m[1 + (idx << 1)] = a[1 + (idx << 1)];
				m[idx] = a[1 + (idx << 1)];
				s.pop();
				sx.pop();
				sy.pop();
			} else {
				if (m.find(1 + (idx << 1)) == m.end()) {
					s.push(1 + (idx << 1));
					sx.push(xx);
					sy.push(yy);
				} else {
					m[idx] = m[1 + (idx << 1)];
					s.pop();
					sx.pop();
					sy.pop();
				}
			}
		} else {
			if (m.find(idx << 1) != m.end() && m.find(1 + (idx << 1)) != m.end()) {
				fill_map(idx);
				s.pop();
			} else {
				int mid = a[idx].start + ((a[idx].end - a[idx].start) >> 1);
			
				if (yy <= mid) {
					if (m.find(idx << 1) == m.end()) {
						s.push(idx << 1);
						sx.push(xx);
						sy.push(yy);
					}
				} else {
					if (xx > mid) {
						if (m.find(1 + (idx << 1)) == m.end()) {
							s.push(1 + (idx << 1));
							sx.push(xx);
							sy.push(yy);
						} else {
							s.pop();
							sx.pop();
							sy.pop();
						}
					} else if (xx == mid) {
						if (m.find(1 + (idx << 1)) == m.end()) {
							s.push(1 + (idx << 1));
							sx.push(xx);
							sy.push(yy);
						 } else {
						 	s.pop();
						 	sx.pop();
						 	sy.pop();
					 	}
					} else {
						if (m.find(idx << 1) == m.end()) {
							s.push(idx << 1);
							sx.push(xx);
							sy.push(yy);	
						}
							
						if (m.find(1 + (idx << 1)) == m.end()) {
							s.push(1 + (idx << 1));
							sx.push(xx);
							sy.push(yy);	
						}
					}
				}
			}
		}
	}
	
	cout << m[1].most << "\n";
}

int main() {
	int n, m, x, y;
	cin >> n >> m;
	
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];
		
	create_seg_tree(n);
		
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		solve(x, y);
	}	
	
	return 0;
}

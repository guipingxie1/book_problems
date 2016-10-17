#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    priority_queue<int> max_heap;
    priority_queue< int, vector<int>, greater<int> > min_heap;

    while (!cin.eof()) {
        cin >> n;
        
        if (cin.eof())
            break;

        if (max_heap.empty() && min_heap.empty()) {
            max_heap.push(n);
        } else if (min_heap.empty()) {
            if (n >= max_heap.top()) {
                min_heap.push(n);
            } else {
                int val = max_heap.top();
                max_heap.pop();
                max_heap.push(n);
                min_heap.push(val);
            } 
        } else if (max_heap.empty()) {
            if (n <= min_heap.top()) {
                max_heap.push(n);
            } else {
                int val = min_heap.top();
                min_heap.pop();
                min_heap.push(n);
                max_heap.push(val);
            } 
        } else {
            if (n >= max_heap.top()) {
                min_heap.push(n);
            } else {
                int val = max_heap.top();
                max_heap.pop();
                max_heap.push(n);
                min_heap.push(val);
            } 
            
            if (max_heap.size() - min_heap.size() == 2) {
                int val = max_heap.top();
                max_heap.pop();
                min_heap.push(val);
            } else if (min_heap.size() - max_heap.size() == 2) {
                int val = min_heap.top();
                min_heap.pop();
                max_heap.push(val);
            }
        }
        
        if (max_heap.size() == min_heap.size()) {
            cout << (min_heap.top() + max_heap.top()) / 2 << "\n";
        } else if (max_heap.size() > min_heap.size()) {
            cout << max_heap.top() << "\n";
        } else {
            cout << min_heap.top() << "\n";
        }
    }
    
    return 0;
}



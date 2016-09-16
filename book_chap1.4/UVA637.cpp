#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;

    while (x != 0) {
        cout << "Printing order for " << x << " pages:\n";
        int s = x / 4;
        if (x % 4)
            ++s;

        int b = x % 4;
        int n = 1;

        if (b == 0) {
            for (int i = 1; i <= s; ++i) {
                cout << "Sheet " << i << ", front: " << x - n + 1 << ", " << n << "\n";
                ++n;
                cout << "Sheet " << i << ", back : " << n++ << ", " << x - n + 1 << "\n"; 
            }
        } else if (b == 1) {
            if (x == 1) {
                cout << "Sheet 1, front: Blank, 1\n";
            } else {
                cout << "Sheet 1, front: Blank, 1\n";
                cout << "Sheet 1, back : 2, Blank\n";
                cout << "Sheet 2, front: Blank, 3\n";
                cout << "Sheet 2, back : 4, " << x-- << "\n";
                n = 5;
                
                for (int i = 3; i <= s; ++i) {
                    cout << "Sheet " << i << ", front: " << x-- << ", " << n++ << "\n";
                    cout << "Sheet " << i << ", back : " << n++ << ", " << x-- << "\n";
                }
            }
        } else if (b == 2) {
            cout << "Sheet 1, front: Blank, 1\n";
            cout << "Sheet 1, back : 2, Blank\n";
            n = 3;    
                
            for (int i = 2; i <= s; ++i) {
                cout << "Sheet " << i << ", front: " << x-- << ", " << n++ << "\n";
                cout << "Sheet " << i << ", back : " << n++ << ", " << x-- << "\n";
            }
        } else {
            cout << "Sheet 1, front: Blank, 1\n";
            cout << "Sheet 1, back : 2, " << x-- << "\n";
            n = 3;    
                
            for (int i = 2; i <= s; ++i) {
                cout << "Sheet " << i << ", front: " << x-- << ", " << n++ << "\n";
                cout << "Sheet " << i << ", back : " << n++ << ", " << x-- << "\n";
            }
        }
        
        cin >> x;
    }

    return 0;
}

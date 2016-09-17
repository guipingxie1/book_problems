#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (!cin.eof()) {
        int a[n];
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        bool b[n];
        for (int i = 0; i < n; ++i)
            b[i] = false;

        bool flag = false;
        for (int i = 1; i < n; ++i) {
            if (abs(a[i] - a[i - 1]) < n && a[i] != a[i - 1]) {
                if (b[abs(a[i] - a[i - 1])]) {
                    cout << "Not jolly\n";
                    flag = true;
                    break;
                } else {
                    b[abs(a[i] - a[i - 1])] = true;
                }
            } else {
                flag = true;
                cout << "Not jolly\n";
                break;
            }
        }

        if (!flag)
            cout << "Jolly\n";

        cin >> n;
    }

    return 0;
}

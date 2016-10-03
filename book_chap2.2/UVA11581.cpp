#include <bits/stdc++.h>
using namespace std;

char b[3][3];

bool check_b(char a[3][3]) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) 
            if (a[i][j] != b[i][j])
                return false;

    return true;
}

int main() {
    int t;
    int n;
    cin >> t;

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            b[i][j] = '0';

    while (t--) {
        char a[3][3];

        for (int i = 0; i < 3; ++i) {
            cin >> n;
            
            for (int j = 0; j < 3; ++j) {
                a[i][j] = (n % 10) + '0';
                n /= 10;
            }
        }

        int count = -1;

        while (!check_b(a)) {
            char co[3][3];

            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int val = 0;
                    if (i - 1 >= 0)
                        val += a[i - 1][j] - '0';

                    if (i < 2)
                        val += a[i + 1][j] - '0';

                    if (j - 1 >= 0)
                        val += a[i][j - 1] - '0';

                    if (j < 2) 
                        val += a[i][j + 1] - '0';

                    if (val & 1)
                        co[i][j] = '1';
                    else co[i][j] = '0';
                }
            }

            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    a[i][j] = co[i][j];

            ++count;
        }

        cout << count << "\n";

    }

    return 0;
}

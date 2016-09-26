#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m, n || m) {
        char a[n][n];
        char b[m][m];

        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < n; ++j)
                cin >> a[i][j];

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < m; ++j)
                cin >> b[i][j];

        int c[4];
        memset(c, 0, 4 * sizeof(int));

        for (int i = 0; i <= n - m; ++i)
            for (int j = 0; j <= n - m; ++j) {
                int co[4];
                memset(co, 0, 4 * sizeof(int));

                for (int x = 0; x < m; ++x)
                    for (int y = 0; y < m; ++y) {
                        if (a[i + x][j + y] == b[x][y])
                            ++co[0];

                        if (a[i + x][j + y] == b[y][m - 1 - x])
                            ++co[3];

                        if (a[i + x][j + y] == b[m - 1 - x][m - 1 - y])
                            ++co[2];

                        if (a[i + x][j + y] == b[m - 1 - y][x])
                            ++co[1];
                    }            

                for (int k = 0; k < 4; ++k)
                    if (co[k] == m * m)
                        c[k]++;
            }

        for (int i = 0; i < 3; ++i)
            cout << c[i] << " ";
        cout << c[3] << "\n";
    }

    return 0;
}

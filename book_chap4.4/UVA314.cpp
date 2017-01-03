#include <bits/stdc++.h>
using namespace std;

bool visited[55][55][4];
bool a[55][55];
map<char, int> mm;

struct node {
    int x;
    int y;
    int dist;
    int dir;
    int par;
    
    node() : x(0), y(0), dist(0), dir(0), par(0) {}; 
    node(int x, int y, int dist, int dir, int par) : x(x), y(y), dist(dist), dir(dir), par(par) {};
};

bool valid(int x, int y, int dir, int n, int m) {
    if ((x && y) && (x < n && y < m)) 
        if (!visited[x][y][dir])
            return (!a[x - 1][y - 1] && !a[x - 1][y] && !a[x][y - 1] && !a[x][y]);
    return false;
}

void bfs(int n, int m) {
    int srcx, srcy, destx, desty;
    string dir;
    
    cin >> srcx >> srcy >> destx >> desty >> dir;
    
    node src(srcx, srcy, 0, mm[dir[0]], -1);
    visited[srcx][srcy][mm[dir[0]]] = true;
    queue<node> q;
    q.push(src);
    
    vector<node> v;
    v.push_back(src);
    
    while (!q.empty()) {
        node t = q.front();
        q.pop();
        /*
        if (t.x == 2 && t.y == 20) {
            cout << t.dist << "\n";
            
            node temp = t;
            int idx = temp.par;
            while (temp.par != -1) {
                cout << temp.x + 1 << " " << temp.y + 1 << " " << temp.dir << "\n";
                temp = v[temp.par];
            }
            
            cout << temp.x + 1 << " " << temp.y + 1 << " " << temp.dir << "\n";
            
            cout << "\n";
        }
        
        if (t.x == 2 && t.y == 17) {
            cout << t.dist << "\n";
            
            node temp = t;
            int idx = temp.par;
            while (temp.par != -1) {
                cout << temp.x + 1 << " " << temp.y + 1 << " " << temp.dir << "\n";
                temp = v[temp.par];
            }
            
            cout << temp.x + 1 << " " << temp.y + 1 << " " << temp.dir << "\n";
            
            cout << "\n";
        }
        */
        if (t.x == destx && t.y == desty) {
            cout << t.dist << "\n";
            /*
            node temp = t;
            int idx = temp.par;
            while (temp.par != -1) {
                cout << temp.x + 1 << " " << temp.y + 1 << " " << temp.dir << "\n";
                temp = v[temp.par];
            }
            
            cout << temp.x + 1 << " " << temp.y + 1 << " " << temp.dir << "\n";
            
            cout << "\n";
            
            for (int i = 0; i < v.size(); ++i) {
                cout << v[i].x + 1 << " " << v[i].y + 1 << " " << v[i].dir << " " << v[i].dist << "\n";
            }
            */
            return;
        }
        
        // get index
        int idx = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i].x == t.x && v[i].y == t.y && v[i].dir == t.dir) {
                idx = i;
                break;
            }
        }
        
        int dist = t.dist;
        
        if (t.dir == 1) {
            if (!visited[t.x][t.y][2]) {
                node west(t.x, t.y, dist + 1, 2, idx);
                q.push(west);
                v.push_back(west);
                visited[t.x][t.y][2] = true;
            }
            
            if (!visited[t.x][t.y][3]) {
                node east(t.x, t.y, dist + 1, 3, idx);
                q.push(east);
                v.push_back(east);
                visited[t.x][t.y][3] = true;
            }
            
            if (valid(t.x + 1, t.y, 1, n, m)) {
                if (valid(t.x + 2, t.y, 1, n, m)) {
                    if (valid(t.x + 3, t.y, 1, n, m)) {
                        node tttt(t.x + 3, t.y, dist + 1, 1, idx);
                        q.push(tttt);
                        v.push_back(tttt);
                        visited[t.x + 3][t.y][1] = true;
                    }
                    
                    node ttt(t.x + 2, t.y, dist + 1, 1, idx);
                    q.push(ttt);
                    v.push_back(ttt);
                    visited[t.x + 2][t.y][1] = true;
                }
                
                node tt(t.x + 1, t.y, dist + 1, 1, idx);
                q.push(tt);
                v.push_back(tt);
                visited[t.x + 1][t.y][1] = true;
                
            } 
        } else if (t.dir == 0) {
            if (!visited[t.x][t.y][2]) {
                node west(t.x, t.y, dist + 1, 2, idx);
                q.push(west);
                v.push_back(west);
                visited[t.x][t.y][2] = true;
            }
            
            if (!visited[t.x][t.y][3]) {
                node east(t.x, t.y, dist + 1, 3, idx);
                q.push(east);
                v.push_back(east);
                visited[t.x][t.y][3] = true;
            }
            
            if (valid(t.x - 1, t.y, 0, n, m)) {
                if (valid(t.x - 2, t.y, 0, n, m)) {
                    if (valid(t.x - 3, t.y, 0, n, m)) {
                        node tttt(t.x - 3, t.y, dist + 1, 0, idx);
                        q.push(tttt);
                        v.push_back(tttt);
                        visited[t.x - 3][t.y][0] = true;
                    }
                    
                    node ttt(t.x - 2, t.y, dist + 1, 0, idx);
                    q.push(ttt);
                    v.push_back(ttt);
                    visited[t.x - 2][t.y][0] = true;
                }
                
                node tt(t.x - 1, t.y, dist + 1, 0, idx);
                q.push(tt);
                v.push_back(tt);
                visited[t.x - 1][t.y][0] = true;
                
            } 
        } else if (t.dir == 3) {
            if (!visited[t.x][t.y][0]) {
                node north(t.x, t.y, dist + 1, 0, idx);
                q.push(north);
                v.push_back(north);
                visited[t.x][t.y][0] = true;
            }
            
            if (!visited[t.x][t.y][1]) {
                node south(t.x, t.y, dist + 1, 1, idx);
                q.push(south);
                v.push_back(south);
                visited[t.x][t.y][1] = true;
            }
            
            if (valid(t.x, t.y + 1, 3, n, m)) {
                if (valid(t.x, t.y + 2, 3, n, m)) {
                    if (valid(t.x, t.y + 3, 3, n, m)) {
                        node tttt(t.x, t.y + 3, dist + 1, 3, idx);
                        q.push(tttt);
                        v.push_back(tttt);
                        visited[t.x][t.y + 3][3] = true;
                    }
                    
                    node ttt(t.x, t.y + 2, dist + 1, 3, idx);
                    q.push(ttt);
                    v.push_back(ttt);
                    visited[t.x][t.y + 2][3] = true;
                }
                
                node tt(t.x, t.y + 1, dist + 1, 3, idx);
                q.push(tt);
                v.push_back(tt);
                visited[t.x][t.y + 1][3] = true;
            } 
        } else {
            if (!visited[t.x][t.y][0]) {
                node north(t.x, t.y, dist + 1, 0, idx);
                q.push(north);
                v.push_back(north);
                visited[t.x][t.y][0] = true;
            }
            
            if (!visited[t.x][t.y][1]) {
                node south(t.x, t.y, dist + 1, 1, idx);
                q.push(south);
                v.push_back(south);
                visited[t.x][t.y][1] = true;
            }
        
            if (valid(t.x, t.y - 1, 2, n, m)) {
                if (valid(t.x, t.y - 2, 2, n, m)) {
                    if (valid(t.x, t.y - 3, 2, n, m)) {
                        node tttt(t.x, t.y - 3, dist + 1, 2, idx);
                        q.push(tttt);
                        v.push_back(tttt);
                        visited[t.x][t.y - 3][2] = true;
                    }
                    
                    node ttt(t.x, t.y - 2, dist + 1, 2, idx);
                    q.push(ttt);
                    v.push_back(ttt);
                    visited[t.x][t.y - 2][2] = true;
                }
                
                node tt(t.x, t.y - 1, dist + 1, 2, idx);
                q.push(tt);
                v.push_back(tt);
                visited[t.x][t.y - 1][2] = true;
            } 
        }
    }
    
    cout << "-1\n";
}

int main() {
    int n, m;
    mm['n'] = 0;
    mm['s'] = 1;
    mm['w'] = 2;
    mm['e'] = 3;
    
    while (cin >> n >> m, n || m) {
        memset(visited, 0, sizeof(visited));
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];
                
        bfs(n, m);
    }
    
    return 0;
}

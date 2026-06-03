#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1001][1001];
bool visited[1001][1001];
char parent[1001][1001];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
char dir[] = {'R', 'L', 'D', 'U'};


void bfs(int r, int c) {
    queue<pair<int,int>> q;
    q.push({r, c});
    visited[r][c] = true;
    parent[r][c] = 'A';
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m
                && !visited[nx][ny] && grid[nx][ny] != '#') {
                visited[nx][ny] = true;
                parent[nx][ny] = dir[d];
                if(grid[nx][ny] == 'B') {
                    return;
                }
                
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    int sr,sc;
    int er,ec;
    for (int i = 0; i < n; i++){
        cin >> grid[i];
        for (int j = 0; j < m; j++)
            if(grid[i][j] == 'A') {
                sr = i;
                sc = j;
            }
            else if(grid[i][j] == 'B') {
                er = i;
                ec = j;
            }
    }
    bfs(sr, sc);


    if(visited[er][ec]) {
        cout << "YES" << endl;
        string path = "";
        int x = er, y = ec;
        while(x!=sr||y!=sc){
            path += parent[x][y];
            if(parent[x][y] == 'R') y--;
            else if(parent[x][y] == 'L') y++;
            else if(parent[x][y] == 'D') x--;
            else if(parent[x][y] == 'U') x++;
        }
        reverse(path.begin(), path.end());

        
        cout << path.size() << endl;
        cout << path << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
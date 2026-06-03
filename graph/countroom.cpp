#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1001][1001];
bool visited[1001][1001];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void bfs(int r, int c) {
    queue<pair<int,int>> q;
    q.push({r, c});
    visited[r][c] = true;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m
                && !visited[nx][ny] && grid[nx][ny] == '.') {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> grid[i];
    int rooms = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!visited[i][j] && grid[i][j] == '.') {
                bfs(i, j);
                rooms++;
            }
    cout << rooms << "\n";
}
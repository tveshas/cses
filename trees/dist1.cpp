#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
int dist1[200005], dist2[200005];

int bfs(int start, int dist[]) {
    fill(dist, dist + 200005, -1);
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    int farthest = start;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
                if (dist[v] > dist[farthest])
                    farthest = v;
            }
        }
    }
    return farthest;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int tmp[200005];
    int u = bfs(1, tmp);
    int v = bfs(u, dist1);
    bfs(v, dist2);

    for (int i = 1; i <= n; i++) {
        cout << max(dist1[i], dist2[i]);
        if (i < n) cout << " ";
    }
    cout << "\n";
}
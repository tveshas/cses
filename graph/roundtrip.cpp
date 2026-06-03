#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100001];
int par[100001];
bool vis[100001];
int cycle_start = -1, cycle_end = -1;

void dfs(int u, int p) {
    if (cycle_start != -1) return;
    vis[u] = true;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (vis[v]) {
            cycle_start = v;
            cycle_end = u;
            return;
        }
        par[v] = u;
        dfs(v, u);
        if (cycle_start != -1) return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            par[i] = i;
            dfs(i, -1);
        }
        if (cycle_start != -1) break;
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> cycle;
    cycle.push_back(cycle_start);
    int cur = cycle_end;
    while (cur != cycle_start) {
        cycle.push_back(cur);
        cur = par[cur];
    }
    cycle.push_back(cycle_start);

    cout << cycle.size() << "\n";
    for (int x : cycle) cout << x << " ";
    cout << "\n";
}
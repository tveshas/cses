#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100001];
int par[100001];
bool vis[100001];
bool inStack[100001];
int cycle_start = -1, cycle_end = -1;

void dfs(int u) {
    if (cycle_start != -1) return;
    vis[u] = true;
    inStack[u] = true;
    for (int v : adj[u]) {
        if (inStack[v]) {
            cycle_start = v;
            cycle_end = u;
            return;
        }
        if (!vis[v]) {
            par[v] = u;
            dfs(v);
        }
        if (cycle_start != -1) return;
    }
    inStack[u] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            par[i] = i;
            dfs(i);
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
    reverse(cycle.begin(), cycle.end());  // fix order

    cout << cycle.size() << "\n";
    for (int x : cycle) cout << x << " ";
    cout << "\n";
}
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[200005];
int sz[200005];

void dfs(int u) {
    sz[u] = 1;
    for (int v : adj[u]) {
        dfs(v);
        sz[u] += sz[v];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 2; i <= n; i++) {
        int b;
        cin >> b;
        adj[b].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << sz[i] - 1;
        if (i < n) cout << " ";
    }
    cout << "\n";
}
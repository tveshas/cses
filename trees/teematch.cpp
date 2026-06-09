#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
vector<int> adj[200005];
bool matched[200005];

void dfs(int u, int par) {
    for (int v : adj[u]) {
        if (v == par) continue;
        dfs(v, u);
        if (!matched[v] && !matched[u]) {
            matched[u] = matched[v] = true;
            ans++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);
    cout << ans << "\n";
}
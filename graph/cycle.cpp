#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct Edge {
    int u, v;
    ll weight;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    vector<ll> dist(n + 1, 0);
    vector<int> parent(n + 1, 0);
    int last_node = -1;

    // Relax all edges N times
    for (int i = 1; i <= n; i++) {
        last_node = -1;
        for (const auto& edge : edges) {
            if (dist[edge.u] + edge.weight < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.weight;
                parent[edge.v] = edge.u;
                last_node = edge.v;
            }
        }
    }

    // If last_node is -1 after N iterations, no negative cycle exists
    if (last_node == -1) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    // To ensure we get the correct cycle, we trace back N times 
    // to guarantee we are inside the negative cycle.
    for (int i = 1; i <= n; i++) {
        last_node = parent[last_node];
    }

    // Reconstruct the cycle
    vector<int> cycle;
    int curr = last_node;
    while (true) {
        cycle.push_back(curr);
        curr = parent[curr];
        if (curr == last_node) break;
    }

    cycle.push_back(curr);
    reverse(cycle.begin(), cycle.end());

    // Print the sequence
    for (int node : cycle) {
        cout << node << " ";
    }
    cout << "\n";

    return 0;
}

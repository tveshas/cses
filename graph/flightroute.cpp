#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
vector<pair<int,int>> adj[MAXN];
vector<pair<int,int>> radj[MAXN];
vector<long long> dist_start(MAXN, LLONG_MAX);
vector<long long> dist_end(MAXN, LLONG_MAX);
int n, m;

void dijkstra(int start, vector<pair<int,int>> g[], vector<long long>& dist){
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();
        if(d > dist[u]) continue;
        for(auto [v, w]: g[u]){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        radj[b].push_back({a, c});
    }

    dijkstra(1, adj, dist_start);
    dijkstra(n, radj, dist_end);

    long long ans = dist_start[n];  // no coupon used
    for(int u = 1; u <= n; u++){
        for(auto [v, w]: adj[u]){
            if(dist_start[u] == LLONG_MAX || dist_end[v] == LLONG_MAX) continue;
            ans = min(ans, dist_start[u] + w/2 + dist_end[v]);
        }
    }

    cout << ans << "\n";
}
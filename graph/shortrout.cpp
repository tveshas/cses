#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
vector<vector<pair<int,int>>> adj(MAXN);
vector<long long> dist(MAXN, LLONG_MAX);

void dijkstra(int start){
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();
        if(d > dist[u]) continue;
        for(auto [v, w]: adj[u]){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    dijkstra(1);
    for(int i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }
}
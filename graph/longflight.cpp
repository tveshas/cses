#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
int n, m;
vector<int> adj[MAXN];
int indegree[MAXN];
vector<int> dp(MAXN, -1);   // -1 = unreachable
vector<int> par(MAXN, -1);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    // Kahn's topological sort
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(indegree[i] == 0) q.push(i);

    dp[1] = 1;  // start city counts as 1

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj[u]){
            if(dp[u] != -1 && dp[u] + 1 > dp[v]){
                dp[v] = dp[u] + 1;
                par[v] = u;
            }
            indegree[v]--;
            if(indegree[v] == 0) q.push(v);
        }
    }

    if(dp[n] == -1){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // reconstruct path
    vector<int> path;
    int cur = n;
    while(cur != -1){
        path.push_back(cur);
        cur = par[cur];
    }
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for(int x : path) cout << x << " ";
    cout << "\n";
}
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int LOG = 18;

int up[MAXN][LOG];
int depth[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int p, int d){
    up[v][0] = p;
    depth[v] = d;
    for(int j = 1; j < LOG; j++)
        up[v][j] = up[up[v][j-1]][j-1];
    for(int u : adj[v])
        if(u != p) dfs(u, v, d+1);
}

int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    for(int j = 0; j < LOG; j++)
        if((diff >> j) & 1)
            a = up[a][j];
    if(a == b) return a;
    for(int j = LOG-1; j >= 0; j--)
        if(up[a][j] != up[b][j]){
            a = up[a][j];
            b = up[b][j];
        }
    return up[a][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;   // edges given as pairs now
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0, 0);

    while(q--){
        int a, b;
        cin >> a >> b;
        int l = lca(a, b);
        cout << depth[a] + depth[b] - 2*depth[l] << "\n";
    }
}
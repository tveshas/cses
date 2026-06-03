#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100001;
vector<int> parent(MAXN);
bool visited[MAXN];
int n, m;
vector<vector<int>> adj(MAXN);
void bfs(int start, int n){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(auto nx : adj[x]){
            if(nx == n){
                parent[nx] = x;
                visited[nx] = true;  
                return;
            }
            if(!visited[nx]){
                visited[nx] = true;
                parent[nx] = x;
                q.push(nx);
            }
        }
    }

}

int main(){
    
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1,n);
    if(!visited[n]){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<int> path;

    int x=n;
    while(x!=1){
        path.push_back(x);

        x=parent[x];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for (int v : path) cout << v << " ";

}   
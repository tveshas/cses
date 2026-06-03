#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
vector<int> adj[MAXN];
bool visited[MAXN];
bool is_possible = true;
vector<int> team(MAXN);
void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    team[start] = 1;
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(auto nx : adj[x]){
            if(!visited[nx]){
                visited[nx] = true;
                team[nx] = 3-team[x];
                q.push(nx);
            }
            else if(team[nx] == team[x]){
                is_possible = false;
                return;
            }
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            bfs(i);
            if(!is_possible){
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << team[i] << " ";
    }
}
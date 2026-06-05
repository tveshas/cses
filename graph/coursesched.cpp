#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
int n, m;

vector<int> adj[MAXN];
int indegree[MAXN];
vector<int> topo;
void calculate_indegree(){
    for(int i = 1; i <= n; i++){
        for(auto j : adj[i]){
            indegree[j]++;
        }
    }
}

void top(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int x=q.front();  q.pop();
        topo.push_back(x);
        for(auto j : adj[x]){
            indegree[j]--;
            if(indegree[j] == 0){
                q.push(j);
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b); // a before b a->b
    }
    calculate_indegree();
    top();
    if((int)topo.size() < n){
        cout << "IMPOSSIBLE\n";
    } else {
        for(auto i : topo) cout << i << " ";
    }
}
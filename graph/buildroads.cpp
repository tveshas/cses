#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
vector<int> adj[MAXN];
bool visited[MAXN];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int nx : adj[x]) {
            if (!visited[nx]) {
                visited[nx] = true;
                q.push(nx);
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> reps;  // one representative node per component
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bfs(i);
            reps.push_back(i);
        }
    }

    cout << reps.size() - 1 << "\n";
    for (int i = 0; i + 1 < reps.size(); i++)
        cout << reps[i] << " " << reps[i+1] << "\n";
}
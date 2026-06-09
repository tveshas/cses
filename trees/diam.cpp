#include <bits/stdc++.h>
using namespace std;
vector<int> adj[200005];
vector<int> height(200005, 0);
int maxDiameter = 0;

int diameterRecur(int u, int par) {
    for (int v : adj[u]) {
        if (v == par) continue;
        height[v] = diameterRecur(v, u);
    }

    int best1 = 0, best2 = 0;
    for (int v : adj[u]) {
        if (v == par) continue;
        if (height[v] > best1) { best2 = best1; best1 = height[v]; }
        else if (height[v] > best2) { best2 = height[v]; }
    }

    maxDiameter = max(maxDiameter, best1 + best2);
    return 1 + best1;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    diameterRecur(1, -1);
    cout << maxDiameter << endl;
}
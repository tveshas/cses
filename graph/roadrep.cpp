#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
int par[MAXN], rnk[MAXN];

int find(int x){
    if(par[x] != x) par[x] = find(par[x]);
    return par[x];
}

bool unite(int a, int b){
    a = find(a); b = find(b);
    if(a == b) return false;
    if(rnk[a] < rnk[b]) swap(a, b);
    par[b] = a;
    if(rnk[a] == rnk[b]) rnk[a]++;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<tuple<int,int,int>> edges(m);
    for(auto& [c, a, b] : edges) cin >> a >> b >> c;

    sort(edges.begin(), edges.end()); // sort by cost (first element)

    for(int i = 1; i <= n; i++) par[i] = i;

    long long total = 0;
    int count = 0;
    for(auto [c, a, b] : edges){
        if(unite(a, b)){
            total += c;
            count++;
        }
    }

    if(count < n - 1) cout << "IMPOSSIBLE\n";
    else cout << total << "\n";
}
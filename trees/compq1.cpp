#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int LOG = 18;

int up[MAXN][LOG];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    up[1][0] = 0; 
    for(int i = 2; i <= n; i++){
        cin >> up[i][0];
    }

    for(int j = 1; j < LOG; j++){
        for(int v = 1; v <= n; v++){
            up[v][j] = up[up[v][j-1]][j-1];
        }
    }

    while(q--){
        int x, k;
        cin >> x >> k;

        for(int j = 0; j < LOG; j++){
            if((k >> j) & 1){
                x = up[x][j];
            }
        }

        if(x == 0) cout << -1 << "\n";
        else cout << x << "\n";
    }
}
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001;
int dp[MAXN];

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        dp[i] = INT_MAX;
        for (int c : coins) {
            if (i - c >= 0 && dp[i - c] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }

    if (dp[x] == INT_MAX) cout << -1 << endl;
    else cout << dp[x] << endl;

    return 0;
}
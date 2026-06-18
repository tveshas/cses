#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1000001;
int dp[MAXN];

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    sort(coins.begin(), coins.end());

    dp[0] = 1;
    for (int c : coins) {
        for (int i = c; i <= x; i++) {
            dp[i] = (dp[i] + dp[i - c]) % MOD;
        }
    }

    cout << dp[x] << endl;
    return 0;
}
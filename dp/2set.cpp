#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    int total = n * (n + 1) / 2;
    if (total % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    int target = total / 2;
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int s = target; s >= i; s--) {
            dp[s] = (dp[s] + dp[s - i]) % MOD;
        }
    }

    cout << (1LL * dp[target] * 500000004) % MOD << endl;
    return 0;
}   
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001;
int dp[MAXN];

int main() {
    int n;
    cin >> n;

    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = INT_MAX;
        for (int j = i; j > 0; j /= 10) {
            int d = j % 10;
            if (d == 0) continue;
            dp[i] = min(dp[i], dp[i - d] + 1);
        }
    }

    cout << dp[n] << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> x(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        sum += x[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(n));

    for (int i = 0; i < n; i++) {
        dp[i][i] = x[i];
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            dp[i][j] = max(x[i] - dp[i + 1][j], x[j] - dp[i][j - 1]);
        }
    }

    cout << (sum + dp[0][n - 1]) / 2 << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<array<int, 3>> projects(n);
    for (int i = 0; i < n; i++) {
        cin >> projects[i][0] >> projects[i][1] >> projects[i][2];
    }

    sort(projects.begin(), projects.end(), [](const auto& a, const auto& b) {
        return a[1] < b[1];  // sort by end day
    });

    vector<long long> dp(n);
    dp[0] = projects[0][2];

    for (int i = 1; i < n; i++) {
        long long take = projects[i][2];

        int lo = 0, hi = i - 1, k = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (projects[mid][1] < projects[i][0]) {
                k = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        if (k != -1) take += dp[k];
        dp[i] = max(dp[i - 1], take);
    }

    cout << dp[n - 1] << endl;
    return 0;
}
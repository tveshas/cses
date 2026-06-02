#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;

    long long sum = 0, ans = 0;
    map<long long, long long> cnt;
    cnt[0] = 1;

    for (int i = 0; i < n; i++) {
        long long v;
        cin >> v;
        sum += v;

        auto it = cnt.find(sum - x);
        if (it != cnt.end())
            ans += it->second;

        cnt[sum]++;
    }

    cout << ans << "\n";
    return 0;
}
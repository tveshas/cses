#include <bits/stdc++.h>
using namespace std;

bool can_split(const vector<long long>& a, int k, long long mid) {
    int parts = 1;
    long long cur = 0;
    for (long long x : a) {
        if (x > mid)
            return false;
        if (cur + x > mid) {
            parts++;
            cur = x;
        } else {
            cur += x;
        }
    }
    return parts <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    long long lo = 0, hi = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        lo = max(lo, a[i]);
        hi += a[i];
    }

    while (lo < hi) {
        long long mid = (lo + hi) / 2;
        if (can_split(a, k, mid))
            hi = mid;
        else
            lo = mid + 1;
    }

    cout << lo << "\n";
    return 0;
}
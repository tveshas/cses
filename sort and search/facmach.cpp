#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, t;
    cin >> n >> t;
    vector<long long> k(n);
    long long minK = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        minK = min(minK, k[i]);
    }

    long long lo = 1, hi = minK * t;
    while (lo < hi) {
        long long mid = (lo + hi) / 2;
        long long products = 0;
        for (int i = 0; i < n; i++) {
            products += mid / k[i];
            if (products >= t) break; // avoid overflow
        }
        if (products >= t) hi = mid;
        else lo = mid + 1;
    }

    cout << lo << "\n";
}
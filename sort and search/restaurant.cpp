#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, +1});
        events.push_back({b, -1});
    }

    sort(events.begin(), events.end());

    int cur = 0, mx = 0;
    for (auto [t, d] : events) {
        cur += d;
        mx = max(mx, cur);
    }

    cout << mx << '\n';
    return 0;
}
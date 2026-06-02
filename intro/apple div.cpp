#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> p;
long long total, half, best;

void dfs(int i, long long cur) {
    if (i == n) {
        if (cur <= half)
            best = max(best, cur);
        return;
    }

    dfs(i + 1, cur);              // skip apple i
    dfs(i + 1, cur + p[i]);       // take apple i
}

int main() {
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        total += p[i];
    }

    half = total / 2;
    dfs(0, 0);

    cout << total - 2 * best << "\n";
    return 0;
}
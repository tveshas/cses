#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    map<int, int> pos;
    for (int i = 0; i < n; i++) {
        int need = x - a[i];
        if (pos.count(need)) {
            cout << pos[need] + 1 << ' ' << i + 1 << '\n';
            return 0;
        }
        pos[a[i]] = i;
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
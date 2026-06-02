#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    unordered_set<int> s;
    s.reserve(n);
    int l = 0, best = 0;
    for (int r = 0; r < n; r++) {
        while (s.count(a[r])) {
            s.erase(a[l]);
            l++;
        }
        s.insert(a[r]);
        best = max(best, r - l + 1);
    }
    
    cout << best << endl;
    return 0;
}
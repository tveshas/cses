#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> price(n);
    for (int i = 0; i < n; i++) cin >> price[i];
    vector<int> maxprice(m);
    for (int i = 0; i < m; i++) cin >> maxprice[i];

    sort(price.begin(), price.end());

    map<int, int> tickets;
    for (int p : price) tickets[p]++;

    for (int i = 0; i < m; i++) {
        int t = maxprice[i];
        auto it = tickets.upper_bound(t);
        if (it == tickets.begin()) {
            cout << -1 << '\n';
        } else {
            --it;
            cout << it->first << '\n';
            if (--it->second == 0) tickets.erase(it);
        }
    }

    return 0;
}
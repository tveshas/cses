#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long row, col;
        cin >> row >> col;

        long long z = max(row, col);
        if (z == 1) {
            cout << 1 << "\n";
            continue;
        }

        long long prev = (z - 1) * (z - 1);
        long long ans;

        if (z % 2 == 0) {
            // even: down column z, then left on row z
            if (col == z)
                ans = prev + row;
            else
                ans = prev + z + (z - col);
        } else {
            // odd: right on row z, then up column z
            if (row == z)
                ans = prev + col;
            else
                ans = prev + z + (z - row);
        }

        cout << ans << "\n";
    }
    return 0;
}
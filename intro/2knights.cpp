#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int k = 1; k <= n; k++) {
        long long sq = 1LL * k * k;

        // total = k×k board pe 2 knights choose karne ke tareeke
        // C(k², 2) = k²(k² - 1) / 2
        long long total = sq * (sq - 1) / 2;

        // bad = woh pairs jahan dono knights ek dusre ko attack karte hain
        // L-shape (2,1) count: har orientation mein (k-1)(k-2) pairs
        // 4 orientations → bad = 4(k-1)(k-2)
        //
        // bad sequence (k=2,3,4,5,6...): 0, 8, 24, 48, 80...
        // yeh second order AP hai (quadratic):
        //   pehle differences: 8, 16, 24, 32... (AP, diff = 8)
        //   doosre differences: 8, 8, 8... (constant)
        // expand: 4(k-1)(k-2) = 4k² - 12k + 8
        //
        // ya m = k-1 rakho to: bad = 4m(m-1) = 4m² - 4m
        long long bad = 4LL * (k - 1) * (k - 2);

        // answer = safe pairs = total - bad
        cout << total - bad << "\n";
    }
    return 0;
}
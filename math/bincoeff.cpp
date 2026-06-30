#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXA = 1e6;

long long power(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    vector<long long> fact(MAXA + 1), inv(MAXA + 1);
    fact[0] = 1;
    for (int i = 1; i <= MAXA; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    inv[MAXA] = power(fact[MAXA], MOD - 2);
    for (int i = MAXA; i >= 1; i--) {
        inv[i - 1] = inv[i] * i % MOD;
    }

    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;

        if (b > a) {
            cout << 0 << "\n";
            continue;
        }

        long long ans = fact[a] * inv[b] % MOD * inv[a - b] % MOD;
        cout << ans << "\n";
    }

    return 0;
}
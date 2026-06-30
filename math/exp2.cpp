#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long power(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        long long a, b, c;
        cin >> a >> b >> c;

        long long phi = MOD - 1;
        long long exp = power(b % phi, c, phi);  // b^c mod (MOD-1)
        if (exp == 0) exp = phi;

        a %= MOD;
        if (a == 0) {
            if (b == 0 && c > 0) cout << 1 << "\n";       // 0^0
            else if (b == 0 && c == 0) cout << 0 << "\n";   // 0^1
            else cout << 0 << "\n";
        } else {
            cout << power(a, exp, MOD) << "\n";
        }
    }
    return 0;
}
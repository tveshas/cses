#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long total = n * (n + 1) / 2;
    if (total % 2 == 1) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    long long target = total / 2;  // same as n(n+1)/4

    vector<long long> set1, set2;
    vector<bool> used(n + 1, false);
    long long sum = 0;

    // greedy from top: n se 1 tak, jab tak sum <= target
    for (long long i = n; i >= 1; i--) {
        if (sum + i <= target) {
            set1.push_back(i);
            sum += i;
            used[i] = true;
        }
    }

    for (long long i = 1; i <= n; i++)
        if (!used[i]) set2.push_back(i);

    cout << set1.size() << "\n";
    for (long long x : set1) cout << x << " ";
    cout << "\n";
    cout << set2.size() << "\n";
    for (long long x : set2) cout << x << " ";
    cout << "\n";

    return 0;
}
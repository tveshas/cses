#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    const int MAXV = 1e6;
    vector<int> freq(MAXV + 1, 0);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    for (int i = MAXV; i >= 1; i--) {
        int cnt = 0;
        for (int j = i; j <= MAXV; j += i) {
            cnt += freq[j];
        }
        if (cnt >= 2) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}
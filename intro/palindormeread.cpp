#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int freq[26] = {};
    for (char c : s)
        freq[c - 'A']++;

    int odd = 0;
    char mid = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2) {
            odd++;
            mid = 'A' + i;
        }
    }

    if (odd > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    string left;
    left.reserve(s.size() / 2 + 1);

    for (int i = 0; i < 26; i++)
        left.append(freq[i] / 2, char('A' + i));

    string right = left;
    reverse(right.begin(), right.end());

    string middle = (odd == 1 ? string(1, mid) : "");
    cout << left << middle << right << "\n";

    return 0;
}
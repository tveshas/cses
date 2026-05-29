#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> ans;
string cur;
map<char, int> freq;

void permute() {
    if (cur.size() == s.size()) {
        ans.push_back(cur);
        return;
    }
    for (auto& [ch, cnt] : freq) {
        if (cnt == 0) continue;

        cnt--;
        cur.push_back(ch);
        permute();
        cur.pop_back();
        cnt++;
    }
}

int main() {
    cin >> s;
    for (char c : s)
        freq[c]++;

    permute();

    cout << ans.size() << "\n";
    for (const string& t : ans)
        cout << t << "\n";
}
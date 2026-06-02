#include <bits/stdc++.h>
using namespace std;

string board[8];
bool colUsed[8], diag1[16], diag2[16];
long long ans;

void dfs(int row) {
    if (row == 8) {
        ans++;
        return;
    }

    for (int col = 0; col < 8; col++) {
        if (board[row][col] == '*') continue;
        if (colUsed[col] || diag1[row + col] || diag2[row - col + 7]) continue;

        colUsed[col] = diag1[row + col] = diag2[row - col + 7] = true;
        dfs(row + 1);
        colUsed[col] = diag1[row + col] = diag2[row - col + 7] = false;
    }
}

int main() {
    for (int i = 0; i < 8; i++)
        cin >> board[i];

    dfs(0);
    cout << ans << "\n";
    return 0;
}
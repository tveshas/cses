#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  const int MAXV = 1e6;
  vector<int> divcnt(MAXV + 1, 0);

  for (int i = 1; i <= MAXV; i++) {
    for (int j = i; j <= MAXV; j += i) {
      divcnt[j]++;
    }
  }

  while (n--) {
    int x;
    cin >> x;
    cout << divcnt[x] << "\n";
  }

  return 0;
}
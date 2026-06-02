#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    long long median = a[n/2];
    long long cost=0;
    for(int i = 0; i < n; i++){
        cost += abs((long long)a[i] - median);
    }
    cout << cost << endl;
    return 0;
}
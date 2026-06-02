#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    sort(a.begin(), a.end()); //desired
    sort(b.begin(), b.end()); //available
    int i=0, j=0, count=0;
    while(i<n && j<m){
        if(a[i]-k <= b[j] && a[i]+k >= b[j]){
            count++;
            i++,j++;
        }
        else if(a[i]-k > b[j]){
            j++;
        }
        else{
            i++;
        }
    }
    cout << count << endl;
}
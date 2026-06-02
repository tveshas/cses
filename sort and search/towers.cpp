#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    multiset<int> tops;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        auto it = tops.upper_bound(x);
        if(it != tops.end()){
            tops.erase(it);
        }
        tops.insert(x);
    }
    cout << tops.size() << "\n";
}
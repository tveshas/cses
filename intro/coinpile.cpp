#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, a, b;
    cin>>t;
    while(t--){
        cin >> a>>b;
        if ((a + b) % 3 ==0&&(2*b-a)%3==0) {
            int x = (2*b-a)/3;
            int y = (2*a-b)/3;
            if(x>=0&&y>=0){
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
    
}
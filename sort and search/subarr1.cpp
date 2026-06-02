#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int l=0,r=0,sum=0,count=0;
    while(r<n&&l<=r){
        sum+=a[r];
        while(sum>x){
            sum-=a[l];
            l++;
        }
        if(sum==x){
            count++;
            r++;
        }
        else{
            r++;
        }
    }
    cout << count << endl;
    return 0;
}
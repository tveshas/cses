#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    stack<int> s;
    for(int i=0;i<n;i++){
        if(!s.empty()&&a[s.top()]<a[i]){
            cout<<s.top()+1<<" ";
            s.push(i);
        }
        else{
            while(!s.empty()&&a[s.top()]>=a[i]){
                s.pop();
            }
            if(s.empty()){
                cout<<0<<" ";
                s.push(i);
            }
            else{
                cout<<s.top()+1<<" ";
                s.push(i);
            }
        }
    }
    return 0;
}
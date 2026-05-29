#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int c = 1, b = 1;
    for(int i = 1; i < n; i++){
        if(s[i] == s[i-1]) c++;
        else c = 1;
        b = max(b, c);
    }
    cout << b << endl;
}
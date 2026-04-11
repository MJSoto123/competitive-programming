#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;
    int n = s.size();
    for(int i = 1; i < n; i += 2){
        if(s[i] == '1') {cout << "No\n"; return 0;}
    }
    cout << "Yes\n";
}
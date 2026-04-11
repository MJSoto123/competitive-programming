#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    int ones = count(s.begin(), s.end(), '1');

    for(int i = 0; i < n; i++){
        if(s[i] == '1') ans += (ones - 1);
        else ans += (ones + 1);
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}
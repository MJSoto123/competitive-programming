#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s, t; cin >> s >> t;
    int n = s.size();

    vector<string> ans;
    while(s != t){
        vector<string> now;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] != t[i]) {
                string s2 = s;
                s2[i] = t[i];
                now.emplace_back(s2);
            }
        }
        sort(now.begin(), now.end());
        s = now[0];
        ans.emplace_back(s);
    }

    cout << ans.size() << "\n";
    for(auto x : ans) cout << x << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
}
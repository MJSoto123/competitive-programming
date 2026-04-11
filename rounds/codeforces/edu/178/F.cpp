#include<bits/stdc++.h>
using namespace std;

string get(int i){
    string s1 = to_string(i);
    string s2 = to_string(i + 1);
    s1 += s2;
    sort(s1.begin(), s1.end());
    return s1;
}

void solve(){
    int n; cin >> n;
    map<string, vector<int>> mp;
    for(int i = 1; i <= n; i++){
        string s = get(i);
        mp[s].emplace_back(i);
    }

    int ans = 0;
    for(auto [s, x] : mp){
        if(x.size() <= 1) continue;

        cout << s << " => ";
        for(auto y : x) {
            ans++;
            cout << y << " ";
        }
        cout << "\n";
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}
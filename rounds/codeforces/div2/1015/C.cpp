#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    
    map<int, int> mp;
    vector<int> pos(n + 1);
    int eq = 0;
    for(int i = 0; i < n; i++){
        mp[a[i]] = b[i];
        pos[a[i]] = i;
        if(a[i] == b[i]) eq++;
    }

    for(auto [from, to] : mp){
        if(mp[to] != from) {cout << "-1\n"; return;}
    }

    vector<pair<int, int>> ans;
    if(eq > 1) {cout << "-1\n"; return; }
    if(eq == 1){
        for(int i = 0; i < n; i++) {
            if(a[i] != b[i] || i == n / 2) continue;
            pos[a[i]] = n / 2;
            pos[a[n / 2]] = i;
            swap(a[i], a[n / 2]);
            ans.emplace_back(i, n / 2);
        }
    }

    for(int i = 0; i < n; i++){
        int p = pos[mp[a[i]]];
        if(p + i != n - 1){
            ans.emplace_back(p, n - i - 1);
            pos[a[n - i - 1]] = p;
            pos[a[p]] = n - i - 1;
            swap(a[p], a[n - i - 1]);
        }
    }

    cout << ans.size() << "\n";
    for(auto [i, j] : ans) cout << i + 1 << " " << j + 1 << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();    
    return 0;
}
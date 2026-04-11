#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    vector<int> pref(n), suf(n);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(cnt < m && a[i] >= b[cnt])  cnt++;
        pref[i] = cnt;
    }

    cnt = 0;
    for(int i = n - 1; i >= 0; i--){
        if(cnt < m && a[i] >= b[m - 1 - cnt]) cnt++;
        suf[i] = cnt;
    }

    if(pref.back() == m || suf[0] == m) { cout << "0\n"; return; }

    int ans = INT_MAX;
    bool can = 0;
    
    int l = 0, r = 1e9 + 100; 
    while(r - l > 1){
        int mid = (l + r) / 2;
        bool ok = false;
        if(suf[0] == m - 1 && mid >= b[0]) ok = true;
        if(pref.back() == m - 1 && mid >= b.back()) ok = true;

        for(int i = 0; i < n - 1; i++){
            int curr = pref[i] + (mid >= b[pref[i]]) + suf[i + 1];
            if(curr >= m) ok = true;
        }

        if(ok) {
            r = mid;
            can = true;
        }
        else l = mid;
    }

    if(!can) cout << -1 << "\n";
    else cout << r << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];


    int l = 0, lastl = -1;
    for(int i = 0; i < n; i++){
        if(l == m) continue;
        if(a[i] >= b[l]) {
            l++;
            lastl = i;
        }
    }

    int r = 0, lastr = n;
    for(int i = n - 1; i >= 0; i--){
        if(r == m) continue;
        if(a[i] >= b[m - 1 - r]) {
            r++;
            lastr = i;
        }
    }   

    if(l == m || r == m) { cout << "0\n"; return; }

    int ans = INT_MAX;
    bool can = 0;
    {
        int now = b[l];
        l++;
        for(int i = lastl + 1; i < n; i++){
            if(l == m) { ans = now; can = true; break; }
            if(a[i] >= b[l]) l++;
        }
        if(l == m) { ans = now; can = true;}
    }
    
    {
        int now = b[m - 1 - r];
        r++;
        for(int i = lastr - 1; i >= 0; i--){
            if(r == m) { ans = min(ans, now); can = true; break; }
            if(a[i] >= b[m - 1 - r]) r++;
        }
        if(r == m) { ans = min(ans, now); can = true;}
    }

    if(!can) cout << -1 << "\n";
    else cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}
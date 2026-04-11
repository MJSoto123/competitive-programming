#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

void solve(){
    int n, m; cin >> n >> m;
    vi cnt(m + 1);
    vvi a(n);
    rep(i, 0, n){
        int l; cin >> l;
        rep(j, 0, l){
            int x; cin >> x;
            a[i].emplace_back(x);
            cnt[x]++;
        }
    }

    rep(i, 1, m + 1) if(cnt[i] == 0){ cout << "NO\n"; return; }
    int ans = 0;
    rep(i, 0, n){
        bool ok = true;
        rep(j, 0, sz(a[i])){
            if(cnt[a[i][j]] == 1) ok = false; 
        }
        if(ok) ans++;
    }

    if(ans >= 2) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}
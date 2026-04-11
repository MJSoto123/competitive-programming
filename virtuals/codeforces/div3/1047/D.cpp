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
    int n; cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    
    vvi cnt(n + 1);
    rep(i, 0, n) cnt[a[i]].emplace_back(i);

    vi ans(n);
    int num = 1;
    rep(i, 1, n + 1) if(sz(cnt[i])){
        if(sz(cnt[i]) % i){ cout << "-1\n"; return; }
        rep(j, 0, sz(cnt[i])){
            ans[cnt[i][j]] = num;
            if(j % i ==  i - 1) num++;
        }
    }

    rep(i, 0, n) cout << ans[i] << " \n"[i == n - 1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}
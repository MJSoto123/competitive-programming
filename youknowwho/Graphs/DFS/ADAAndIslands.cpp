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

// UDLR
vi dr = {-1, 1, 0, 0};
vi dc = {0, 0, -1, 1};
void solve(){
    int n, m; cin >> n >> m;
    vector<string> a(n);
    rep(i, 0, n) cin >> a[i];

    auto check = [&](int r, int c){
        return (r >= 0 && r < n && c >= 0 && c < m);
    };

    vvi vis(n, vi(m));
    function<int(int, int)> go = [&](int r, int c){
        int ret = 1;
        rep(i, 0, 4){
            int nr = r + dr[i], nc = c + dc[i];
            if(!check(nr, nc) || a[nr][nc] != '#' || vis[nr][nc]) continue;
            vis[nr][nc] = 1;
            ret += go(nr, nc);
        }
        return ret;
    };

    ll ans = 0;
    rep(i, 0, n) rep(j, 0, m){
        if(vis[i][j] || a[i][j] != '#') continue;
        vis[i][j] = 1;
        ll ret = go(i, j);
        ans += 1LL * ret * ret;
    }

    ll tot = n * m;
    ll g = __gcd(tot, ans);
    if(ans == 0){ cout << "0\n"; return; }
    if(ans % tot == 0){ cout << ans / tot << "\n"; return; }
    cout << ans / g << " / " << tot / g << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}
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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vvi g(n);
    rep(i, 1, n){
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vvi dp(n, vi(k + 2));
    vvi children(n);
    function<void(int)> go = [&](int u){
        dp[u][0] = 1;
        for(auto v : g[u]){
            if(sz(children[v])) continue;
            children[u].emplace_back(v);
            go(v);
            rep(d, 0, k) dp[u][d + 1] += dp[v][d];
        }
    };
    go(0);

    ll ans = 0;
    rep(u, 0, n){
        rep(d, 1, k) {
            for(auto v : children[u]){
                // ini
                int here = dp[v][d - 1];

                // fin
                int other = dp[u][k - d] - dp[v][k - d - 1];
                ans += 1LL * here * other;
            }
        }
    }

    ans /= 2;
    rep(u, 0, n) ans += dp[u][k];
    cout << ans << "\n";
}
#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<ll> vi;
typedef vector< vi> vvi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

void solve(){
    int n; cin >> n;
    vvi g(n);
    vvi a(n, vi(2));
    rep(i, 0, n) cin >> a[i][0] >> a[i][1];
    rep(i, 0, n - 1){
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vvi dp(n, vi(2, 0));
    function<void(int, int)> dfs = [&](int u, int p){
        for(auto v : g[u]){
            if(v == p) continue;
            dfs(v, u);
            rep(i, 0, 2){
                ll here = 0;
                rep(j, 0, 2){
                    here = max(here, dp[v][j] + abs(a[u][i] - a[v][j]));
                }
                dp[u][i] += here;
            }
        }
    }; dfs(0, -1);

    cout << max(dp[0][0], dp[0][1]) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}
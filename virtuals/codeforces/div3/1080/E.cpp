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
const int MOD = 1e9 + 7;
void solve(){
    int n; cin >> n;
    vvi g(n + 2, vi(2));
    vi par(n + 2);
    
    g[0][0] = 1;
    for(int i = 1; i <= n; i++){
        int l, r; cin >> l >> r;
        g[i][0] = l; g[i][1] = r;
        par[l] = i; par[r] = i;
    }

    vi dp(n + 2);
    function<void(int, int)> dfs = [&](int u, int p){
        dp[u] = 0;
        for(auto v : g[u]){
            if(v == 0) continue;
            if(v == p) continue;
            dfs(v, u);
            dp[u] = (dp[u] + 1 + dp[v]) % MOD;
        }
        dp[u]++;
    }; dfs(0, -1);

    vi ans(n + 2);
    function<void(int, int)> dfs2 = [&](int u, int p){
        for(auto v : g[u]){
            if(v == 0) continue;
            if(v == p) continue;
            ans[v] = (dp[v] + ans[u]) % MOD;
            dfs2(v, u);
        }
    }; dfs2(0, -1);

    for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}
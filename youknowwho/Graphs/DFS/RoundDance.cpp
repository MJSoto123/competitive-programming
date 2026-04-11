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
    vvi g(n + 1);
    rep(u, 1, n + 1){
        int v; cin >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    rep(u, 1, n + 1){
        sort(all(g[u]));
        g[u].resize(unique(all(g[u])) - g[u].begin());
    }

    int cyc = 0, nocyc = 0;

    vi vis(n + 1);
    function<bool(int)> iscyc = [&](int u){
        bool ok = (sz(g[u]) == 2);
        for(auto v : g[u]){
            if(vis[v]) continue;
            vis[v] = 1;
            ok &= iscyc(v);
        }
        return ok;
    };

    rep(u, 1, n + 1){
        if(vis[u]) continue;
        vis[u] = 1;
        if(iscyc(u)) cyc++;
        else nocyc++;
    }

    cout << cyc + (nocyc != 0) << " " << cyc + nocyc << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}
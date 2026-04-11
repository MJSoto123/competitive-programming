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
    int n, m, q; cin >> n >> m >> q;
    vvi g(n + 1);
    vvi inv(n + 1);
    vi deg(n + 1);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        inv[v].emplace_back(u);
        deg[u]++;
    }

    vi can(n + 1);
    rep(i, 1, n + 1) can[i] = (deg[i] ? deg[i] : 100);

    function<void(int, bool)> upd = [&](int u, bool fs){
        if(fs) can[u] = 0;
        for(auto v : inv[u]){
            if(!can[v]) continue;
            can[v]--;
            if(fs) upd(v, 0);
        }
    };

    rep(qq, 0, q){
        int op, u; cin >> op >> u;
        if(op == 1) upd(u, 1);
        else cout << (can[u] ? "YES" : "NO") << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}
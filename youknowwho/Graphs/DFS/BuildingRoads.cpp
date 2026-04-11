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

    int n, m; cin >> n >> m;
    vvi g(n + 1);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vi vis(n + 1);
    function<void(int)> go = [&](int u){
        for(auto v : g[u]){
            if(vis[v]) continue;
            vis[v] = 1;
            go(v);
        }
    };

    vi comp;
    rep(u, 1, n + 1){
        if(vis[u]) continue;
        comp.emplace_back(u);
        vis[u] = 1;
        go(u);
    }

    cout << sz(comp) - 1 << "\n";
    rep(i, 1, sz(comp)) cout << comp[0] << " " << comp[i] << "\n";
}
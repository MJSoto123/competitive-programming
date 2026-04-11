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
    vii edges(m);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        edges[i] = {u, v};
    }

    vi col(n + 1, -1);
    function<bool(int)> go = [&](int u){
        bool ret = 1;
        for(auto v : g[u]){
            if(col[v] != -1 && col[v] == col[u]) return false;
            if(col[v] != -1) continue; 
            col[v] = col[u] ^ 1;
            ret &= go(v);
        }
        return ret;
    }; col[1] = 0; 

    bool ok = go(1);
    if(!ok){ cout << "NO\n"; return 0; }

    cout << "YES\n";
    for(auto [u, v] : edges) cout << col[u];
    cout << "\n";
}
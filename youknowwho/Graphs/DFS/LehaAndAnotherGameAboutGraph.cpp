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
    vi d(n);
    for(int i = 0; i < n; i++) cin >> d[i];

    vvi g(n);
    vii edges(m);
    map<pii, int> mp;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--; v--;
        if(u < v) swap(u, v); // mx mn
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        edges[i] = make_pair(u, v);
        mp[edges[i]] = i;
    }

    int sm = 0;
    set<int> b;
    for(int i = 0; i < n; i++){
        if(d[i] == -1) b.emplace(i);
        else sm += d[i];
    }

    bool ready = (sm % 2 == 0);
    for(auto u : b){
        bool here = false;
        for(auto v : g[u]){
            if(b.count(v)) continue;
            here = 1;
        }
        if(ready) d[u] = 0;
        else{
            if(here){
                d[u] = 1;
                ready = 1;
            }
            else d[u] = 0;
        }
    }
    sm = accumulate(all(d), 0);
    if(sm % 2){ cout << "-1\n"; return 0; }

    vvi g2(n);
    vi vis(n);
    function<void(int)> dfs = [&](int u){
        for(auto v : g[u]){
            if(vis[v]) continue;
            g2[u].emplace_back(v);
            g2[v].emplace_back(u);
            vis[v] = 1;
            dfs(v);
        }
    };
    vis[0] = 1;
    dfs(0);

    vi depth(n);
    vi par(n, -1);
    function<void(int)> go = [&](int u){
        for(auto v : g2[u]){
            if(depth[v]) continue;
            depth[v] = depth[u] + 1;
            par[v] = u;
            go(v);
        }
    };

    depth[0] = 1;
    go(0);

    vi ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j){
        return (depth[i] > depth[j]);
    });


    // for(auto [ed, i] : mp){
    //     cerr << ed.first << " " << ed.second << " " << i << "\n";
    // }
    vi ans;
    for(auto u : ord){
        if(u == 0) continue; 
        // cerr << "go " << u << " " << d[u] << " " << par[u] << "\n";
        if(d[u]){
            d[par[u]] ^= 1;
            ans.emplace_back(mp[{max(u, par[u]), min(u, par[u])}]);
        }
    }

    cout << sz(ans) << "\n";
    for(auto x : ans) cout << x + 1 << " "; cout << "\n";
}
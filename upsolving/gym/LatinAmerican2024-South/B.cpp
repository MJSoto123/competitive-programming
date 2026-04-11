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

    map<pii, int> edges;
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        edges[{max(u, v), min(u, v)}] = i + 1;
    }
    
    vi disc(n + 1);
    int timer = 1;
    vi par(n + 1);
    int from = -1, to = -1, val = 0;
    function<void(int, int)> go = [&](int u, int p = -1){
        par[u] = p;
        disc[u] = timer++;
        for(auto v : g[u]){
            if(v == p) continue;
            if(disc[v]){
                if(disc[u] < disc[v]) continue;
                if(disc[v] > val){
                    from = u;
                    to = v;
                    val = disc[v];
                }
                continue;
            }
            go(v, u);
        }
    }; go(1, -1);

    vi path;
    while(from != to){
        path.emplace_back(from);
        from = par[from];
    }
    path.emplace_back(to);
    
    cout << sz(path) << "\n";
    // for(auto u : path) cout << u << " "; cout << "\n";
    rep(i, 1, sz(path)){
        cout << edges[{max(path[i], path[i - 1]), min(path[i], path[i - 1])}] << " ";
    }
    cout << edges[{max(path[0], path.back()), min(path[0], path.back())}] << "\n";
}
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

vector<vii> g;
vi vis;
vii ed;
vl vals;

vi comp;

int n, m;
void dfs(int u){
    comp.emplace_back(u);
    for(auto [v, id] : g[u]){
        if(vis[v]) continue;
        vis[v] = 1;
        dfs(v);
    }
}

void mark(int val){
    for(auto u : comp) vis[u] = val;
    if(val == 0) for(auto u : comp) vals[u] = -1;
}

ll lcm(ll a, ll b){ return (a * b) / __gcd(a, b); }

bool go(int u, ll val){
    bool ret = 1;
    for(auto [v, id] : g[u]){
        if(vis[v]) continue;
        vis[v] = 1;
        ll gc = ed[id].first;
        ll lc = ed[id].second;
        // cerr << "u v " << u << " " << v << " => " << gc << " " << lc << "\n";
        if((gc * lc) % val != 0) return false;

        ll other = gc * lc / val;
        if(vals[v] == -1) vals[v] = other;
        if(vals[v] != other) return false;
        if(__gcd(vals[v], vals[u]) != gc || lcm(vals[v], vals[u]) != lc) return false;
        ret &= go(v, other);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    g.resize(n);
    vis.assign(n, 0);
    vals.assign(n, -1);
    ed.resize(m);

    rep(i, 0, m){
        int u, v, a, b; cin >> u >> v >> a >> b;
        u--; v--;
        ed[i] = {a, b};
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }

    bool ok = true;
    rep(i, 0, n){
        if(vis[i]) continue;
        // cerr << "\nchecking " << i << "\n";
        bool can = false;
        comp.clear();
        vis[i] = 1;
        dfs(i);
        // for(auto x : comp) cerr << x << " "; cerr << "\n";

        rep(j, 1, 1000000 + 1){
            mark(0);
            vals[i] = j;
            // cerr << "try " << j << "\n"; 
            if(go(i, j)){
                can = true;
                break;
            }
        }
        
        mark(1);
        if(!can) ok = false;
    }

    if(!ok){ cout << "NO\n"; return 0; }
    cout << "YES\n";
    rep(i, 0, n) cout << vals[i] << " "; cout << "\n";
}
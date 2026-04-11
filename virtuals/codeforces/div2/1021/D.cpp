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
int mul(ll a, ll b){ return (a * b) % MOD; }

void solve(){
    int  n, m, k; cin >> n >> m >> k;

    vii path;
    rep(i, 0, k + 1){
        int r, c; cin >> r >> c; r--; c--;
        path.emplace_back(r, c);
    }

    vvi g(n * m);
    rep(i, 0, k){
        auto [r1, c1] = path[i];
        auto [r2, c2] = path[i + 1];
        int dr = r2 - r1;
        int dc = c2 - c1;

        if(abs(dr) + abs(dc) != 2){ cout << "0\n"; return; }
        if(r1 == r2){
            g[r1 * m + c1 + dc / 2].emplace_back(r1 * m + c1 + dc / 2);
        }else if(c1 == c2){
            g[(r1 + dr / 2) * m + c1].emplace_back((r1 + dr / 2) * m + c1);
        }else{
            g[r1 * m + c1 + dc].emplace_back((r1 + dr) * m + c1);
            g[(r1 + dr) * m + c1].emplace_back(r1 * m + c1 + dc);
        }
    }

    vi vis(n * m);
    set<pii> edges;
    bool bad = 0;
    function<void(int)> dfs = [&](int u){
        for(auto v : g[u]){
            if(u == v){
                if(edges.count({min(u, v), max(u, v)})){ bad = 1; return; }
            }
            edges.emplace(min(u, v), max(u, v));            
            if(vis[v]) continue;
            vis[v] = 1;
            dfs(v);
        }
    };

    int ans = 1;
    rep(i, 0, n * m){
        if(vis[i]) continue;
        vis[i] = 1;
        edges.clear(); bad = 0;
        dfs(i); 

        if(bad){ cout << "0\n"; return; }
        set<int> ver;
        bool cyc = false;
        for(auto [u, v] : edges){
            ver.insert(u);
            ver.insert(v);
            if(u == v) cyc = true;
        }
        int ed = sz(edges);
        int ve = sz(ver);
        if(ve == 0) continue;

        if(ed > ve){ cout << "0\n"; return; } 
        if(ed == ve && !cyc) ans = mul(ans, 2);
        if(ed == ve - 1) ans = mul(ans, ve);
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt; 
    while(tt--) solve();   
}
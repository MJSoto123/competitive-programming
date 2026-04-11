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
ll mul(ll a, ll b){ return (a * b) % MOD; }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vii edges(m);
    vvi g(n + 1);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        edges[i] = {u, v};
    }


    vii tofix;
    vi disc(n + 1), par(n + 1);
    int timer = 1;
    function<void(int, int)> go = [&](int u, int p = - 1){
        disc[u] = timer++;
        par[u] = p;
        for(auto v : g[u]){
            if(v == p) continue;
            if(disc[v]){
                if(disc[v] > disc[u]) continue;
                tofix.emplace_back(u, v);
                continue;
            }
            go(v, u);
        }
    }; go(1, -1);

    vi rename(n + 1);
    rep(i, 1, n + 1) rename[i] = i;
    int name = n + 1;
    for(auto [from, to] : tofix){
        while(from != to){
            rename[from] = name;
            from = par[from];
        }
        rename[to] = name;
        name++;
    }

    vvi g2(2 * n + 2);
    for(auto [u, v] : edges){
        if(rename[u] != rename[v]){
            g2[rename[u]].emplace_back(rename[v]);
            g2[rename[v]].emplace_back(rename[u]);
        }
    }

    vi dp(2 * n + 2);
    vi deep(2 * n + 2);
    vvi up(2 * n + 2, vi(20));
    // cerr << "rename: ";
    // rep(i, 1, n + 1) cerr << rename[i] << " "; cerr << "\n";
    function<void(int, int)> godp = [&](int u, int p){
        for(auto v : g2[u]){
            if(p == v) continue;
            deep[v] = deep[u] + 1;
            dp[v] = dp[u];
            if(v > n) dp[v]++;
            up[v][0] = u;
            rep(i, 1, 20) up[v][i] = up[up[v][i - 1]][i - 1];
            godp(v, u);
        }
    }; 
    if(rename[1] > n) dp[rename[1]] = 1; 
    godp(rename[1], rename[1]);


    function<int(int, int)> lca = [&](int u, int v){
        if(deep[u] < deep[v]) swap(u, v);
        int k = deep[u] - deep[v];
        rep(i, 0, 20) if((k >> i) & 1) u = up[u][i];
        if(u == v) return u;
        for(int i = 19; i >= 0; i--){
            if(up[u][i] != up[v][i]){
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    };


    vi pot(2 * n + 2, 1);
    rep(i, 1, 2 * n) pot[i] = mul(pot[i - 1], 2);
    int q; cin >> q;
    rep(qq, 0, q){
        int u, v; cin >> u >> v;
        u = rename[u]; v = rename[v];
        int anc = lca(u, v);
        int exp = dp[u] + dp[v] - 2 * dp[anc];
        if(anc > n) exp++;
        cout << pot[exp] << "\n";
    }
}
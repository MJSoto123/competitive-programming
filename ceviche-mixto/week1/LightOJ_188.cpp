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

struct ST{
    int n;
    vi t;
    ST(int n) : n(n), t(4 * n + 5){}
    void upd(int v, int l, int r, int lq, int rq, int val){
        if(r < lq || rq < l) return; 
        if(lq <= l && r <= rq){
            t[v] += val;
            return;
        }
        int mid = l + r >> 1;
        upd(2 * v + 1, l, mid, lq, rq, val);
        upd(2 * v + 2, mid + 1, r, lq, rq, val);
    }
    void upd(int lq, int rq, int val){ upd(0, 0, n - 1, lq, rq, val); }

    int query(int v, int l, int r, int pos){
        if(pos < l || pos > r) return 0;
        if(l == r) return t[v];

        int mid = l + r >> 1;
        return (
            t[v] + 
            query(2 * v + 1, l, mid, pos) + 
            query(2 * v + 2, mid + 1, r, pos) 
        );
    }
    int query(int pos){ return query(0, 0, n - 1, pos); }
};


void solve(){
    int n; cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    vvi g(n);
    rep(i, 0, n - 1){
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vi in(n), out(n);
    int timer = 1;

    int lg = log2(n) + 1;
    vvi par(lg, vi(n));
    vi depth(n);

    function<void(int, int, int)> dfs = [&](int u, int p, int d){
        depth[u] = d;
        par[0][u] = p;
        rep(i, 1, lg) par[i][u] = par[i - 1][par[i - 1][u]];

        in[u] = timer;
        for(auto v : g[u]){
            if(v == p) continue;
            timer++;
            dfs(v, u, d + 1);
        }
        out[u] = timer;
    }; dfs(0, 0, 0);

    function<int(int, int)> lca = [&](int u, int v){
        if(depth[v] < depth[u]) swap(u, v);
        int d = depth[v] - depth[u];

        for(int i = lg - 1; i >= 0; i--) if(d >> i & 1) v = par[i][v];
        if(u == v) return u;
        for(int i = lg - 1; i >= 0; i--) if(par[i][u] != par[i][v]){
            u = par[i][u];
            v = par[i][v];
        }
        return par[0][u];
    };

    ST seg(n + 5);
    rep(i, 0, n) seg.upd(in[i], out[i], a[i]);

    // rep(i, 0, n) cerr << i << " => " << in[i] << " " << out[i] << "\n";
    // rep(i, 0, n) cerr << seg.query(in[i]) << "\n";

    int qq; cin >> qq;
    rep(_, 0, qq){
        int op; cin >> op;
        if(op == 0){
            int u, v; cin >> u >> v;
            int anc = lca(u, v);
            cout << seg.query(in[u]) + seg.query(in[v]) - 2 * seg.query(in[anc]) + a[anc] << "\n";
        }else {
            int u, val; cin >> u >> val;
            seg.upd(in[u], out[u], -a[u] + val);
            a[u] = val;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    rep(i, 1, tt + 1){
        cout << "Case " << i << ":\n";
        solve(); 
    }
}
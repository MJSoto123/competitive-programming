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

struct Seg{
    int n;
    vl t;
    Seg(int nn) : n(nn), t(4 * nn + 10) {}
    void upd(int v, int l, int r, int lq, int rq, ll val){
        if(lq > r || l > rq) return;
        if(lq <= l && r <= rq){
            t[v] += val;
            return;
        }
        int mid = l + r >> 1;
        upd(2 * v + 1, l, mid, lq, rq, val);
        upd(2 * v + 2, mid + 1, r, lq, rq, val);
    }
    void upd(int lq, int rq, ll val){ upd(0, 0, n - 1, lq, rq, val); }

    ll query(int v, int l, int r, int pos){
        if(pos < l || pos > r) return 0;
        if(l == r) return t[v];
        int mid = l + r >> 1;
        return (
            t[v] + 
            query(2 * v + 1, l, mid, pos) + 
            query(2 * v + 2, mid + 1, r, pos)
        );
    }
    ll query(int pos){ return query(0, 0, n - 1, pos); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    vvi g(n);
    rep(i, 0, n - 1){
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vi in(n), out(n), dist(n);
    vi ord;
    function<void(int, int)> dfs = [&](int u, int p = -1){
        in[u] = sz(ord);
        ord.emplace_back(u);
        for(auto v : g[u]){
            if(v == p) continue;
            dist[v] = dist[u] + 1;
            dfs(v, u);
        }
        out[u] = sz(ord) - 1;
    }; dfs(0, -1);

    Seg even(n), odd(n);
    rep(_, 0, m){
        int op; cin >> op;
        if(op == 1){
            int u, val; cin >> u >> val;
            u--;
            if(dist[u] % 2 == 0) even.upd(in[u], out[u], val);
            else  odd.upd(in[u], out[u], val);
        }else{
            int u; cin >> u;
            u--;
            ll ans = a[u];
            ll sm0 = even.query(in[u]);
            ll sm1 = odd.query(in[u]);
            if(dist[u] % 2 == 0) ans += (sm0 - sm1);
            else ans += (sm1 - sm0);

            cout << ans << "\n";
        }
    }
}
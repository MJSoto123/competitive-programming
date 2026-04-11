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
int add(int a, int b){ return (a + b) % MOD; }
int mul(int a, int b){ return 1LL * a * b % MOD; }
int subs(int a, int b){ return (a + MOD - b) % MOD; }

struct Seg{
    int n;
    vi t;
    Seg(int nn) : n(nn), t(4 * nn + 10) {}
    void upd(int v, int l, int r, int lq, int rq, int val){
        if(lq > r || l > rq) return;
        if(lq <= l && r <= rq){
            t[v] = add(t[v], val);
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
        return add(
            t[v], add(
            query(2 * v + 1, l, mid, pos),
            query(2 * v + 2, mid + 1, r, pos)
        ));
    }
    int query(int pos){ return query(0, 0, n -1, pos); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vvi g(n);
    rep(u, 1, n){
        int p; cin >> p; 
        p--;
        g[p].emplace_back(u);
    }

    vi in(n), out(n), dist(n);
    vi a;
    function<void(int)> dfs = [&](int u){
        in[u] = sz(a);
        a.emplace_back(u);
        for(auto v : g[u]){
            dist[v] = dist[u] + 1;
            dfs(v);
        }
        out[u] = sz(a) - 1;
    }; dfs(0);

    Seg st(n), sobra(n);
    int m; cin >> m;
    rep(i, 0, m){
        int op; cin >> op;
        if(op == 1){
            int u, val, k; cin >> u >> val >> k;
            u--;
            int here = add(val, mul(k, dist[u]));
            st.upd(in[u], out[u], here);
            sobra.upd(in[u], out[u], k);
        }else{
            int u; cin >> u;
            u--;
            int here = subs(st.query(in[u]), mul(sobra.query(in[u]), dist[u]));
            cout << here << "\n";
        }
    }
}
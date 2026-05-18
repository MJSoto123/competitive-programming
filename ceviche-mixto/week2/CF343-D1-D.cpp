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

const int N = 500000 + 10;
vi g[N];
int in[N], out[N];
int timer = 0;

void dfs(int u, int p = -1){
    timer++;
    in[u] = timer;
    for(auto v : g[u]){
        if(v == p) continue;
        dfs(v, u);
    }
    out[u] = timer;
}

struct Seg{
    int n;
    vi t;
    Seg(int n) : n(n), t(4 * n + 5) {};

    void range_upd(int v, int l, int r, int lq, int rq, int val){
        if(r < lq || rq < l) return; 
        if(lq <= l && r <= rq){
            t[v] = val;
            return;
        }
        int mid = l + r >> 1;
        range_upd(2 * v + 1, l, mid, lq, rq, val);
        range_upd(2 * v + 2, mid + 1, r, lq, rq, val);
    }
    void range_upd(int lq, int rq, int val){ range_upd(0, 0, n - 1, lq, rq, val); }

    int query(int v, int l, int r, int pos){
        if(pos < l || r < pos) return 0; 
        if(l == r) return t[v];
        int mid = l + r >> 1;
        return max({
            t[v],
            query(2 * v + 1, l, mid, pos), 
            query(2 * v + 2, mid + 1, r, pos)
    });
    }
    int query(int pos){ return query(0, 0, n - 1, pos); }

    void print(){
        rep(i, 0, n) cerr << query(i) << " ";
        cerr << "\n";
        cerr << "\n";
    }
};

struct Seg2{
    int n;
    vi t;
    Seg2(int n) : n(n), t(4 * n + 5) {};
    void point_upd(int v, int l, int r, int pos, int val){
        if(pos < l || r < pos) return;
        if(l == r){
            t[v] = val;
            return;
        }
        int mid = l + r >> 1;
        point_upd(2 * v + 1, l, mid, pos, val);
        point_upd(2 * v + 2, mid + 1, r, pos, val);
        t[v] = max(t[2 * v + 1], t[2 * v + 2]);
    }
    void point_upd(int pos, int val){ point_upd(0, 0, n - 1, pos, val); }

    int query(int v, int l, int r, int lq, int rq){
        if(r < lq || rq < l) return 0;
        if(lq <= l && r <= rq) return t[v];
        int mid = l + r >> 1;
        return max(
            query(2 * v + 1, l, mid, lq, rq),
            query(2 * v + 2, mid + 1, r, lq, rq)
        );
    }
    int query(int lq, int rq){ return query(0, 0, n - 1, lq, rq); }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    rep(i, 0, n - 1){
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    dfs(0);
    rep(u, 0, n) in[u]--, out[u]--;

    Seg st(n);
    Seg2 par(n);
    int qq; cin >> qq;
    rep(i, 0, qq){
        // st.print();
        int op; cin >> op;
        int v; cin >> v; v--;
        if(op == 1) st.range_upd(in[v], out[v], i + 1);
        if(op == 2) par.point_upd(in[v], i + 1);
        if(op == 3){
            int last1 = st.query(in[v]);
            int last2 = par.query(in[v], out[v]);
            cout << (last1 > last2) << "\n";
        }
    }
}
#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

const ll inf = 2e18;
struct Seg{
    int n;
    vl t, lz;
    void build(const vl &a, int v, int l, int r){
        if(l == r){
            t[v] = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(a, 2 * v + 1, l, mid);
        build(a, 2 * v + 2, mid + 1, r);
        t[v] = max(t[2 * v + 1], t[2 * v + 2]);
    }
    void init(const vl &a){
        n = sz(a);
        t.assign(4 * n + 10, -inf);
        lz.assign(4 * n + 10, 0);
        build(a, 0, 0, n - 1);
    }

    void push(int v, int l, int r){
        if(lz[v] == 0) return;
        if(l != r){
            lz[2 * v + 1] += lz[v];
            lz[2 * v + 2] += lz[v];
        }
        t[v] += lz[v];
        lz[v] = 0;
    }

    void upd(int v, int l, int r, int lq, int rq, ll val){
        push(v, l, r);
        if(lq > r || l > rq) return;
        if(lq <= l && r <= rq){
            lz[v] += val;
            push(v, l, r);
            return;
        }
        int mid = l + r >> 1;
        upd(2 * v + 1, l, mid, lq, rq, val);
        upd(2 * v + 2, mid + 1, r, lq, rq, val);
        t[v] = max(t[2 * v + 1], t[2 * v + 2]);
    }
    void upd(int lq, int rq, ll val){ upd(0, 0, n - 1, lq, rq, val); }

    ll query(int v, int l, int r, int lq, int rq){
        push(v, l, r);
        if(lq > r || l > rq) return -inf;
        if(lq <= l && r <= rq) return t[v];
        int mid = l + r >> 1;
        return max(
            query(2 * v + 1, l, mid, lq, rq),
            query(2 * v + 2, mid + 1, r, lq, rq)
        );
    }
    ll query(int lq, int rq){ return query(0, 0, n - 1, lq, rq); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vl a(n);
    rep(i, 0, n) cin >> a[i];
    
    vl ori = a;
    rep(i, 1, n) a[i] += a[i - 1];

    Seg st; st.init(a);
    rep(_, 0, q){
        int op; cin >> op;
        if(op == 1){
            int pos, val; cin >> pos >> val; pos--;
            st.upd(pos, n - 1, (-ori[pos] + val));
            ori[pos] = val;
        }else{
            int l, r; cin >> l >> r;
            l--; r--;
            ll ans = st.query(l, r);
            if(l - 1 >= 0) ans -= st.query(l - 1, l - 1);
            cout << max(ans, 0LL) << "\n";
        }
    }
}
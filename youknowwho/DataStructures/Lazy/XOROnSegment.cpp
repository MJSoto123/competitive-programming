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

struct Seg{
    int n;
    int bit;
    vi t, lz;
    void build(const vi &a, int v, int l, int r){
        if(l == r){
            t[v] = (a[l] & bit ? 1 : 0);
            return;
        }
        int mid = l + r >> 1;
        build(a, 2 * v + 1, l, mid);
        build(a, 2 * v + 2, mid + 1, r);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
    void init(const vi &a, int bt){
        n = sz(a);
        bit = (1 << bt);
        t.assign(4 * n + 10, 0);
        lz.assign(4 * n + 10, 0);
        build(a, 0, 0, n - 1);
    }

    void push(int v, int l, int r){
        if(lz[v] == 0) return;
        if(l != r){
            lz[2 * v + 1] ^= lz[v];
            lz[2 * v + 2] ^= lz[v];
        }
        t[v] = (r - l + 1) - t[v];
        lz[v] = 0;
    }

    void upd(int v, int l, int r, int lq, int rq, int val){
        push(v, l, r);
        if(lq > r || l > rq) return;
        if(lq <= l && r <= rq){
            lz[v] = (val & bit ? 1 : 0);
            push(v, l, r);
            return;
        }
        int mid = l + r >> 1;
        upd(2 * v + 1, l, mid, lq, rq, val);
        upd(2 * v + 2, mid + 1, r, lq, rq, val);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
    void upd(int lq, int rq, int val){ upd(0, 0, n - 1, lq, rq, val); }

    int query(int v, int l, int r, int lq, int rq){
        push(v, l, r);
        if(lq > r || l > rq) return 0;
        if(lq <= l && r <= rq) return t[v];
        int mid = l + r >> 1;
        return (
            query(2 * v + 1, l, mid, lq, rq) +
            query(2 * v + 2, mid + 1, r, lq, rq)
        );
    }
    int query(int lq, int rq){ return query(0, 0, n - 1, lq, rq); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    vector<Seg> st(25);
    rep(i, 0, 25) st[i].init(a, i);
    
    int q; cin >> q;
    rep(_, 0, q){
        int op, l, r; cin >> op >> l >> r;
        l--; r--;
        if(op == 1){
            ll ans = 0;
            rep(i, 0, 25) ans += 1LL * st[i].query(l, r) * (1 << i);
            cout << ans << "\n";
        }else{
            int val; cin >> val;
            rep(i, 0, 25) st[i].upd(l, r, val);
        }
    }
}
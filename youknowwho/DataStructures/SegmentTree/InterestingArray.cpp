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

struct SegOR{
    int n;
    vi t;
    SegOR(int nn) : n(nn), t(4 * nn + 10, 0) {}
    void upd(int v, int l, int r, int lq, int rq, int val){
        if(lq > r || l > rq) return;
        if(lq <= l && r <= rq){
            t[v] |= val;
            return;
        }
        int mid = l + r >> 1;
        upd(2 * v + 1, l, mid, lq, rq, val);
        upd(2 * v + 2, mid + 1, r, lq, rq, val);
    }
    void upd(int lq, int rq, int val){ upd(0, 0, n - 1, lq, rq, val); }

    int get(int v, int l, int r, int pos){
        if(pos < l || pos > r) return 0;
        if(l == r) return t[v];
        int mid = l + r >> 1;
        return (
            t[v] |
            get(2 * v + 1, l, mid, pos) |
            get(2 * v + 2, mid + 1, r, pos)
        );
    }
    int get(int pos){ return get(0, 0, n - 1, pos); }
};

struct SegAND{
    int n;
    vi t;
    void build(const vi &a, int v, int l, int r){
        if(l == r){
            t[v] = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(a, 2 * v + 1, l, mid);
        build(a, 2 * v + 2, mid + 1, r);
        t[v] = t[2 * v + 1] & t[2 * v + 2];
    }
    void init(const vi &a){
        n = sz(a);
        t.assign(4 * n + 10, (1 << 30) - 1);
        build(a, 0, 0, n - 1);
    }

    int query(int v, int l, int r, int lq, int rq){
        if(lq > r || l > rq) return (1 << 30) - 1;
        if(lq <= l && r <= rq) return t[v];
        int mid = l + r >> 1;
        return (
            query(2 * v + 1, l, mid, lq, rq) & 
            query(2 * v + 2, mid + 1, r, lq, rq)
        );
    }
    int query(int lq, int rq){ return query(0, 0, n - 1, lq, rq); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    SegOR st(n);
    vector<tuple<int, int, int>> ops;
    rep(i, 0, q){
        int l, r, val; cin >> l >> r >> val;
        l--; r--;
        ops.emplace_back(l, r, val);
        st.upd(l, r, val);
    }

    vi a(n);
    rep(i, 0, n) a[i] = st.get(i);

    SegAND ans;
    ans.init(a);
    for(auto [l, r, val] : ops){
        int ret = ans.query(l, r);
        if(ret != val){ cout << "NO\n"; return 0; }
    }
    cout << "YES\n";
    rep(i, 0, n) cout << a[i] << " ";
    cout << "\n";
}
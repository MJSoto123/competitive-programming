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

int get(int a){
    int ret = 0;
    for(int dv = 1; dv * dv <= a; dv++){
        if(a % dv == 0){
            ret++;
            int other = a / dv;
            if(other != dv) ret++;
        }
    }
    return ret;
}

struct Seg{
    int n;
    vl t;
    vi sm;
    void build(const vi &a, int v, int l, int r){
        if(l == r){
            t[v] = a[l];
            sm[v] = 0;
            return;
        }
        int mid = l + r >> 1;
        build(a, 2 * v + 1, l, mid);
        build(a, 2 * v + 2, mid + 1, r);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
        sm[v] = sm[2 * v + 1] + sm[2 * v + 2];
    }
    void init(const vi &a){
        n = sz(a);
        t.resize(4 * n + 10);
        sm.resize(4 * n + 10);
        build(a, 0, 0, n - 1);
    }

    void upd(int v, int l, int r, int lq, int rq){
        if(lq > r || l > rq) return;
        
        // ready
        if(sm[v] == r - l + 1) return;

        if(l == r){
            int old = t[v];
            int now = get(old);
            if(old == now) sm[v] = 1;

            t[v] = now;
            return;
        }

        int mid = l + r >> 1;
        upd(2 * v + 1, l, mid, lq, rq);
        upd(2 * v + 2, mid + 1, r, lq, rq);

        t[v] = t[2 * v + 1] + t[2 * v + 2];
        sm[v] = sm[2 * v + 1] + sm[2 * v + 2];
    }
    void upd(int lq, int rq){ upd(0, 0, n - 1, lq, rq); }

    ll query(int v, int l, int r, int lq, int rq){
        if(lq > r || l > rq) return 0;
        if(lq <= l && r <= rq) return t[v];
        int mid = l + r >> 1;
        return (
            query(2 * v + 1, l, mid, lq, rq) + 
            query(2 * v + 2, mid + 1, r, lq, rq)
        );
    }
    ll query(int lq, int rq){ return query(0, 0, n - 1, lq, rq); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    Seg st;
    st.init(a);
    
    rep(_, 0, q){
        int op; cin >> op;
        if(op == 1){
            int l, r; cin >> l >> r;
            l--; r--;
            st.upd(l, r);
        }else{
            int l, r; cin >> l >> r;
            l--; r--;
            cout << st.query(l, r) << "\n";
        }
    }
}
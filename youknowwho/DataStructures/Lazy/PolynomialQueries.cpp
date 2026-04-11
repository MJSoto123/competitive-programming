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

ll sm(ll x){
    return x * (x + 1) / 2;
}

struct Seg{
    int n;
    vl t, lz1, lz2;
    void build(const vi &a, int v, int l, int r){
        if(l == r){
            t[v] = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(a, 2 * v + 1, l, mid);
        build(a, 2 * v + 2, mid + 1, r);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
    void init(const vi &a){
        n = sz(a);
        t.resize(4 * n + 10);
        lz1.resize(4 * n + 10);
        lz2.resize(4 * n + 10);
        build(a, 0, 0, n - 1);
    }

    void push(int v, int l, int r){
        if(lz1[v] != 0){
            if(l != r){
                lz1[2 * v + 1] += lz1[v];
                lz1[2 * v + 2] += lz1[v];
            }
            t[v] += 1LL * (r - l + 1) * lz1[v];
            lz1[v] = 0;
        }

        if(lz2[v] != 0){
            if(l != r){
                lz2[2 * v + 1] += lz2[v];
                lz2[2 * v + 2] += lz2[v];
            }
            t[v] += 1LL * lz2[v] * (sm(r + 1) - sm(l - 1 + 1));
            lz2[v] = 0;
        }
    }

    void upd(int v, int l, int r, int lq, int rq, int fijo, int raz){
        push(v, l, r);
        if(lq > r || l > rq) return;
        if(lq <= l && r <= rq){
            lz1[v] += fijo;
            lz2[v] += raz;
            push(v, l, r);
            return;
        }
        int mid = l + r >> 1;
        upd(2 * v + 1, l, mid, lq, rq, fijo, raz);
        upd(2 * v + 1, mid + 1, r, lq, rq, fijo, raz);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
    void upd(int lq, int rq){ upd(0, 0, n - 1, lq, rq, -lq, 1); }

    ll query(int v, int l, int r, int lq, int rq){
        push(v, l, r);
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

    Seg st; st.init(a);

    rep(_, 0, q){
        int op, l, r; cin >> op >> l >> r;
        l--; r--;

        if(op == 1) st.upd(l, r);
        else cout << st.query(l, r) << "\n";
    }
}
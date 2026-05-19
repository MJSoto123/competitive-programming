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
    vl t, lz;
    Seg(int n): n(n), t(4 * n + 5), lz(4 * n + 5) {}

    void push(int v, int l, int r){
        if(lz[v] == 0) return;
        t[v] += lz[v] * (r - l + 1);

        if(l != r){
            lz[2 * v + 1] += lz[v];
            lz[2 * v + 2] += lz[v];
        }
        lz[v] = 0;
    }

    void upd(int v, int l, int r, int lq, int rq, ll val){
        push(v, l, r);
        if(r < lq || rq < l) return;
        if(lq <= l && r <= rq){
            lz[v] += val;
            push(v, l, r);
            return;
        }
        int mid = l + r >> 1;
        upd(2 * v + 1, l, mid, lq, rq, val);
        upd(2 * v + 2, mid + 1, r, lq, rq, val);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
    void upd(int lq, int rq, ll val){ upd(0, 0, n - 1, lq, rq, val); }


    ll query(int v, int l, int r, int lq, int rq){
        push(v, l, r);
        if(r < lq || rq < l) return 0;
        if(lq <= l && r <= rq) return t[v];
        int mid = l + r >> 1;
        return (
            query(2 * v + 1, l, mid, lq, rq) +
            query(2 * v + 2, mid + 1, r, lq, rq)
        );
    }
    ll query(int lq, int rq){ return query(0, 0, n - 1, lq, rq); }

    void print(){
        rep(i, 0, n) cerr << query(i, i) << " "; cerr << "\n\n";
    }
};

void solve(){
    int n, m; cin >> n >> m;
    Seg st(n);
    rep(i, 0, m){
        int op; cin >> op;
        if(op == 0){
            int l, r, val; cin >> l >> r >> val;
            l--; r--;
            st.upd(l, r, val);
        }else{
            int l, r; cin >> l >> r;
            l--; r--;
            cout << st.query(l, r) << "\n";
        }
        // st.print();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}
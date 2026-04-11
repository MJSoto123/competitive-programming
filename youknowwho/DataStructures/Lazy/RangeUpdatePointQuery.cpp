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

int get(int x){
    int ret = 0;
    while(x){
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

struct Seg{
    int n;
    vi t;
    Seg(int nn) : n(nn), t(4 * nn + 10) {}
    void upd(int v, int l, int r, int lq, int rq){
        if(lq > r || l > rq) return;
        if(lq <= l && r <= rq){
            t[v]++;
            return;
        }
        int mid = l + r >> 1;
        upd(2 * v + 1, l, mid, lq, rq);
        upd(2 * v + 2, mid + 1, r, lq, rq);
    }
    void upd(int lq, int rq){ upd(0, 0, n - 1, lq, rq); }

    int query(int v, int l, int r, int pos){
        if(pos < l || pos > r) return 0;
        if(l == r) return t[v];
        int mid = l + r >> 1;
        return t[v] + 
            query(2 * v + 1, l, mid, pos) + 
            query(2 * v + 2, mid + 1, r, pos);
    }
    int query(int pos){ return query(0, 0, n - 1, pos); }
};

void solve(){
    int n, q; cin >> n >> q;
    vvi a(10, vi(n));
    rep(i, 0, n) cin >> a[0][i];
    rep(i, 1, 10) rep(j, 0, n) a[i][j] = get(a[i - 1][j]);

    Seg st(n);
    rep(_, 0, q){
        int op; cin >> op;
        if(op == 1){
            int l, r; cin >> l >> r;
            l--; r--;
            st.upd(l, r);
        }else{
            int pos; cin >> pos;
            pos--;
            int lvl = min(9, st.query(pos));
            cout << a[lvl][pos] << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}
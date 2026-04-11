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
    vi t;
    Seg(int n) : n(n), t(4 * n + 10, 2e9) {}

    void upd(int v, int l, int r, int pos, int val){
        if(pos < l || r < pos) return;
        if(l == r){
            t[v] = val;
            return;
        }
        int mid = l + r >> 1;
        upd(2 * v + 1, l, mid, pos, val);
        upd(2 * v + 2, mid + 1, r, pos, val);
        t[v] = min(t[2 * v + 1], t[2 * v + 2]);
    }
    void upd(int pos, int val){ upd(0, 0, n - 1, pos, val); }

    int query(int v, int l, int r, int lq, int rq){
        if(l > rq || lq > r) return 2e9;
        if(lq <= l && r <= rq) return t[v];
        int mid = l + r >> 1;
        return min(
            query(2 * v + 1, l, mid, lq, rq),
            query(2 * v + 2, mid + 1, r, lq, rq)
        );
    }
    int query(int lq, int rq){ return query(0, 0, n - 1, lq, rq); }

    void print(){
        cout << "\nprinting: ";
        rep(i, 0, n) cout << query(i, i) << " "; cout << "\n";
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    Seg big(n), small(n);
    rep(i, 0, n) big.upd(i, a[i] - i);
    rep(i, 0, n) small.upd(i, a[i] + i);

    rep(i, 0, q){
        int op; cin >> op;
        if(op == 1){
            int pos, val; cin >> pos >> val;
            pos--;
            big.upd(pos, val - pos);
            small.upd(pos, val + pos);
        }else{
            int pos; cin >> pos; pos--;
            cout << min(pos + big.query(0, pos), -pos + small.query(pos, n - 1)) << "\n";
        }
    }
}
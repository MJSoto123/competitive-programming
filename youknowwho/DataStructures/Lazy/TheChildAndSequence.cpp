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

struct Node{
    ll sm, mx;
    Node(int val = 0) : sm(val), mx(val) {}
    Node operator+(const Node &other) const {
        Node ret;
        ret.sm = sm + other.sm;
        ret.mx = max(mx, other.mx);
        return ret;
    }
};

Node NIL;
struct Seg{
    int n; 
    vector<Node> t;
    void build(const vi &a, int v, int l, int r){
        if(l == r){
            t[v] = Node(a[l]);
            return;
        }
        int mid = l + r >> 1;
        build(a, 2 * v + 1, l, mid);
        build(a, 2 * v + 2, mid + 1, r);
        t[v] = t[2 * v + 1] + t[2 * v + 2]; 
    }

    void init(const vi &a){
        n = sz(a);
        t.assign(4 * n + 10, NIL);
        build(a, 0, 0, n - 1);
    }

    void updmod(int v, int l, int r, int lq, int rq, int mod){
        if(lq > r || l > rq) return;
        if(t[v].mx < mod) return;
        if(l == r){
            t[v].sm %= mod;
            t[v].mx %= mod;
            return;
        }
        int mid = l + r >> 1;
        updmod(2 * v + 1, l, mid, lq, rq, mod);
        updmod(2 * v + 2, mid + 1, r, lq, rq, mod);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
    void updmod(int lq, int rq, int mod){ updmod(0, 0, n - 1, lq, rq, mod); }

    void upd(int v, int l, int r, int pos, int val){
        if(pos < l || pos > r) return;
        if(l == r){
            t[v] = Node(val);
            return;
        }
        int mid = l + r >> 1;
        upd(2 * v + 1, l, mid, pos, val);
        upd(2 * v + 2, mid + 1, r, pos, val);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
    void upd(int pos, int val){ upd(0, 0, n -1, pos, val); }

    Node query(int v, int l, int r, int lq, int rq){
        if(lq > r || l > rq) return NIL;
        if(lq <= l && r <= rq) return t[v];
        int mid = l + r >> 1;
        return (
            query(2 * v + 1, l, mid, lq, rq) + 
            query(2 * v + 2, mid + 1, r, lq, rq)
        );
    }
    Node query(int lq, int rq){ return query(0, 0, n - 1, lq, rq); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    Seg st; st.init(a);
    rep(_, 0, q){
        int op; cin >> op;
        if(op == 1){
            int l, r; cin >> l >> r;
            l--; r--;
            cout << st.query(l, r).sm << "\n";
        }else if(op == 2){
            int l, r, mod; cin >> l >> r >> mod;
            l--; r--;
            st.updmod(l, r, mod);
        }else{
            int pos, val; cin >> pos >> val;
            pos--;
            st.upd(pos, val);
        }
    }
}
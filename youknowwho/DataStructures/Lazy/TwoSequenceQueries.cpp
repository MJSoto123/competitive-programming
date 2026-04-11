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

const int MOD = 998244353;
int add(int a, int b){ return (a + b) % MOD; }
int mul(int a, int b){ return 1LL * a * b % MOD; }

struct Node{
    int sma, smb, ans;
    Node() : sma(0), smb(0), ans(0) {}
    Node(int a, int b) : sma(a), smb(b), ans(mul(a, b)) {}
    Node(int a, int b, int c) : sma(a), smb(b), ans(c) {}
    Node operator+(const Node &other) const {
        Node ret(0, 0, 0);
        ret.sma = add(sma, other.sma);
        ret.smb = add(smb, other.smb);
        ret.ans = add(ans, other.ans);
        return ret;
    }
};

Node NIL(0, 0, 0);
struct Seg{
    int n;
    vector<Node> t;
    vi lza, lzb;
    void build(const vi &a, const vi &b, int v, int l, int r){
        if(l == r){
            t[v] = Node(a[l], b[l]);
            return;
        }
        int mid = l + r >> 1;
        build(a, b, 2 * v + 1, l, mid);
        build(a, b, 2 * v + 2, mid + 1, r);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
    void init(const vi &a, const vi &b){
        n = sz(a);
        t.assign(4 * n + 10, NIL);
        lza.assign(4 * n + 10, 0);
        lzb.assign(4 * n + 10, 0);
        build(a, b, 0, 0, n - 1);
    }

    void push(int v, int l, int r){
        if(lza[v]){
            if(l != r){
                lza[2 * v + 1] = add(lza[2 * v + 1], lza[v]);
                lza[2 * v + 2] = add(lza[2 * v + 2], lza[v]);
            }
            t[v].sma = add(t[v].sma, mul(lza[v], (r - l + 1)));
            t[v].ans = add(t[v].ans, mul(lza[v], t[v].smb));
            lza[v] = 0;
        }

        if(lzb[v]){
            if(l != r){
                lzb[2 * v + 1] = add(lzb[2 * v + 1], lzb[v]);
                lzb[2 * v + 2] = add(lzb[2 * v + 2], lzb[v]);
            }
            t[v].smb = add(t[v].smb, mul(lzb[v], (r - l + 1)));
            t[v].ans = add(t[v].ans, mul(lzb[v], t[v].sma));
            lzb[v] = 0;
        }
    }

    void upd(int v, int l, int r, int op, int lq, int rq, ll val){
        push(v, l, r);
        if(lq > r || l > rq) return;
        if(lq <= l && r <= rq){
            if(op == 0) lza[v] = add(lza[v], val);
            else lzb[v] = add(lzb[v], val);
            push(v, l, r);
            return;
        }
        int mid = l + r >> 1;
        upd(2 * v + 1, l, mid, op, lq, rq, val);
        upd(2 * v + 2, mid + 1, r, op, lq, rq, val);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
    void upd(int op, int lq, int rq, ll val){ upd(0, 0, n - 1, op, lq, rq, val); }

    ll query(int v, int l, int r, int lq, int rq){
        push(v, l, r);
        if(lq > r || l > rq) return 0;
        if(lq <= l && r <= rq) return t[v].ans;
        int mid = l + r >> 1;
        return add(
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
    vi a(n), b(n), c(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    Seg st; st.init(a, b);
    rep(_, 0, q){
        int op, l, r; cin >> op >> l >> r;
        l--; r--;
        if(op == 1){
            int val; cin >> val;
            st.upd(0, l, r, val);
        }
        if(op == 2){
            int val; cin >> val;
            st.upd(1, l, r, val);
        }
        if(op == 3) cout << st.query(l, r) << "\n";
    }
}
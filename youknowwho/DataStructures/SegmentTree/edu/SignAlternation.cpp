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

const ll VIL = 0;
struct Node{
    ll sm;
    Node(ll v = VIL) : sm(v) {}
    Node operator+(const Node &other) const {
        return Node(sm + other.sm);
    }
};

Node NIL;
struct SegmentTree{
    int n;
    vector<Node> t;
    void build(const vi &a, int node, int l, int r){
        if(l == r){
            t[node] = Node(a[l]);
            return;
        };
        int mid = l + r >> 1;
        build(a, 2 * node + 1, l, mid);
        build(a, 2 * node + 2, mid + 1, r);
        t[node] = t[2 * node + 1] + t[2 * node + 2];
    }
    void init(const vi &a){
        n = sz(a);
        t.assign(4 * n + 10, NIL);
        build(a, 0, 0, n - 1);
    }

    void setPointUpdate(int node, int l, int r, int pos, int val){
        if(pos < l || r < pos) return;
        if(l == r){
            t[node] = Node(val);
            return;
        }

        int mid = l + r >> 1;
        setPointUpdate(2 * node + 1, l, mid, pos, val);
        setPointUpdate(2 * node + 2, mid + 1, r, pos, val);
        t[node] = t[2 * node + 1] + t[2 * node + 2];
    }
    void setPointUpdate(int pos, int val){ setPointUpdate(0, 0, n - 1, pos, val); }

    Node rangeQuery(int node, int l, int r, int lq, int rq){
        if(lq > r || rq < l) return NIL;
        if(lq <= l && r <= rq) return t[node];

        int mid = l + r >> 1;
        return rangeQuery(2 * node + 1, l, mid, lq, rq) + 
               rangeQuery(2 * node + 2, mid + 1, r, lq, rq);
    }
    Node rangeQuery(int lq, int rq){ return rangeQuery(0, 0, n - 1, lq, rq); }
};

void print(SegmentTree a, int n){
    rep(i, 0, n) cerr << a.rangeQuery(i, i).sm << " "; 
    cerr << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    vi b = a, c = a;
    rep(i, 0, n){
        if(i % 2 == 0) c[i] = -a[i];
        else b[i] = -a[i]; 
    }

    SegmentTree even, odd;
    even.init(b);
    odd.init(c); 

    int q; cin >> q;
    rep(_, 0, q){
        int op; cin >> op;
        if(op == 0){
            int pos, val; cin >> pos >> val;
            pos--;
            if(pos % 2 == 0){
                even.setPointUpdate(pos, val);
                odd.setPointUpdate(pos, -val);
            }else{
                even.setPointUpdate(pos, -val);
                odd.setPointUpdate(pos, val);
            }
        }else{
            int l, r; cin >> l >> r;
            l--; r--;
            ll ans = 0;
            if(l % 2 == 0) ans = even.rangeQuery(l, r).sm;
            else ans = odd.rangeQuery(l, r).sm;
            cout << ans << "\n";
        }
    }
}
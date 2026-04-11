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

const int VIL = 0;
struct Node{
    vi cnt;
    int ans;
    Node() : cnt(41, 0), ans(0) {}
    Node(int v) : cnt(41, 0), ans(0) { cnt[v] = 1; ans = 1; }
    Node operator+(const Node &other) const {
        Node ret;
        rep(i, 0, 41) ret.cnt[i] = cnt[i] + other.cnt[i];
        rep(i, 0, 41) ret.ans += (ret.cnt[i] != 0);
        return ret;
    }
};

Node NIL;
struct SegmentTree{
    int n;
    vector<Node> t;
    void build(const vi &a, int node, int l, int r){
        if(l == r){
            t[node] = a[l];
            return; 
        }
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
        if(pos < l || pos > r) return;
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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    SegmentTree st;
    st.init(a);

    rep(_, 0, q){
        int op; cin >> op;
        if(op == 1){
            int l, r; cin >> l >> r; 
            l--; r--;
            cout << st.rangeQuery(l, r).ans << "\n";
        }else{
            int pos, val; cin >> pos >> val;
            pos--;
            st.setPointUpdate(pos, val);
        }
    }
}
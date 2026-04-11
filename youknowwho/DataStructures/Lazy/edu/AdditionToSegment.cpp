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
    ll sm = 0;
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

    void addRangeUpdate(int node, int l, int r, int lq, int rq, int val){
        if(lq > r || rq < l) return;
        if(lq <= l && r <= rq){
            t[node] = t[node] + Node(val);
            return;
        }
        int mid = l + r >> 1;
        addRangeUpdate(2 * node + 1, l, mid, lq, rq, val);
        addRangeUpdate(2 * node + 2, mid + 1, r, lq, rq, val);
    }
    void addRangeUpdate(int lq, int rq, int val){ addRangeUpdate(0, 0, n - 1, lq, rq, val); }

    Node pointQuery(int node, int l, int r, int pos){
        if(pos < l || pos > r) return NIL;
        if(l == r) return t[node];

        int mid = l + r >> 1;
        return t[node] + pointQuery(2 * node + 1, l, mid, pos) +
               pointQuery(2 * node + 2, mid + 1, r, pos);
    }
    Node pointQuery(int pos){ return pointQuery(0, 0, n - 1, pos); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vi a(n);
    SegmentTree st;
    st.init(a);

    rep(_, 0, q){
        int op; cin >> op;
        if(op == 1){
            int l, r, val; cin >> l >> r >> val;
            r--;
            st.addRangeUpdate(l, r, val);
        }else{
            int pos; cin >> pos;
            cout << st.pointQuery(pos).sm << "\n";
        }
    }
}
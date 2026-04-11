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
    SegmentTree(int nn) : n(nn), t(4 * nn + 10) {}

    void addRangeUpdate(int node, int l, int r, int lq, int rq, ll val){
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

    ll pointQuery(int node, int l, int r, int pos){
        if(pos < l || pos > r) return 0LL;
        if(l == r) return t[node].sm; 

        int mid = l + r >> 1;
        return t[node].sm +
        pointQuery(2 * node + 1, l, mid, pos) +
        pointQuery(2 * node + 2, mid + 1, r, pos);
    }
    ll pointQuery(int pos){ return pointQuery(0, 0, n - 1, pos); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    SegmentTree st(n);

    rep(_, 0, m){
        int op; cin >> op;
        if(op == 1){
            int l, r, v; cin >> l >> r >> v;
            st.addRangeUpdate(l, r - 1, v);
        }else{
            int pos; cin >> pos;
            cout << st.pointQuery(pos) << "\n";
        }
    }
}
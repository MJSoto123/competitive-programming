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

const int VIL = -1;
struct Node{
    int val;
    Node(int v = -1) : val(v) {}
};

Node NIL;
struct SegmentTree{
    int n;
    vector<Node> t;
    SegmentTree(int nn) : n(nn), t(4 * nn + 10, NIL) {}

    void push(int node, int l, int r){
        if(l == r) return;
        if(t[node].val == -1) return;
        t[2 * node + 1] = t[node];
        t[2 * node + 2] = t[node];
        t[node] = NIL;
    }

    void rangeUpdate(int node, int l, int r, int lq, int rq, int val){
        if(lq > r || rq < l) return;
        push(node, l, r);

        if(lq <= l && r <= rq){
            t[node] = Node(val);
            return;
        }

        int mid = l + r >> 1;
        rangeUpdate(2 * node + 1, l, mid, lq, rq, val);
        rangeUpdate(2 * node + 2, mid + 1, r, lq, rq, val);
    }
    void rangeUpdate(int lq, int rq, int val){ rangeUpdate(0, 0, n - 1, lq, rq, val); }

    int pointQuery(int node, int l, int r, int pos){
        if(l == r) return t[node].val;
        push(node, l, r);

        int mid = l + r >> 1;
        if(pos <= mid) return pointQuery(2 * node + 1, l, mid, pos);
        return pointQuery(2 * node + 2, mid + 1, r, pos);
    }
    int pointQuery(int pos){ return pointQuery(0, 0, n - 1, pos); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    SegmentTree st(n);
    rep(i, 0, n) st.rangeUpdate(i, i, 0);

    rep(_, 0, q){
        int op; cin >> op;
        if(op == 1){
            int l, r, val; cin >> l >> r >> val;
            r--;
            st.rangeUpdate(l, r, val);
        }else{
            int pos; cin >> pos;
            cout << st.pointQuery(pos) << "\n";
        }
    }
}
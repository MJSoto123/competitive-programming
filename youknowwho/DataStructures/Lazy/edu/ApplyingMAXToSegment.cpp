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
    int val;
    Node(int v = VIL) : val(v) {}
    Node operator+(const Node &other) const {
        return Node(max(val, other.val));
    }
};

Node NIL;
struct SegmentTree{
    int n;
    vector<Node> t;
    SegmentTree(int nn) : n(nn), t(4 * nn + 10) {}
    void rangeUpdate(int node, int l, int r, int lq, int rq, int val){
        if(lq > r || l > rq) return;
        if(lq <= l && r <= rq){
            t[node] = Node(val) + t[node];
            return;
        }

        int mid = l + r >> 1;
        rangeUpdate(2 * node + 1, l, mid, lq, rq, val);
        rangeUpdate(2 * node + 2, mid + 1, r, lq, rq, val);
    }
    void rangeUpdate(int lq, int rq, int val){ rangeUpdate(0, 0, n - 1, lq, rq, val); }

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
    SegmentTree st(n);
    rep(_, 0, q){
        int op; cin >> op;
        if(op == 1){
            int l, r, val; cin >> l >> r >> val;
            r--;
            st.rangeUpdate(l, r, val);
        }else{
            int pos; cin >> pos;
            cout << st.pointQuery(pos).val << "\n";
        }
    }
}
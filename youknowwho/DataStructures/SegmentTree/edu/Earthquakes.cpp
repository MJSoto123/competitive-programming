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

const int VIL = 2e9;
struct Node{
    int mn;
    Node(int v = VIL) : mn(v){}
    Node operator+(const Node &other) const {
        return Node(min(mn, other.mn));
    }
};

Node NIL;
struct SegmentTree{
    int n;
    vector<Node> t;
    SegmentTree(int nn) : n(nn), t(4 * nn + 10) {}

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

    int rangeQuery(int node, int l, int r, int lq, int rq, int val){
        if(lq > r || rq < l) return 0;
        if(t[node].mn > val) return 0;
        if(l == r){
            if(t[node].mn <= val){
                t[node] = NIL;
                return 1;
            }
            return 0;
        }

        int mid = l + r >> 1;
        int ans = rangeQuery(2 * node + 1, l, mid, lq, rq, val) + 
                  rangeQuery(2 * node + 2, mid + 1, r, lq, rq, val);

        t[node] = t[2 * node + 1] + t[2 * node + 2];
        return ans;
    }
    int rangeQuery(int lq, int rq, int val){ return rangeQuery(0, 0, n - 1, lq, rq, val); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    SegmentTree st(n);
    vi a(n);

    rep(_, 0, q){
        int op; cin >> op;
        if(op == 1){
            int pos, val; cin >> pos >> val;
            st.setPointUpdate(pos, val);
        }else{
            int l, r, val; cin >> l >> r >> val;
            cout << st.rangeQuery(l, r - 1, val) << "\n";
        }
    }
}
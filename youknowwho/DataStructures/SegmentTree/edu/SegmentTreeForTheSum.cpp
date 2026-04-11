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

ll VIL = 0;
struct Node{
    ll val;
    Node(ll v = VIL) : val(v){};

    Node operator+(const Node &other) const {
        return Node(val + other.val);
    }
};

Node NIL;

// 0-index
// query [l, r]
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
        t.assign(n * 4 + 10, NIL);
        build(a, 0, 0, n - 1);
    }

    void setPointUpdate(int node, int l, int r, int pos, int val){
        if(l == r){
            t[node] = Node(val);
            return;
        }

        int mid = l + r >> 1;
        if(pos <= mid) setPointUpdate(2 * node + 1, l, mid, pos, val);
        else setPointUpdate(2 * node + 2, mid + 1, r, pos, val);

        t[node] = t[node * 2 + 1] + t[node * 2 + 2];
    }
    void setPointUpdate(int pos, int val){ setPointUpdate(0, 0, n - 1, pos, val); }

    
    Node rangeQuery(int node, int l, int r, int lquery, int rquery){
        if(l >= lquery && r <= rquery) return t[node];
        Node ret = NIL;
        int mid = l + r >> 1;
        if(lquery <= mid) ret = ret + rangeQuery(2 * node + 1, l, mid, lquery, rquery);
        if(rquery >= mid + 1) ret = ret + rangeQuery(2 * node + 2, mid + 1, r, lquery, rquery);
        return ret;
    }
    Node rangeQuery(int lquery, int rquery){ return rangeQuery(0, 0, n - 1, lquery, rquery); }
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
            int pos, val; cin >> pos >> val;
            st.setPointUpdate(pos, val);
        }else{
            int l, r; cin >> l >> r;
            auto ret = st.rangeQuery(l, r - 1);
            cout << ret.val << "\n";
        }
    }
}
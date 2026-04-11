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


// set VIL
// set operator
ll VIL = 0;
struct Node{
    ll pre, suf, sum, ans;
    Node(ll v = VIL) : pre(max(0LL, v)), suf(max(0LL, v)), sum(v), ans(max(0LL, v)) {};

    Node operator+(const Node &other) const {
        Node ret;
        ret.pre = max(pre, sum + other.pre);
        ret.suf = max(other.suf, suf + other.sum);
        ret.sum = sum + other.sum;
        ret.ans = max({
            0LL,
            ans,
            other.ans,
            suf + other.pre
        });
        return ret;
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
        if(pos < l || pos > r) return;
        if(l == r){
            // constructor
            t[node] = Node(val);
            return;
        }

        int mid = l + r >> 1;
        setPointUpdate(2 * node + 1, l, mid, pos, val);
        setPointUpdate(2 * node + 2, mid + 1, r, pos, val);
        t[node] = t[node * 2 + 1] + t[node * 2 + 2];
    }
    void setPointUpdate(int pos, int val){ setPointUpdate(0, 0, n - 1, pos, val); }

    
    Node rangeQuery(int node, int l, int r, int lquery, int rquery){
        if(r < lquery || l > rquery) return NIL;
        if(l >= lquery && r <= rquery) return t[node];

        int mid = l + r >> 1;
        return rangeQuery(2 * node + 1, l, mid, lquery, rquery)
            +  rangeQuery(2 * node + 2, mid + 1, r, lquery, rquery);
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

    auto ret = st.rangeQuery(0, n - 1);
    cout << ret.ans << "\n";
    rep(_, 0, q){
        int pos, val; cin >> pos >> val;
        st.setPointUpdate(pos, val);
        auto ret = st.rangeQuery(0, n - 1);
        cout << ret.ans << "\n";
    }
}
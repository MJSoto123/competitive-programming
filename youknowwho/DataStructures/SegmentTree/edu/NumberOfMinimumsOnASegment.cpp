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
int VIL = 2'000'000'000;
struct Node{
    int mn, cnt;
    Node(int v = VIL, int cnt = 1) : mn(v), cnt(1) {};

    Node operator+(const Node &other) const {
        Node ret;
        if(mn == other.mn){ 
            ret.mn = mn;
            ret.cnt = cnt + other.cnt;
        }
        else if(mn < other.mn) ret = *this;
        else ret = other;

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

    rep(_, 0, q){
        int op; cin >> op;
        if(op == 1){
            int pos, val; cin >> pos >> val;
            st.setPointUpdate(pos, val);
        }else{
            int l, r; cin >> l >> r;
            auto ret = st.rangeQuery(l, r - 1);
            cout << ret.mn << " " << ret.cnt << "\n";
        }
    }
}
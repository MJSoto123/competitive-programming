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

const int VIL = -100;
struct Node{
    int mx;
    Node(int v = VIL) : mx(v) {}
    Node operator+(const Node &other) const{
        return Node(max(mx, other.mx));
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
        if(l >= lq && r <= rq) return t[node];

        int mid = l + r >> 1;
        return rangeQuery(2 * node + 1, l, mid, lq, rq) + 
               rangeQuery(2 * node + 2, mid + 1, r, lq, rq);
    }
    Node rangeQuery(int lq, int rq){ return rangeQuery(0, 0, n - 1, lq, rq); }


    int treeDescend(int node, int l, int r, int val){
        if(t[node].mx < val) return -1;
        if(l == r) return l;
        
        int mid = l + r >> 1;
        int ans = treeDescend(2 * node + 1, l, mid, val);
        if(ans == -1) ans = treeDescend(2 * node + 2, mid + 1, r, val);
        return ans;
    }
    int treeDescend(int val){ return treeDescend(0, 0, n - 1, val); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    SegmentTree st;
    st.init(a);

    rep(i, 0, q){
        int op; cin >> op;
        if(op == 1){
            int pos, val; cin >> pos >> val;
            st.setPointUpdate(pos, val);
        }else{
            int val; cin >> val;
            cout << st.treeDescend(val) << "\n";
        }
    }
}
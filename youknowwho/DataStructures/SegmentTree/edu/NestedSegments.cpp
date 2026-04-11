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
    int sm;
    Node(int v = VIL) : sm(v) {}
    Node operator+(const Node &other) const {
        return Node(sm + other.sm);
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

    Node rangeQuery(int node, int l, int r, int lq, int rq){
        if(lq > r || rq < l) return NIL;
        if(l >= lq && r <= rq) return t[node];

        int mid = l + r >> 1;
        return rangeQuery(2 * node + 1, l, mid, lq, rq) + 
               rangeQuery(2 * node + 2, mid + 1, r, lq, rq);
    }
    Node rangeQuery(int lq, int rq){ return rangeQuery(0, 0, n - 1, lq, rq); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vi fi(n, -1), se(n, -1);
    vi a(2 * n);
    rep(i, 0, 2 * n){
        cin >> a[i];
        a[i]--;
        if(fi[a[i]] == -1) fi[a[i]] = i;
        se[a[i]] = i;
    }

    SegmentTree st(2 * n);

    vi ans(n);
    rep(i, 0, 2 * n){
        if(se[a[i]] == i){
            ans[a[i]] = st.rangeQuery(fi[a[i]], se[a[i]]).sm;
            st.setPointUpdate(fi[a[i]], 1);
        }
    }

    rep(i, 0, n) cout << ans[i] << " ";
    cout << "\n";
}
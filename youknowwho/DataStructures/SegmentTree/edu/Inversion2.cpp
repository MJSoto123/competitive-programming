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

    int treeDescend(int node, int l, int r, int kth){
        if(l == r) return l;
        int mid = l + r >> 1;
        int ansl = t[2 * node + 1].sm;

        if(ansl >= kth) return treeDescend(2 * node + 1, l, mid, kth);
        else return treeDescend(2 * node + 2, mid + 1, r, kth - ansl);
    }
    int treeDescend(int kth){ return treeDescend(0, 0, n - 1, kth); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    vi b(n, 1);
    SegmentTree st;
    st.init(b);

    vi ans(n);
    for(int i = n - 1; i >= 0; i--){
        ans[i] = st.treeDescend(i + 1 - a[i]);
        st.setPointUpdate(ans[i], 0);
    }

    rep(i, 0, n) cout << ans[i] + 1 << " ";
    cout << "\n";
}
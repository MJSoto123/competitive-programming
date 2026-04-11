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
typedef array<array<int, 2>, 2> M;

int mod;
M id;
void init(M &a){ rep(i, 0, 2) rep(j, 0, 2) a[i][j] = 0; }
int add(int a, int b){ return (a + b) % mod; }
int mul(int a, int b){ return 1LL * a * b % mod; }
M matmul(const M &a, const M &b){
    M c; init(c);
    rep(i, 0, 2) rep(k, 0, 2) rep(j, 0, 2) c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
    return c;
}

struct Node{
    M mat;
    Node(M v = id) : mat(v) {};
    Node operator*(const Node &other) const {
        return Node(matmul(mat, other.mat));
    }
};

Node NIL;
struct SegmentTree{
    int n;
    vector<Node> t;
    void build(const vector<M> &a, int node, int l, int r){
        if(l == r){
            t[node] = Node(a[l]);
            return;
        }

        int mid = l + r >> 1;
        build(a, 2 * node + 1, l, mid);
        build(a, 2 * node + 2, mid + 1, r);
        t[node] = t[2 * node + 1] * t[2 * node + 2];
    }
    void init(const vector<M> &a){
        n = sz(a);
        t.assign(4 * n + 10, NIL);
        build(a, 0, 0, n - 1);
    }

    Node rangeQuery(int node, int l, int r, int lq, int rq){
        if(lq > r || rq < l) return NIL;
        if(lq <= l && r <= rq) return t[node];
        int mid = l + r >> 1;
        return rangeQuery(2 * node + 1, l, mid, lq, rq) * 
               rangeQuery(2 * node + 2, mid + 1, r, lq, rq);
    }
    Node rangeQuery(int lq, int rq){ return rangeQuery(0, 0, n - 1, lq, rq); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init(id);
    id[0][0] = 1;
    id[1][1] = 1;

    NIL = Node(id);


    int n, m; cin >> mod >> n >> m;
    vector<M> a(n);
    rep(i, 0, n) rep(j, 0, 2) rep(k, 0, 2) cin >> a[i][j][k];

    SegmentTree st;
    st.init(a);

    rep(_, 0, m){
        int l, r; cin >> l >> r;
        l--; r--;
        auto ret = st.rangeQuery(l, r).mat;
        rep(i, 0, 2){
            rep(j, 0, 2) cout << ret[i][j] << " ";
            cout << "\n";
        }
        cout << "\n";
    }
}
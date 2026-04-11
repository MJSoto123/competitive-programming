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

const ll inf = -2e18;
struct Node{
    ll ans, pre, suf, sum;
    Node() : ans(inf), pre(inf), suf(inf), sum(0) {}
    Node(ll val) : ans(val), pre(val), suf(val), sum(val) {}
    Node operator+(const Node &other){
        Node ret(0);
        ret.sum = sum + other.sum;
        ret.pre = max(pre, sum + other.pre);
        ret.suf = max(suf + other.sum, other.suf);
        ret.ans = max({
            ans, 
            other.ans,
            suf + other.pre
        });
        return ret;
    }
};

Node NIL;
struct Seg{
    int n;
    vector<Node> t;
    void build(const vi &a, int v, int l, int r){
        if(l == r){
            t[v] = Node(a[l]);
            return;
        }
        int mid = l + r >> 1;
        build(a, 2 * v + 1, l, mid);
        build(a, 2 * v + 2, mid + 1, r);
        t[v] = t[2 * v + 1] +  t[2 * v + 2]; 
    }

    void init(const vi &a){
        n = sz(a);
        t.assign(4 * n + 10, NIL);
        build(a, 0, 0, n - 1);
    }

    void upd(int v, int l, int r, int pos, ll val){
        if(pos < l || pos > r) return;
        if(l == r){
            t[v] = Node(t[v].ans + val);
            return;
        }
        int mid = l + r >> 1;
        upd(2 * v + 1, l, mid, pos, val);
        upd(2 * v + 2, mid + 1, r, pos, val);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
    void upd(int pos, ll val){ upd(0, 0, n - 1, pos, val); }

    Node query(int v, int l, int r, int lq, int rq){
        if(lq > r || l > rq) return NIL;
        if(lq <= l && r <= rq) return t[v];
        int mid = l + r >> 1;
        return (
            query(2 * v + 1, l, mid, lq, rq) + 
            query(2 * v + 2, mid + 1, r, lq, rq)
        );
    }
    Node query(int lq, int rq){ return query(0, 0, n - 1, lq, rq); }
};

void solve(){
    int n, k; cin >> n >> k;
    k %= 2;
    vi a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    Seg st;
    st.init(a);

    auto ret = st.query(0, n - 1); 
    ll ans = ret.ans;
    if(k % 2 == 0){ cout << ans << "\n"; return; }
    rep(i, 0, n){
        st.upd(i, +b[i]);
        auto ret = st.query(0, n - 1);
        ans = max(ans, ret.ans);
        st.upd(i, -b[i]);
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt; 
    while(tt--) solve();   
}
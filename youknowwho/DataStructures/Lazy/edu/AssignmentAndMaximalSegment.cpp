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

struct Node{
    ll ans, pre, suf, sum;
    Node(ll ans = 0, ll pre = 0, ll suf = 0, ll sum = 0) : ans(ans), pre(pre), suf(suf), sum(sum) {}
    Node operator+(const Node &other) const {
        Node ret;
        ret.pre = max(pre, sum + other.pre);
        ret.suf = max(suf + other.sum, other.suf);
        ret.sum = sum + other.sum;
        ret.ans = max({ans, other.ans, suf + other.pre});
        return ret;
    }
};

const ll NL = 5e18;
Node NIL(0, -NL, -NL, 0);
struct SegmentTree{
    int n;
    vector<Node> t;
    vl lz;
    SegmentTree(int nn) : n(nn), t(4 * nn + 10, NIL), lz(4 * nn + 10, NL) {}

    void push(int node, int l, int r){
        if(lz[node] == NL) return;
        if(l != r){
            lz[2 * node + 1] = lz[node];
            lz[2 * node + 2] = lz[node];
        }
        ll sm = lz[node] * (r - l + 1);
        ll best = max(sm, 0LL);
        t[node] = Node(best, best, best, sm);
        lz[node] = NL;
    }

    void rangeUpdate(int node, int l, int r, int lq, int rq, ll val){
        push(node, l, r);
        if(lq > r || rq < l) return;
        if(lq <= l && r <= rq){
            lz[node] = val;
            push(node, l, r);
            return;
        }
        int mid = l + r >> 1;
        rangeUpdate(2 * node + 1, l, mid, lq, rq, val);
        rangeUpdate(2 * node + 2, mid + 1, r, lq, rq, val);
        t[node] = t[2 * node + 1] + t[2 * node + 2];
    }
    void rangeUpdate(int lq, int rq, ll val){ rangeUpdate(0, 0, n - 1, lq, rq, val); }

    Node rangeQuery(int node, int l, int r, int lq, int rq){
        push(node, l, r);
        if(lq > r || rq < l) return NIL;
        if(lq <= l && r <= rq) return t[node];
        int mid = l + r >> 1;
        return (
            rangeQuery(2 * node + 1, l, mid, lq, rq) +
            rangeQuery(2 * node + 2, mid + 1, r, lq, rq)
        );
    }
    Node rangeQuery(int lq, int rq){ return rangeQuery(0, 0, n - 1, lq, rq); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    SegmentTree st(n);

    rep(_, 0, q){
        int l, r, val; cin >> l >> r >> val;
        r--;
        st.rangeUpdate(l, r, val);
        cout << st.rangeQuery(0, n - 1).ans << "\n";
    }
}
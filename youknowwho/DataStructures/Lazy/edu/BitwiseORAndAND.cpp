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

struct SegmentTree{
    int n;
    vl t, lz;
    SegmentTree(int nn) : n(nn), t(4 * nn + 10, 0), lz(4 * nn + 10, 0) {}

    void push(int node, int l, int r){
        if(lz[node] == 0) return;
        if(l != r){
            lz[2 * node + 1] |= lz[node];
            lz[2 * node + 2] |= lz[node];
        }
        t[node] |= lz[node];
        lz[node] = 0;
    }

    void rangeUpdate(int node, int l, int r, int lq, int rq, int val){
        push(node, l, r);
        if(lq > r || rq < l) return;
        if(lq <= l && r <= rq){
            lz[node] |= val;
            push(node, l, r);
            return;
        }
        int mid = l + r >> 1;
        rangeUpdate(2 * node + 1, l, mid, lq, rq, val);
        rangeUpdate(2 * node + 2, mid + 1, r, lq, rq, val);
        t[node] = t[2 * node + 1] & t[2 * node + 2];
    } 
    void rangeUpdate(int lq, int rq, int val){ rangeUpdate(0, 0, n - 1, lq, rq, val); }

    int rangeQuery(int node, int l, int r, int lq, int rq){
        push(node, l, r);
        if(lq > r || rq < l) return (1LL << 30) - 1;
        if(lq <= l && r <= rq) return t[node];
        int mid = l + r >> 1;
        return (
            rangeQuery(2 * node + 1, l, mid, lq, rq) &
            rangeQuery(2 * node + 2, mid + 1, r, lq, rq)
        );
    }
    int rangeQuery(int lq, int rq){ return rangeQuery(0, 0, n - 1, lq, rq); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    SegmentTree st(n);

    rep(_, 0, q){
        int op; cin >> op;
        if(op == 1){
            int l, r, val; cin >> l >> r >> val;
            r--;
            st.rangeUpdate(l, r, val);
        }else{
            int l, r; cin >> l >> r;
            r--;
            cout << st.rangeQuery(l, r) << "\n";
        }
    }
}
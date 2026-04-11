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
    vl sm;
    SegmentTree(int nn) : n(nn), t(4 * nn + 10, 0), sm(4 * nn + 10, 0), lz(4 * nn + 10, 0) {}
    void push(int node, int l, int r){
        int mid = l + r >> 1;
        if(lz[node] != 0){
            if(l != r){
                lz[2 * node + 1] += lz[node];
                lz[2 * node + 2] += lz[node];
            }
            t[node] += (1LL * (l + r) * (r - l + 1) / 2) * lz[node];
            sm[node] += 1LL * (r - l + 1) * lz[node];
            lz[node] = 0;
        }
    }
    void rangeUpdate(int node, int l, int r, int lq, int rq, ll a, ll d){
        push(node, l, r);
        if(lq > r || rq < l) return;
        if(lq <= l && r <= rq){
            lz[node] += d;
            push(node, l, r);
            return;
        }
        
        int mid = l + r >> 1;
        rangeUpdate(2 * node + 1, l, mid, lq, rq, a, d);
        rangeUpdate(2 * node + 2, mid + 1, r, lq, rq, a, d);
        t[node] = t[2 * node + 1] + t[2 * node + 2];
        sm[node] = sm[2 * node + 1] + sm[2 * node + 2];
    }
    void rangeUpdate(int lq, int rq, ll a, ll d){ rangeUpdate(0, 0, n - 1, lq, rq, a, d); }

    ll rangeQuery(int node, int l, int r, int lq, int rq){
        push(node, l, r);
        if(lq > r || rq < l) return 0;
        if(lq <= l && r <= rq) return t[node];

        int mid = l + r >> 1;
        return (
            rangeQuery(2 * node + 1, l, mid, lq, rq) +
            rangeQuery(2 * node + 2, mid + 1, r, lq, rq)
        );
    }
    ll rangeQuery(int lq, int rq){ return rangeQuery(0, 0, n - 1, lq, rq); }

    ll rangeSum(int node, int l, int r, int lq, int rq){
        push(node, l, r);
        if(lq > r || rq < l) return 0;
        if(lq <= l && r <= rq) return sm[node];

        int mid = l + r >> 1;
        return (
            rangeSum(2 * node + 1, l, mid, lq, rq) +
            rangeSum(2 * node + 2, mid + 1, r, lq, rq)
        );
    }
    ll rangeSum(int lq, int rq){ return rangeSum(0, 0, n - 1, lq, rq); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    SegmentTree st(n + 1);
    rep(i, 1, n + 1){
        int x; cin >> x;
        st.rangeUpdate(i, i, 0, x);
    }

    rep(_, 0, q){
        int op; cin >> op;
        if(op == 1){
            int l, r, d; cin >> l >> r >> d;
            st.rangeUpdate(l, r, 0, d);
        }else{
            int l, r; cin >> l >> r;
            cout << st.rangeQuery(l, r) - 1LL * (l - 1) * st.rangeSum(l, r) << "\n";
        }
    }
}
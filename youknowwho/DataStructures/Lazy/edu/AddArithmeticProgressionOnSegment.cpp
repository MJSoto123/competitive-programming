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
    vl t, lz1, lz2;
    SegmentTree(int nn) : n(nn), t(4 * nn + 10, 0), lz1(4 * nn + 10, 0), lz2(4 * nn + 10, 0) {}
    void rangeUpdate(int node, int l, int r, int lq, int rq, ll a, ll d){
        if(lq > r || rq < l) return;
        if(lq <= l && r <= rq){
            lz1[node] += a;
            lz2[node] += d;
            return;
        }

        int mid = l + r >> 1;
        rangeUpdate(2 * node + 1, l, mid, lq, rq, a, d);
        rangeUpdate(2 * node + 2, mid + 1, r, lq, rq, a, d);
    }
    void rangeUpdate(int lq, int rq, ll a, ll d){ rangeUpdate(0, 0, n - 1, lq, rq, a - lq * d, d); }

    ll pointQuery(int node, int l, int r, int pos, ll a, ll d){
        if(pos < l || pos > r) return 0;
        ll na = a + lz1[node];
        ll nd = d + lz2[node];
        if(l == r) return t[node] + na + nd * l;
        int mid = l + r >> 1;
        return t[node] + 
        pointQuery(2 * node + 1, l, mid, pos, na, nd) + 
        pointQuery(2 * node + 2, mid + 1, r, pos, na, nd);
    }
    ll pointQuery(int pos){ return pointQuery(0, 0, n - 1, pos, 0, 0); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    SegmentTree st(n);
    rep(_, 0, q){
        int op; cin >> op;
        if(op == 1){
            int l, r, a, d; cin >> l >> r >> a >> d;
            l--; r--;
            st.rangeUpdate(l, r, a, d);
        }else{
            int pos; cin >> pos;
            pos--;
            cout << st.pointQuery(pos) << "\n";
        }
    }
}
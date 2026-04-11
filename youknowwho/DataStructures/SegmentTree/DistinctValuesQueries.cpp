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
    vi t;
    SegmentTree(int nn) : n(nn), t(4 * nn + 10, 0) {}
    void pointUpdate(int node, int l, int r, int pos, int val){
        if(pos < l || pos > r) return;
        if(l == r){
            t[node] += val;
            return;
        }
        int mid = l + r >> 1;
        pointUpdate(2 * node + 1, l, mid, pos, val);
        pointUpdate(2 * node + 2, mid + 1, r, pos, val);
        t[node] = t[2 * node + 1] + t[2 * node + 2];
    }
    void pointUpdate(int pos, int val){ pointUpdate(0, 0, n - 1, pos, val); }

    int rangeQuery(int node, int l, int r, int lq, int rq){
        if(lq > r || l > rq) return 0;
        if(lq <= l && r <= rq) return t[node];
        int mid = l + r >> 1;
        return (
            rangeQuery(2 * node + 1, l, mid, lq, rq) + 
            rangeQuery(2 * node + 2, mid + 1, r, lq, rq)
        );
    }
    int rangeQuery(int lq, int rq){ return rangeQuery(0, 0, n - 1, lq, rq); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    
    vi d = a;
    sort(all(d));
    d.resize(unique(all(d)) - d.begin());
    rep(i, 0, n) a[i] = lower_bound(all(d), a[i]) - d.begin();

    vector<vii> querys(n);
    rep(i, 0, q){
        int l, r; cin >> l >> r;
        l--; r--;
        querys[r].emplace_back(l, i);
    }

    vi ans(q);
    vi last(n, -1);
    SegmentTree st(n);
    rep(i, 0, n){
        if(last[a[i]] != -1) st.pointUpdate(last[a[i]], -1);
        st.pointUpdate(i, +1);
        last[a[i]] = i;
        for(auto [l, id] : querys[i]){
            ans[id] = st.rangeQuery(l, i);
        }
    }

    for(auto x : ans) cout << x << "\n";
}
#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

struct SegmentTree{
    int n; 
    vvi t;
    void build(const vi &a, int node, int l, int r){
        if(l == r){
            t[node] = vi(1, a[l]);
            return;
        }
        int mid = l + r >> 1;
        build(a, 2 * node + 1, l, mid);
        build(a, 2 * node + 2, mid + 1, r);
        auto &v1 = t[2 * node + 1];
        auto &v2 = t[2 * node + 2];
        int sz1 = sz(v1);
        int sz2 = sz(v2);

        int i = 0, j = 0;
        while(i < sz1 && j < sz2){
            if(v1[i] < v2[j]) t[node].emplace_back(v1[i++]);
            else t[node].emplace_back(v2[j++]);
        }
        while(i < sz1) t[node].emplace_back(v1[i++]);
        while(j < sz2) t[node].emplace_back(v2[j++]);
    }
    void init(const vi &a){
        n = sz(a);
        t.resize(4 * n + 10);
        build(a, 0, 0, n - 1);
    }

    int get(const vi &a, int val){
        int l = -1, r = sz(a);
        while(r - l > 1){
            int mid = l + r >> 1;
            if(a[mid] > val) r = mid;
            else l = mid;
        }
        return sz(a) - 1 - r + 1;
    }

    int rangeQuery(int node, int l, int r, int lq, int rq, int val){
        if(lq > r || l > rq) return 0;
        if(lq <= l && r <= rq) return get(t[node], val);
        int mid = l + r >> 1;
        return (
            rangeQuery(2 * node + 1, l, mid, lq, rq, val) +
            rangeQuery(2 * node + 2, mid + 1, r, lq, rq, val)
        );
    }
    int rangeQuery(int lq, int rq, int val){ return rangeQuery(0, 0, n - 1, lq, rq, val); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    SegmentTree st;
    st.init(a);

    int q; cin >> q;
    rep(_, 0, q){
        int l, r, val; cin >> l >> r >> val;
        l--; r--;
        cout << st.rangeQuery(l, r, val) << "\n";
    }
}
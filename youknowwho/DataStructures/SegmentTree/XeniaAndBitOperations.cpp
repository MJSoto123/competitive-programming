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
    vi d;
    void build(const vi &a, int node, int l, int r){
        if(l == r){
            t[node] = a[l];
            d[node] = 0;
            return;
        }
        int mid = l + r >> 1;
        build(a, 2 * node + 1, l, mid);
        build(a, 2 * node + 2, mid + 1, r);
        d[node] = d[2 * node + 1] ^ 1;
        if(d[node]) t[node] = t[2 * node + 1] | t[2 * node + 2]; 
        else t[node] = t[2 * node + 1] ^ t[2 * node + 2];
    }

    void init(const vi &a){
        n = sz(a);
        t.resize(4 * n + 10);
        d.resize(4 * n + 10);
        build(a, 0, 0, n - 1);
    }

    void pointUpdate(int node, int l, int r, int pos, int val){
        if(pos < l || pos > r) return;
        if(l == r){
            t[node] = val;
            return;
        }

        int mid = l + r >> 1;
        pointUpdate(2 * node + 1, l, mid, pos, val);
        pointUpdate(2 * node + 2, mid + 1, r, pos, val);
        if(d[node]) t[node] = t[2 * node + 1] | t[2 * node + 2]; 
        else t[node] = t[2 * node + 1] ^ t[2 * node + 2];
    }
    void pointUpdate(int pos, int val){ pointUpdate(0, 0, n - 1, pos, val); }

    int rangeQuery(int node, int l, int r, int lq, int rq){
        if(lq > r || l > rq) return 0;
        if(lq <= l && r <= rq) return t[node];
        int mid = l + r >> 1;
        int ansl = rangeQuery(2 * node + 1, l, mid, lq, rq);
        int ansr = rangeQuery(2 * node + 2, mid + 1, r, lq, rq);

        if(d[node]) return ansl | ansr; 
        return ansl ^ ansr;
    }
    int rangeQuery(int lq, int rq){ return rangeQuery(0, 0, n - 1, lq, rq); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    n = (1 << n);
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    
    SegmentTree st;
    st.init(a);

    rep(i, 0, m){
        int pos, val; cin >> pos >> val;
        pos--;
        st.pointUpdate(pos, val);
        cout << st.rangeQuery(0, n - 1) << "\n";
    }
}
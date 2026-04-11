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

struct Seg{
    int n;
    vi t;
    void build(const vi &a, int v, int l, int r){
        if(l == r){
            t[v] = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(a, 2 * v + 1, l, mid);
        build(a, 2 * v + 2, mid + 1, r);
        t[v] = __gcd(t[2 * v + 1], t[2 * v + 2]);
    }
    void init(const vi &a){
        n = sz(a);
        t.assign(4 * n + 10, 0);
        build(a, 0, 0, n - 1);
    }

    int query(int v, int l, int r, int lq, int rq){
        if(lq > r || l > rq) return 0;
        if(lq <= l && r <= rq) return t[v];
        int mid = l + r >> 1;
        return __gcd(
            query(2 * v + 1, l, mid, lq, rq),
            query(2 * v + 2, mid + 1, r, lq, rq)
        );
    }
    int query(int lq, int rq){ return query(0, 0, n - 1, lq, rq); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    Seg st;
    st.init(a);
    
    int q; cin >> q;
    map<int, vi> mp;
    rep(i, 0, n) mp[a[i]].emplace_back(i);

    rep(i, 0, q){
        int l, r; cin >> l >> r;
        l--; r--;
        int g = st.query(l, r);
        // cerr << "l r " << l << " " << r << " => " << g << "\n";
        if(!mp.count(g)){
            cout << r - l + 1 << "\n";
            continue;
        }
        auto &v = mp[g];
        int ansl = lower_bound(all(v), l) - v.begin();
        int ansr = upper_bound(all(v), r) - v.begin();
        cout << r - l + 1  - (ansr - ansl) << "\n";
    }
}
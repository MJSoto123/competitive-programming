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

struct ST{
    int n; 
    vl t;
    void build(const vl &a, int v, int l, int r){
        if(l == r){
            t[v] = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(a, 2 * v + 1, l, mid);
        build(a, 2 * v + 2, mid + 1, r);
        t[v] = __gcd(t[2 * v + 1] ,t[2 * v + 2]);
    }
    void init(const vl &a){
        n = sz(a);
        t.assign(4 * n + 5, 0);
        build(a, 0, 0, n - 1);
    }

    ll query(int v, int l, int r, int lq, int rq){
        if(lq > r || rq < l) return 0;
        if(lq <= l && r <= rq) return t[v];
        int mid = l + r >> 1;
        return __gcd(
            query(2 * v + 1, l, mid, lq, rq),
            query(2 * v + 2, mid + 1, r, lq, rq)
        );
    }
    ll query(int lq, int rq){ return query(0, 0, n - 1, lq, rq); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vl a(n);
    rep(i, 0, n) cin >> a[i];
    if(count(all(a), 1)){ cout << "1\n"; return 0; }

    ST st; st.init(a);
    int r = 0;
    int ans = n + 1;
    rep(l, 0, n){
        ll g = st.query(l, max(r - 1, l));
        while(r < n && g != 1) g = __gcd(g, a[r++]);
        if(g == 1) ans = min(ans, r - l);
    }
    cout <<  (ans == n + 1 ? -1 : ans) << "\n";
}
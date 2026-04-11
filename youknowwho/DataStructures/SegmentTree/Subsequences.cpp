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
    vl t;
    Seg(int nn) : n(nn), t(4 * nn + 10, 0) {}
    void upd(int v, int l, int r, int pos, ll val){
        if(pos < l || pos > r) return;
        if(l == r){
            t[v] += val;
            return;
        }
        int mid = l + r >> 1;
        upd(2 * v + 1, l, mid, pos, val);
        upd(2 * v + 2, mid + 1, r, pos, val);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
    void upd(int pos, ll val){ upd(0, 0, n - 1, pos, val); }

    ll query(int v, int l, int r, int lq, int rq){
        if(lq > r || l > rq) return 0;
        if(lq <= l && r <= rq) return t[v];
        int mid = l + r >> 1;
        return (
            query(2 * v + 1, l, mid, lq, rq) + 
            query(2 * v + 2, mid + 1, r, lq, rq)
        );
    }
    ll query(int lq, int rq){ return query(0, 0, n - 1, lq, rq); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    vector<Seg> dp(k + 2, Seg(n + 1));
    rep(i, 0, n){
        for(int len = k; len >= 1; len--){
            ll add = dp[len].query(0, a[i] - 1);
            dp[len + 1].upd(a[i], +add);
        }
        dp[1].upd(a[i], +1);
    }

    cout << dp[k + 1].query(0, n + 1) << "\n";
}
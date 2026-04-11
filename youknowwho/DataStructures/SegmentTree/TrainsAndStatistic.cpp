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

struct ST{
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
        t[v] = max(t[2 * v + 1], t[2 * v + 2]);
    }

    void init(const vi &a){
        n = sz(a);
        t.assign(4 * n + 5, 0);
        build(a, 0, 0, n - 1);
    }

    int query(int v, int l, int r, int lq, int rq){
        if(rq < l || r < lq) return -1;
        if(lq <= l && r <= rq) return t[v];
        int mid = l + r >> 1;
        return max(
            query(2 * v + 1, l, mid, lq, rq),
            query(2 * v + 2, mid + 1, r, lq, rq)
        );
    }
    int query(int l, int r){ return query(0, 0, n - 1, l, r); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vi a(n);
    rep(i, 0, n - 1){ cin >> a[i]; a[i]--; }

    ST seg; seg.init(a);
    ll ans = 0;

    rep(i, 0, n - 1){
        int L = i + 1;
        int R = a[i];
        int dist = 1;

        while(L < n && L <= R){
            int r = min(R, n - 1);
            ans += 1LL * (r - L + 1) * dist;

            int newR = seg.query(L, R);
            if(newR <= R) break;

            L = R + 1;
            R = newR;
            dist++;
        }
    }

    cout << ans << "\n";
}
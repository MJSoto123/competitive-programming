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

struct Seg{
    int n;
    vi t;
    Seg(int nn) : n(nn), t(4 * nn + 10) {}
    void upd(int v, int l, int r, int pos){
        if(pos < l || pos > r) return;
        if(l == r){
            t[v]++;
            return;
        }
        int mid = l + r >> 1;
        upd(2 * v + 1, l, mid, pos);
        upd(2 * v + 2, mid + 1, r, pos);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
    void upd(int pos){ upd(0, 0, n - 1, pos); }

    int query(int v, int l, int r, int lq, int rq){
        if(lq > r || l > rq) return 0;
        if(lq <= l && r <= rq) return t[v];
        int mid = l + r >> 1;
        return (
            query(2 * v + 1, l, mid, lq, rq) +
            query(2 * v + 2, mid + 1, r, lq, rq)
        );
    }
    int query(int lq, int rq){ return query(0, 0, n - 1, lq, rq); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    
    vi pos(n + 1);
    rep(i, 0, n) pos[a[i]] = i;

    vvi upds(n);
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j += i){
            int pi = pos[i];
            int pj = pos[j];
            upds[max(pj, pi)].emplace_back(min(pi, pj));
        }
    }

    vector<vii> qs(n + 1);
    rep(i, 0, m){
        int l, r; cin >> l >> r;
        r--; l--;
        qs[r].emplace_back(l, i);
    }

    Seg st(n);
    vi ans(m);
    rep(r, 0, n){
        for(auto pos : upds[r]) st.upd(pos);
        for(auto [l, id] : qs[r]) ans[id] = st.query(l, r);
    }

    for(auto x : ans) cout << x << "\n";
}
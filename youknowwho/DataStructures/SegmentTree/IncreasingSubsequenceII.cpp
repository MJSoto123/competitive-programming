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

const int MOD = 1e9 + 7;
int add(int a, int b){ return (a + b) % MOD; }
struct Seg{
    int n;
    vi t;
    Seg(int nn) : n(nn), t(4 * nn + 10, 0) {}
    void upd(int v, int l, int r, int pos, int val){
        if(pos < l || pos > r) return;
        if(l == r){
            t[v] = add(t[v], val);
            return;
        }
        int mid = l + r >> 1;
        upd(2 * v + 1, l, mid, pos, val);
        upd(2 * v + 2, mid + 1, r, pos, val);
        t[v] = add(t[2 * v + 1], t[2 * v + 2]);
    }
    void upd(int pos, int val){ upd(0, 0, n - 1, pos, val); }

    int query(int v, int l, int r, int lq, int rq){
        if(lq > r || l > rq) return 0;
        if(lq <= l && r <= rq) return t[v];
        int mid = l + r >> 1;
        return add(
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
    
    vi d = a;
    sort(all(d));
    d.resize(unique(all(d)) - d.begin());
    rep(i, 0, n) a[i] = lower_bound(all(d), a[i]) - d.begin();

    Seg st(sz(d) + 1);
    st.upd(0, 1);
    rep(i, 0, n){
        int toadd = st.query(0, a[i]);
        st.upd(a[i] + 1, toadd);
    }

    cout << st.query(1, sz(d)) << "\n"; 
}    
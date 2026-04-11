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
const int MOD = 998244353;
int add(int a, int b){ return (a + b) % MOD; }
int subs(int a, int b){ return (a + MOD - b) % MOD; }
int mul(int a, int b){ return 1LL * a * b % MOD; }

struct Seg{
    int n; 
    vi t;

    Seg(int nn) : n(nn), t(4 * nn + 10, 0) {}

    void upd(int node, int l, int r, int pos, int val){
        if(pos < l || pos > r) return;
        if(l == r){
            t[node] = add(t[node], val);
            return;
        }

        int mid = l + r >> 1;
        upd(2 * node + 1, l, mid, pos, val);
        upd(2 * node + 2, mid + 1, r, pos, val);
        t[node] = add(t[node * 2 + 1], t[node * 2 + 2]);
    }
    void upd(int pos, int val){ upd(0, 0, n - 1, pos, val); }

    
    int query(int node, int l, int r, int lq, int rq){
        if(lq > r || l > rq) return 0;
        if(l >= lq && r <= rq) return t[node];
        int mid = l + r >> 1;
        return add(
            query(2 * node + 1, l, mid, lq, rq), 
            query(2 * node + 2, mid + 1, r, lq, rq)
        );
    }
    int query(int lq, int rq){ return query(0, 0, n - 1, lq, rq); }
};

void solve(){
    int n, m; cin >> n >> m;
    n--;
    vi q(n + 1, 0);
    rep(i, 0, m){
        int l, r; cin >> l >> r;
        r--;
        q[r] = max(q[r], l);
    }

    Seg st(n + 1);
    vi ans(n + 1, 0);
    vi old(n + 1, 0);
    old[0] = 1;
    ans[0] = 1;

    st.upd(0, +1);
    int idx = 0;
    int idx2 = 0;
    rep(i, 1, n + 1){
        idx = max(idx, q[i]);
        int sm = 0;
        if(idx - 1 >= 0) sm = st.query(0, idx - 1);

        // add 0 1
        ans[i] = mul(2, ans[i - 1]);

        // sub old
        ans[i] = subs(ans[i], sm);

        // old
        old[i] = ans[i - 1];
        st.upd(i, old[i]);

        while(idx2 < idx){
            st.upd(idx2, subs(0, old[idx2]));
            idx2++;
        }
    }

    cout << mul(2, ans[n]) << "\n"; 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt; 
    while(tt--) solve();   
}
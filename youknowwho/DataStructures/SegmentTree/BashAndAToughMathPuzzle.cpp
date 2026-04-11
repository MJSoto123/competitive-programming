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

    void upd(int v, int l, int r, int pos, int val){
        if(pos < l || pos > r) return;
        if(l == r){
            t[v] = val;
            return;
        }
        int mid = l + r >> 1;
        upd(2 * v + 1, l, mid, pos, val);
        upd(2 * v + 2, mid + 1, r, pos, val);
        t[v] = __gcd(t[2 * v + 1], t[2 * v + 2]);
    }
    void upd(int pos, int val){ upd(0, 0, n - 1, pos, val); }

    int query(int v, int l, int r, int lq, int rq, int val){
        if(lq > r || l > rq) return 0;
        if(lq <= l || r <= rq){
            if(t[v] % val == 0) return 0;
        }
        if(l == r) return (t[v] % val != 0);
        int mid = l + r >> 1;

        int ans = query(2 * v + 1, l, mid, lq, rq, val);
        if(ans > 1) return ans;
        return ans + query(2 * v + 2, mid + 1, r, lq, rq, val);
    }
    int query(int lq, int rq, int val){ return query(0, 0, n - 1, lq, rq, val); }
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
    rep(_, 0, q){
        int op; cin >> op;
        if(op == 1){
            int l, r, val; cin >> l >> r >> val;
            l--; r--;
            int ans = st.query(l, r, val);
            cout << (ans <= 1 ? "YES" : "NO") << "\n";
        }else{
            int pos, val; cin >> pos >> val;
            pos--;
            st.upd(pos, val);
        }
    }
}
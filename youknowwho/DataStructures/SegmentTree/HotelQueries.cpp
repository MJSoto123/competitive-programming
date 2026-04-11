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
        t[v] = max(t[2 * v + 1], t[2 * v + 2]);
    }
    void init(const vi &a){
        n = sz(a);
        t.assign(4 * n + 10, -1);
        build(a, 0, 0, n - 1);
    }

    void upd(int v, int l, int r, int pos, int val){
        if(pos < l || pos > r) return;
        if(l == r){
            t[v] -= val;
            return;
        }
        int mid = l + r >> 1;
        upd(2 * v + 1, l, mid, pos, val);
        upd(2 * v + 2, mid + 1, r, pos, val);
        t[v] = max(t[2 * v + 1], t[2 * v + 2]);
    }
    void upd(int pos, int val){ upd(0, 0, n - 1, pos, val); }

    int descend(int v, int l, int r, int val){
        if(t[v] < val) return -1;
        if(l == r) return l;
        int mid = l + r >> 1;

        int ans = descend(2 * v + 1, l, mid, val);
        if(ans == -1) ans = descend(2 * v + 2, mid + 1, r, val);
        return ans;
    }
    int descend(int val){ return descend(0, 0, n - 1, val); }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    Seg st;
    st.init(a);

    rep(_, 0, q){
        int val; cin >> val;
        int id = st.descend(val);
        if(id == -1){ cout << "0 "; continue; }
        cout << id + 1 << " ";
        st.upd(id, val);
    }
    cout << "\n";
}
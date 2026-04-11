#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a); i < (b); i++)

using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<pii> vii;

struct SparseTable{
    int n, lg;
    vvi tb;
    void init(const vi &a){
        n = sz(a);
        lg = log2(n) + 1;
        tb.assign(lg, vi(n));
        rep(i, 0, n) tb[0][i] = a[i];
        rep(lvl, 1, lg) rep(i, 0, n){
            if(i + (1 << lvl) > n) break;
            tb[lvl][i] = min(tb[lvl - 1][i], tb[lvl - 1][i + (1 << (lvl - 1))]);
        }
    }

    int query(int l, int r){
        int len = r - l + 1;
        int lvl = log2(len);
        return min(tb[lvl][l], tb[lvl][r - (1 << lvl) + 1]);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    SparseTable st; 
    st.init(a);

    rep(i, 0, q){
        int l, r; cin >> l >> r;
        l--; r--;
        cout << st.query(l, r) << "\n";
    }
}
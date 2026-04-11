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

struct SparseTable{
    int n, lg;
    vvi tb;
    void init(const vi &a){
        n = sz(a);
        lg = log2(n + 1) + 1;
        tb.assign(lg, vi(n + 1, 0));

        rep(i, 0, n) tb[0][i] = a[i];
        rep(lvl, 1, lg) rep(i, 0, n){
            if(i + (1 << lvl) > n) break;
            tb[lvl][i] = __gcd(tb[lvl - 1][i], tb[lvl - 1][i + (1 << (lvl - 1))]); 
        }
    }

    int query(int l, int r){
        int len = r - l + 1;
        int lvl = log2(len);
        return __gcd(tb[lvl][l], tb[lvl][r - (1 << lvl) + 1]);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    SparseTable st;
    st.init(a);

    map<int, ll> mp;
    rep(i, 0, n){
        int pos = i;
        while(pos < n){
            int cur = st.query(i, pos);

            int l = pos, r = n;
            while(r - l > 1){
                int mid = l + r >> 1;
                if(st.query(i, mid) == cur) l = mid;
                else r = mid;
            }
            mp[cur] += (l - pos + 1);
            pos = l + 1;
        }
    }

    int q; cin >> q;
    rep(i, 0, q){
        int val; cin >> val;
        cout << mp[val] << "\n";
    }
}
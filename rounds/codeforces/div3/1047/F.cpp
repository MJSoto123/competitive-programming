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


int lso(int n) {return (n & (-n));}

// las consultas están indexadas en 1
struct FenwickTree{
    vector<int> ft; 
    FenwickTree(int m) {ft.assign(m + 1, 0);};
    int rsq(int j) {
        int mx = 0;
        for(; j; j -= lso(j)) mx = max(mx, ft[j]);
        return mx;
    }
    void upd(int i, int v) {
        for(; i < ft.size(); i += lso(i)) ft[i] = max(ft[i], v);
    }
};

void solve(){
    ll n; cin >> n;
    vi a(n + 1), b(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
    rep(i, 1, n + 1) cin >> b[i];

    int n2 = 2 * n;
    FenwickTree ft(n2 + 2);
    
    auto get = [&](int i){
        int idx = n2 - i + 1;
        idx = max(idx, 1);
        idx = min(idx, n2 + 1);
        return idx;
    };

    ll ans = 0;
    rep(i, 1, n + 1){
        int pos1 = ft.rsq(get(a[i]));
        int pos2 = ft.rsq(get(b[i]));
        
        if(b[i] == a[i]) ans += 1LL * (n + 1 - i) * (i - pos1);
        ans += 1LL * (n + 1 - i) * min(pos1, pos2);

        ft.upd(get(a[i]), i);
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}
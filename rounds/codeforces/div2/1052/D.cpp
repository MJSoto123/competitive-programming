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

vl pot(32, 1);
vi a;

ll solve1(int l , int r){
    int n = (r - l + 1);
    a.assign(n, 0);
    iota(all(a), l);
    vi vis(n);

    for(int j = 31; j >= 0; j--){
        for(int i = n - 1; i >= 0; i--){
            if(vis[i]) continue;
            ll best = pot[j] - 1;
            ll target = best ^ a[i];
            
            if(target < l || target > r) continue;
            if(vis[target - l]) continue;
            if(target == a[i]) continue;
            vis[target - l] = 1;
            // cout << "pair " << a[i] << " " << a[target - l] << " t " << target << "\n";
            swap(a[i], a[target - l]);
            vis[i] = 1;
            // break; // xdasxdas
        }
    }

    vi b(n);
    iota(all(b), l);

    ll ans = 0;
    rep(i, 0, n) ans += (a[i] | b[i]);
    return ans;
}

void solve(){
    int l, r; cin >> l >> r;
    int n = r - l + 1;
    ll ans = solve1(l, r);
    vi c = a;

    cout << ans << "\n";
    rep(i, 0, n) cout << c[i] << " \n"[i == n - 1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    rep(i, 1, 32) pot[i] = pot[i - 1] * 2;

    int tt; cin >> tt;
    while(tt--) solve();
}
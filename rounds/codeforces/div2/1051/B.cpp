#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(ll i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

void solve(){
    ll n; cin >> n;
    ll m; cin >> m;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    vi b(m);
    rep(i, 0, m) cin >> b[i];

    sort(all(a));
    reverse(all(a));
    sort(all(b));

    ll sm = 0;
    ll ans = 0;
    rep(i, 0, m){
        rep(j, sm, min(sm + b[i] - 1, n)) ans += a[j];
        sm += b[i];
    }

    rep(i, sm , n) ans += a[i];
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}
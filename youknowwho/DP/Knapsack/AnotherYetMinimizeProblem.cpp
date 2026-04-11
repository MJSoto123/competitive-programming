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

void solve(){
    int n; cin >> n;
    vi a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    ll ans = 0;
    rep(i, 0, n) ans += 1LL * a[i] * a[i];
    rep(i, 0, n) ans += 1LL * b[i] * b[i];

    ans *= (n - 2);
    int MX = 100 * 100 + 5;
    vvi dp(2, vi(MX));
    dp[0][0] = dp[1][0] = 1;

    rep(i, 0, n){
        vvi ndp(2, vi(MX));
        for(int j = MX - a[i] - 1; j >= 0; j--) ndp[0][j + a[i]] |= dp[0][j];
        for(int j = MX - a[i] - 1; j >= 0; j--) ndp[0][j + a[i]] |= dp[1][j];
        for(int j = MX - b[i] - 1; j >= 0; j--) ndp[1][j + b[i]] |= dp[1][j];
        for(int j = MX - b[i] - 1; j >= 0; j--) ndp[1][j + b[i]] |= dp[0][j];
        swap(dp, ndp);
    }

    int sma = accumulate(all(a), 0);
    int smb = accumulate(all(b), 0);
    int sm = sma + smb;
    int extra = sma * sma + smb * smb;
    rep(i, 0, MX){
        if(dp[0][i]) extra = min(extra, i * i + (sm - i) * (sm - i));
        if(dp[1][i]) extra = min(extra, i * i + (sm - i) * (sm - i));
    }

    cout << ans + extra << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}
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

ll mul(ll a, ll b){
    if(2e18 / a < b) return 2e18;
    return a * b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, y; cin >> n >> m >> y;
    vl a(n); 
    rep(i, 0, n) cin >> a[i];

    vl dp(1 << n);
    rep(mask, 1, (1 << n)){
        ll lcm = 1;
        rep(i, 0, n) if(mask & (1 << i)){
            ll g = __gcd(lcm, a[i]);
            lcm = mul(lcm, a[i] / g);
        }
        dp[mask] = y / lcm;
    }
    rep(i, 0, n) rep(j, 0, 1 << n) if (j & (1 << i)){
        dp[j - (1 << i)] -= dp[j];
    }
    
    ll ans = 0;
    rep(mask, 0, (1 << n)){
        int cnt = 0;
        rep(i, 0, n) if(mask & (1 << i)) cnt++;
        if(cnt == m) ans += dp[mask];
    }

    cout << ans << "\n";
}
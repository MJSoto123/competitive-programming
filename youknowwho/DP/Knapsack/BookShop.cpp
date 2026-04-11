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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vi a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    vi dp(k + 1, -1e9);
    dp[0] = 0;
    rep(i, 0, n){
        int w = a[i];
        int v = b[i];
        for(int j = k - w; j >= 0; j--){
            if(dp[j] != -1e9) dp[j + w] = max(dp[j + w], dp[j] + v);
        }
    }
    int ans = -1e9;
    rep(i, 0, k + 1) ans = max(ans, dp[i]);
    cout << ans << "\n";
}
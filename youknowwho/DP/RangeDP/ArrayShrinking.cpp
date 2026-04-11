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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    vvi dp(n, vi(n, 1e9));
    vvi ans(n, vi(n, 0));
    rep(i, 0, n) ans[i][i] = a[i];
    rep(i, 0, n) dp[i][i] = 1;

    rep(len, 2, n + 1){
        rep(l, 0, n){
            int r = l + len - 1;
            if(r >= n) break;
            rep(k, l, r){
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);

                if(!ans[l][k]) continue;
                if(!ans[k + 1][r]) continue;
                if(ans[l][k] != ans[k + 1][r]) continue;
                ans[l][r] = ans[l][k] + 1;
                dp[l][r] = 1;
            }
        }
    }

    cout << dp[0][n - 1] << "\n";
}
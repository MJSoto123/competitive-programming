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

    int n, k; cin >> n >> k;
    vi e2(n), e5(n);

    rep(i, 0, n){
        ll x; cin >> x;
        while(x % 2 == 0){ x /= 2; e2[i]++; }
        while(x % 5 == 0){ x /= 5; e5[i]++; }
    }

    vvi dp(30 * n, vi(k + 1, -1));
    dp[0][0] = 0;
    rep(i, 0, n){
        vvi ndp = dp;
        rep(j, 0, 30 * n) rep(tak, 0, k){
            if(dp[j][tak] == -1) continue;
            ndp[j + e5[i]][tak + 1] = max(ndp[j + e5[i]][tak + 1], dp[j][tak] + e2[i]);
        }
        swap(dp, ndp);
    }

    int ans = 0;
    rep(i, 0, 30 * n){
        int ze = min(i, dp[i][k]);
        ans = max(ans, ze);
    }

    cout << ans << "\n";
}   
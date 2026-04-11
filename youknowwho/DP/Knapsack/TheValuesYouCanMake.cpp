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
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    vvi dp(k + 1, vi(k + 1));
    dp[0][0] = 1;
    for(auto w : a){
        vvi ndp(k + 1, vi(k + 1));
        rep(i, 0, k + 1){
            rep(j, 0, i + 1){
                ndp[i][j] |= dp[i][j];
                if(i < w) continue;
                ndp[i][j] |= dp[i - w][j];

                if(j < w) continue;
                ndp[i][j] |= dp[i - w][j - w];
            }
        }
        swap(dp, ndp);
    }

    vi ans;
    rep(i, 0, k + 1) if(dp[k][i]) ans.emplace_back(i);
    cout << sz(ans) << "\n";
    rep(i, 0, sz(ans)) cout << ans[i] << " \n"[i == sz(ans) - 1];
}
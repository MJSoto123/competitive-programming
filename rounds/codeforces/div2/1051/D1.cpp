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

const int MOD = 1e9 + 7;
void add(int &a, int b){ a += b; if(a >= MOD) a -= MOD; }

void solve(){
    int n; cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    vvi dp(n + 1, vi(n + 1));
    dp[0][0] = 1;
    rep(i, 0, n){
        vvi ndp(n + 1, vi(n + 1));
        rep(j, 0, n + 1){
            rep(k, 0, n + 1){
                add(ndp[j][k], dp[j][k]);
                if(a[i] >= j){ add(ndp[a[i]][k], dp[j][k]); continue; }
                // chetuma
                if(a[i] >= k){ add(ndp[j][a[i]], dp[j][k]); continue; }
            }
        }
        swap(dp, ndp);
    }

    int ans = 0;
    rep(i, 0, n + 1) rep(j, 0, n + 1) add(ans, dp[i][j]);
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}
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
int mul(ll a, ll b){ return (a * b) % MOD; }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k; cin >> n >> k;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    sort(all(a));

    vvi dp(n + 1, vi(k + 1, 0));
    dp[0][0] = 1;

    int prev = a[0];
    rep(it, 0, n){
        vvi ndp(n + 1, vi(k + 1, 0));
        rep(i, 0, n){
            rep(j, 0, k + 1){
                int nj = j + i * (a[it] - prev);
                if(nj > k) continue;
                
                // abrir y cerrar
                add(ndp[i][nj], dp[i][j]);

                // abrir y no cerrar
                add(ndp[i + 1][nj], dp[i][j]);

                // extender y no cerrar
                if(i > 0 && nj <= k) add(ndp[i][nj], mul(i ,dp[i][j]));

                // extender y cerrar
                if(i > 0 && nj <= k) add(ndp[i - 1][nj], mul(i, dp[i][j]));
            }
        }
        prev = a[it];
        swap(dp, ndp);

        // cout << "\ndp\n";
        // rep(i, 0, n){
        //     rep(j, 0, k + 1) cout << dp[i][j] << " "; cout << "\n";
        // }
    }    

    int ans = 0;
    rep(i, 0, k + 1) add(ans, dp[0][i]);
    cout << ans << "\n";
}
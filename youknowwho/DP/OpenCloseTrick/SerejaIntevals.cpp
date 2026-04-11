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

    int n, m, x; cin >> n >> m >> x;
    if(n > m){ cout << "0\n"; return 0; }
    vvi dp(n + 2, vi (n + 2));
    dp[0][0] = 1;
    rep(pos, 1, m + 1){
        vvi ndp(n + 2, vi(n + 2));
        rep(i, 0, n + 1){
            rep(j, 0, n + 1){
                if(pos != x){
                    // nada
                    add(ndp[i][j], dp[i][j]);
                    // cerrar
                    if(i > j) add(ndp[i][j + 1], dp[i][j]);
                }
                // abrir
                add(ndp[i + 1][j], dp[i][j]);
                // abrir cerrar
                add(ndp[i + 1][j + 1], dp[i][j]);
            }
        }

        swap(dp, ndp);
    }

    int ans = dp[n][n];
    for(int i = 1; i <= n; i++) ans = mul(ans, i);
    cout << ans << "\n";
}
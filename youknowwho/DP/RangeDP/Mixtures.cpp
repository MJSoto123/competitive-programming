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

const int MOD = 100;
const int inf = 1e9;
int add(int a, int b){ return (a + b >= MOD ? a + b - MOD : a + b); }
int sub(int a, int b){ return (a >= b ? a - b : a + MOD - b); }
void chmin(int &a, int b){ a = min(a, b); }
void solve(int n){
    vi a(n);
    rep(i, 0, n) cin >> a[i], a[i] %= MOD;

    vi pre(n + 1);
    rep(i, 0, n) pre[i + 1] = add(pre[i], a[i]);

    vvi dp(n, vi(n, inf));
    rep(i, 0, n) dp[i][i] = 0;
    
    rep(len, 2, n + 1){
        rep(l, 0, n){
            int r = l + len - 1;
            if(r >= n) continue;
            rep(k, l, r){
                int m1 = sub(pre[k + 1], pre[l + 1 - 1]);
                int m2 = sub(pre[r + 1], pre[k + 1 + 1 - 1]);
                int cost = m1 * m2;
                chmin(dp[l][r], dp[l][k] + dp[k + 1][r] + cost);
            }
        }
    }
    cout << dp[0][n - 1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n) solve(n);
}
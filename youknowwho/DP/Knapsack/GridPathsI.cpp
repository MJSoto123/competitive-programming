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
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<string> a(n);
    rep(i, 0, n) cin >> a[i];

    vvi dp(n, vi(n));
    dp[0][0] = (a[0][0] == '.');
    rep(i, 0, n){
        rep(j, 0, n){
            if(a[i][j] == '*') continue;
            if(i) add(dp[i][j], dp[i - 1][j]);
            if(j) add(dp[i][j], dp[i][j - 1]);
        }
    }

    cout << dp[n - 1][n - 1] << "\n";
}
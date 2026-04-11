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

const int MOD = 1e9 + 7;
void add(int &a, int b){ a += b; if(a >= MOD) a -= MOD; }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int lcm = 2520;

    vi a(n);
    rep(i, 0, n) cin >> a[i];

    vi dp(lcm + 1, 0);
    dp[1] = 1;

    rep(i, 0, n){
        vi ndp(lcm + 1, 0);
        rep(j, 0, lcm){
            add(ndp[j], dp[j]);
            add(ndp[(j * a[i]) % lcm], dp[j]);
        }
        swap(dp, ndp);
    }
    

    cout << dp[0] << "\n";
}
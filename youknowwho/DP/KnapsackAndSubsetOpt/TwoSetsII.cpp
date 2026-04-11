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
int mul(ll a, ll b){ return (a * b) % MOD; }
int binpow(ll a, ll exp){
    ll res = 1;
    while(exp){
        if(exp & 1) res = mul(res, a);
        a = mul(a, a);
        exp >>= 1;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int sm = n * (n + 1) / 2;
    if(sm % 2){ cout << "0\n"; return 0; }

    sm /= 2;
    vi dp(sm + 1);
    dp[0] = 1;
    rep(w, 1, n + 1){
        for(int i = sm - w; i >= 0; i--) add(dp[i + w], dp[i]);
    }

    cout << mul(dp[sm], binpow(2, MOD - 2)) << "\n";
}
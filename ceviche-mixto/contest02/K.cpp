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

const int MOD = 1e9 + 9;
int add(ll a, ll b){ return (a + b) % MOD; }
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

    ll n; cin >> n;
    n++;
    ll ans = binpow(2, n);
    ans = add(ans, MOD - 1);
    n %= MOD;
    ans = add(ans, MOD - n);
    cout << ans << "\n";
}
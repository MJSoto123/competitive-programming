#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b); i++)
using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vi> vvi;

const int MOD = 1e9 + 7;
int add(ll a, ll b){ return (a + b) % MOD; }
int mul(ll a, ll b){ return (a * b) % MOD; }
int binpow(int a, int exp){
    int res = 1;
    while(exp){
        if(exp & 1) res = mul(res, a);
        a = mul(a, a);
        exp >>= 1;
    }
    return res;
}

int inverse(int a){ return binpow(a, MOD - 2); }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n, m; cin >> n >> m;
    vi a(m);
    rep(i, 0, m) cin >> a[i];

    int chance = inverse(2);
    int suf = 0;

    vi ans(n + 1);
    for(int i = m - 1; i >= 0; i--){
        ans[a[i]] = add(ans[a[i]], mul(suf, chance));
        suf = add(suf, a[i]);
        suf = mul(suf, chance);
    }
    
    ans[1] = add(ans[1], suf);
    rep(j, 1, n + 1) cout << ans[j] << "\n";
}
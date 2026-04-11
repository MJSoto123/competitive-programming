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
ll add(ll a, ll b){ 
    a %= MOD; b %= MOD;
    return (a + b) % MOD; 
}

ll mod(ll a, ll b){ 
    a %= MOD; b %= MOD;
    return (a + b) % MOD; 
}

ll binpow(ll a, ll exp){
    ll res = 1;
    while(exp){
        if(exp & 1) res = mul(res, a);
        a = mul(a, a);
        exp >>= 1;
    }
    return res;
}

ll inverse(ll a){ return binpow(a, MOD - 2); }
ll comb(ll n, ll k){
    // cerr << "C(" << n << ", " << k << ") => ";
    if(k > n) return 0;
    ll num = 1, den = 1;
    rep(i, 0, k){
        num = mul(num, n - i);
        den = mul(den, i + 1);
    } 

    ll ret = mul(num, inverse(den));
    // cerr << ret << "\n";
    return ret;
}

void solve(){
    ll n, a, b; cin >> n >> a >> b;
    ll dvs;
    for(ll i = 1; i * i <= b; i++){
        if(n % i == 0){
            dvs.emplace_back(i);
            ll other = b / i;
            if(other != i) 
        }
    }

    ll ans = 0;
    for(auto d : dvs){
        if(d > a) continue;
        // cerr << "\nd " << d << "\n";
        ll other = b / d;
        ll ansl = 1;
        {
            auto v = factor(d);
            map<ll, int> mp;
            for(auto p : v) mp[p]++;

            for(auto [p, exp] : mp){
                //cerr << "p exp " << p << " " << exp << "\n"; 
                ansl = modmul(ansl, comb(n - 1 + exp, exp), MOD);
            }
        }

        ll ansr = 1;
        {
            auto v = factor(other);
            map<ll, int> mp;
            for(auto p : v) mp[p]++;
            
            //cerr << "other " << "\n";
            for(auto [p, exp] : mp){
                //cerr << "p exp " << p << " " << exp << "\n"; 
                ansr = modmul(ansr, comb(n - 1 + exp, exp), MOD);
            }
        }
        //cerr << "l, r " << ansl << " " << ansr << "\n";
        ans = modadd(ans, modmul(ansl, ansr, MOD));
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    for(int i = 1; i <= tt; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
}
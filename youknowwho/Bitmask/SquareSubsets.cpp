#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)
#define dbg(x) cerr << (#x) << " = [ ", print(x), cerr << "]\n";
using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;
void print(vi a){ for(auto x : a) cerr << x << " "; }

const int MOD = 1e9 + 7;
int add(int a, int b){ return (a + b >= MOD ? a + b - MOD : a + b); } // ojito carajo
int subs(int a, int b){ return (a >= b ? a - b : a + MOD - b); }
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
int inverse(ll a){ return binpow(a, MOD - 2); }
const int N = 1e5 + 10;
vi fact(N, 1), finv(N, 1);
void init(){
    for(int i = 2; i < N; i++) fact[i] = mul(fact[i - 1], i);
    finv[N - 1] = inverse(fact[N - 1]);
    for(int i = N - 2; i >= 1; i--) finv[i] = mul(finv[i + 1], i + 1);
}
int C(int n, int k){ return mul(fact[n], mul(finv[n - k], finv[k])); }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init(); cerr << C(5, 3) << "\n";

    int n; cin >> n;
    vi cnt(71);
    for(int i = 0; i < n; i++){ int x; cin >> x; cnt[x]++; }

    vi primes;
    for(int i = 2; i <= 70; i++){
        bool ok = true;
        for(int dv = 2; dv * dv <= i; dv++){
            if(i % dv == 0) ok = false;
        }
        if(ok) primes.emplace_back(i);
    }

    vi msk(71);
    for(int i = 1; i <= 70; i++){
        int now = i; 
        for(int bit = 0; bit < sz(primes); bit++){
            int exp = 0;
            while(now % primes[bit] == 0) exp++, now /= primes[bit];
            if(exp % 2) msk[i] |= (1 << bit);
        }
    }  

    // for(int i = 0; i <= 70; i++){
    //     cout << i << " " << bitset<20> (msk[i]) << "\n";
    // }
    
    int Sz = 1 << (sz(primes));
    vi dp(Sz + 1);
    dp[0] = 1;

    for(int i = 0; i <= 70; i++){
        if(cnt[i] == 0) continue;
        vi ndp(Sz, 0);

        int prod = 0;
        for(int j = 0; j <= cnt[i]; j++){
            if(j % 2 == 1) prod = add(prod, C(cnt[i], j));
        }
        int nprod = subs(binpow(2, cnt[i]), prod);

        for(int mask = Sz - 1; mask >= 0; mask--){
            int nmask = mask ^ msk[i];
            ndp[mask] =  add(ndp[mask], mul(nprod, dp[mask]));
            ndp[nmask] = add(ndp[nmask], mul(prod, dp[mask]));
        }
        swap(dp, ndp);
        // dbg(dp);
    }

    cout << subs(dp[0], 1) << "\n";
}
#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int,int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
using namespace std;

const int MOD = 1e9 + 7;
inline ll gcd(ll a, ll b) { while (b != 0) swap(b, a %= b); return a; }

int add(ll a, ll b){
    return (a + b + MOD) % MOD;
}

int mul(ll a, ll b){
    return (a * b) % MOD;
}

int binpow(ll a, ll exp){
    ll res = 1;
    while(exp){
        if(exp & 1) res = mul(res, a);
        a = mul(a, a);
        exp >>= 1;
    }
    return res;
}

int inverse(ll a){
    return binpow(a, MOD - 2);
}

const int N = 2e6 + 100;
vi fact(N, 1), finv(N, 1);

void init(){
    for(int i = 2; i < N; i++) fact[i] = mul(fact[i - 1], i);
    finv[N - 1] = inverse(fact[N - 1]);
    for(int i = N - 2; i > 1; i--) finv[i] = mul(finv[i + 1], i + 1);
}

int comb(ll n, ll k){
    return mul(fact[n], mul(finv[n - k], finv[k]));
}

void solve(){
    int a, b, n; cin >> a >> b >> n;

    set<int> goods;
    for(int i = 1; i <= 8; i++){
        for(int mask = 0; mask < (1 << i); mask++){
            int now = 0;
            for(int bit = 0; bit < i; bit++){
                now *= 10;
                if(mask & (1 << bit)) now += a;
                else now += b;
            }
            goods.insert(now);
        }
    }

    int ans = 0;
    for(int i = 0; i <= n; i++){
        int sm = a * i + b * (n - i);
        if(goods.count(sm)) ans = add(ans, comb(n, i));
    }

    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    init();
    // cout << comb(5, 2);
    solve();
}
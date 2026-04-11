#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int,int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
using namespace std;

const int MOD = 998244353;
inline ll gcd(ll a, ll b) { while (b != 0) swap(b, a %= b); return a; }

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

int inverse(ll a){ return binpow(a, MOD - 2); }

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vector<tuple<int, int, int, int>> a(n);
    for(int i = 0; i < n; i++){
        int l, r, p, q; cin >> l >> r >> p >> q;
        a[i] = make_tuple(l, r, p, q);
    }
    
    sort(a.begin(), a.end());
    vi dp(m + 1);
    dp[0] = 1;
    
    vi pre(m + 1, 1);
    for(auto [l, r, p, q] : a) pre[l] = mul(pre[l], mul(q - p, inverse(q)));
    for(int i = 1; i <= m; i++) pre[i] = mul(pre[i - 1], pre[i]);

    for(auto [l, r, p, q] : a){
        int last = dp[l - 1];
        int good = mul(p, inverse(q));
        int bad = mul(pre[r], inverse(pre[l - 1]));
        bad = mul(bad, inverse(mul(q - p, inverse(q))));
        int prob = mul(good, bad);
        dp[r] = add(dp[r], mul(last, prob));
    }
    cout << dp[m] << "\n";
}
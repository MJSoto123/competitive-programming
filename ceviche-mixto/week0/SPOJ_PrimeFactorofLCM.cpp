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
typedef unsigned long long ull;

ull modmul(ull a, ull b, ull m){
    ll ret = a * b - m * ull(1.L / m * a * b);
    return ret + m * (ret < 0) - m * (ret >= (ll)m);
}

ull modpow(ull a, ull exp, ull m){
    ull res = 1;
    while(exp){
        if(exp & 1) res = modmul(res, a, m);
        a = modmul(a, a, m);
        exp >>= 1;
    }
    return res;
}

bool isPrime(ull n){
    if(n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022}, s = __builtin_clz(n - 1), d = n >> s;
    for(ull a : A){
        ull p = modpow(a % n, d, n), i = s;
        while(p != 1 && p != n - 1 && a % n && i--) p = modmul(p, p, n);
        if(p != n - 1 && i != s) return 0;
    }
    return 1;
}

ull pollard(ull n){
    ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
    auto f = [&](ull x){ return modmul(x, x, n) + i; };

    while(t++ % 40 || __gcd(prd, n) == 1){
        if(x == y) x = ++i, y = f(x);
        if((q = modmul(prd, max(x, y) - min(x, y), n))) prd = q;
        x = f(x), y = f(f(y));
    }
    return __gcd(prd, n);
}


vector<ull> factor(ull n){
    if(n == 1) return {};
    if(isPrime(n)) return {n};
    ull x = pollard(n);
    auto l = factor(x), r = factor(n / x);
    l.insert(l.end(), all(r));
    return l;
}

void solve(){
    int n; cin >> n;
    vl a(n);
    rep(i, 0, n) cin >> a[i];
    
    vl st;
    rep(i, 0, n){
        auto fact = factor(a[i]);
        for(auto p : fact) st.emplace_back(p);
    }

    sort(all(st));
    st.erase(unique(all(st)), st.end());

    cout << sz(st) << "\n";
    for(auto p : st) cout << p << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    rep(i, 0, tt){
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
}
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

typedef unsigned long long ull;
ull modmul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}

bool isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	    s = __builtin_ctzll(n-1), d = n >> s;
	for (ull a : A) {   // ^ count trailing zeroes
		ull p = modpow(a%n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}

ull pollard(ull n) {
	ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	auto f = [&](ull x) { return modmul(x, x, n) + i; };
	while (t++ % 40 || __gcd(prd, n) == 1) {
		if (x == y) x = ++i, y = f(x);
		if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
		x = f(x), y = f(f(y));
	}
	return __gcd(prd, n);
}
vector<ull> factor(ull n) {
	if (n == 1) return {};
	if (isPrime(n)) return {n};
	ull x = pollard(n);
	auto l = factor(x), r = factor(n / x);
	l.insert(l.end(), all(r));
	return l;
}

vl getdivs(ll n){
    auto v = factor(n);

    map<ll, int> mp;
    for(ll x : v) mp[x]++;

    vl p, exp;
    for(auto [pi, expi] : mp){
        p.emplace_back(pi);
        exp.emplace_back(expi);
    }

    vl ret(1, 1); 
    int m = sz(p);
    vl cnt(m);
    while(cnt != exp){
        // fix
        cnt[0]++;
        rep(i, 0, m){
            if(cnt[i] > exp[i]) cnt[i + 1]++, cnt[i] = 0;
        }
        
        ll here = 1;
        rep(i, 0, m){
            rep(j, 0, cnt[i]) here *= p[i];
        }
        ret.emplace_back(here);
    }
    return ret;
}

const int MOD = 1e9 + 7;
ll modadd(ll a, ll b){ return (a + b) % MOD; }
ll inverse(ll a){ return (ll)modpow(a, MOD - 2, MOD); }

ll comb(ll n, ll k){
    // cerr << "C(" << n << ", " << k << ") => ";
    if(k > n) return 0;
    ll num = 1, den = 1;
    rep(i, 0, k){
        num = modmul(num, n - i, MOD);
        den = modmul(den, i + 1, MOD);
    } 

    ll ret = modmul(num, inverse(den), MOD);
    // cerr << ret << "\n";
    return ret;
}

void solve(){
    ll n, a, b; cin >> n >> a >> b;
    auto dvs = getdivs(b);
    int m = sz(dvs);

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
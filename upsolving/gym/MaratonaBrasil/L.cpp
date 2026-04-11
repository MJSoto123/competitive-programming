#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll; 
typedef vector<ll> vl; 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pii> vii;


const int MOD = 998244353; 
int add(int a, int b) { return (a + b >= MOD ? a + b - MOD : a + b); }
int sub(int a, int b) { return (a < b ? a - b + MOD : a - b); }
int mul(ll a, ll b) { return a * b % MOD; }
int binpow(int a, int exp) { 
    int ans = 1; 
    while(exp) { 
        if(exp % 2) ans = mul(ans, a); 
        a = mul(a, a); 
        exp >>= 1; 
    }
    return ans; 
}
int invpow(int a) { return binpow(a, MOD - 2); }
const int MAXN = 600000 + 100; 
int fact[MAXN], inv[MAXN]; 
void init() { 
    fact[0] = 1; 
    for(int i = 1; i < MAXN; i++) fact[i] = mul(fact[i - 1], i); 
    inv[MAXN - 1] = invpow(fact[MAXN - 1]); 
    for(int i = MAXN - 1; i > 0; i--) inv[i - 1] = mul(inv[i], i); 
}
int C(int n, int k) { 
    if(n < k) return 0; 
    return mul(fact[n], mul(inv[k], inv[n - k]));
}

int f(int row, int col)  {
	int diag = row + col - 1; 
	return C(diag, row); 
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	init();

	int n, k, q, x; cin >> n >> k >> q >> x; 
	while(q--) { 
		int i, l, r; cin >> i >>  l >> r; 
		i++ ; 
		int ans = f(i, r); 
		if(r > 0) ans = sub(ans, f(i, l - 1)); 
		ans = mul(ans, x); 
		cout << ans << "\n"; 
	}

}

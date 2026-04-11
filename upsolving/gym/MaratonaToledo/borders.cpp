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
int mul(ll a, ll b) { return a * b % MOD; }
int bp(int a, int exp) { 
    int ans = 1; 
    while(exp) { 
        if(exp & 1) ans = mul(ans, a); 
        a = mul(a, a); 
        exp >>= 1; 
    }
    return ans; 
}

int add(int a, int b) { 
    a += b; 
    while(a >= MOD) a -= MOD; 
    while(a < 0) a += MOD; 
    return a; 
}
int sub(int a, int b) { return add(a, -b); }
int inv(int a) { return bp(a, MOD - 2); }

vi interpolate(vi x, vi y, int n) {
	vi res(n), temp(n);
	rep(k,0,n-1) rep(i,k+1,n) { 
		// y[i] = (y[i] - y[k]) / (x[i] - x[k]);
        int num = sub(y[i], y[k]); 
        int den = sub(x[i], x[k]); 
        assert(den != 0); 
        y[i] = mul(num, inv(den)); 
    }
	int last = 0; temp[0] = 1;
	rep(k,0,n) rep(i,0,n) {
        // res[i] += y[k] * temp[i];
		res[i] = add(res[i], mul(y[k], temp[i]));
		swap(last, temp[i]);
        // temp[i] -= last * x[k];
        temp[i] = sub(temp[i], mul(last, x[k])); 
	}
	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    ll a, b; cin >> a >> b; 
    ll ca = (a * (a + 1)) / 2; 
    ll cb = (b * (b + 1)) / 2; 
    ca %= MOD; 
    cb %= MOD; 
    int total = mul(ca, cb); 

    if(a > b) swap(a, b); 
    vi vals(1, 0);
    rep(i,0,3) { 
        int f = add(1, i);
        int s = add(f, (b - a) % MOD) ; 
        int extra = mul(f, s); 
        int new_val = add(vals.back(), extra); 
        vals.push_back(new_val);   
    }
    
    // for(int i : vals) cerr << i << " " ; cerr << "\n"; 
    auto poly = interpolate({0,1,2,3}, vals, 4); 
    // for(int i : poly) cerr << i << " " ; cerr << "\n"; 
    int last = a % MOD; 
    int ans = 0; 
    rep(exp,0,sz(poly)) { 
        int v = bp(last, exp); 
        ans = add(ans, mul(v, poly[exp])); 
    }
    cout << sub(total, ans) << "\n"; 
}

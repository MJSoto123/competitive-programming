#include <set>
#include <map>
#include <queue>
#include <stack>
#include <limits>
#include <bitset>
#include <time.h>
#include <math.h>
#include <vector>
#include <string>
#include <climits>
#include <numeric>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <unordered_map>
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

ll mult(ll a, ll b) {
    ll r = a*b-(ll)((long double)a*b/MOD+.5)*MOD;
    return r < 0 ? r+MOD : r;
}

long long binpow(long long a, long long b) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}

void solve(){
    ll n; cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    
    ll num = 0;
    ll sm = accumulate(a.begin() + 1, a.end(), 0LL);

    for(int i = 0; i < n - 1; i++) {
        num += mult(sm, a[i]);
        num %= MOD;
        sm -= a[i + 1];
    }

    int deno = binpow((n * (n - 1) / 2), MOD - 2);
    cout << mult(num, deno) << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt; cin >> tt;
    while(tt--) solve();    
    return 0;
}
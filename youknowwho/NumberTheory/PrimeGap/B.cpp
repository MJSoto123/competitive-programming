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

ll mulmod(ll a, ll b, ll m) {
    ll r = a*b-(ll)((long double)a*b/m+.5)*m;
    return r < 0 ? r+m : r;
}

ll expmod(ll a, ll exp, ll mod){
    ll res = 1;
    while(exp){
        if(exp & 1) res = mulmod(res, a, mod);
        a = mulmod(a, a, mod);
        exp >>= 1;
    }
    return res;
}

/// O(log^3(n))
bool test(ll n, int a) {
    if (n == a) return true;
    ll s = 0, d = n-1;
    while (d%2 == 0) s++, d /= 2;
    ll x = expmod(a, d, n);
    if (x == 1 || x+1 == n) return true;
    for (int i = 0; i < s-1; i++) {
        x = mulmod(x, x, n);
        if (x == 1) return false;
        if (x+1 == n) return true;
    }
    return false;
}

bool is_prime(ll n) {
    if (n == 1) return false;
    int ar[] = {2,3,5,7,11,13,17,19,23};
    for (auto &p : ar) if (!test(n, p)) return false;
    return true;
}

const int delta = 750;
void solve(ll n){
    if(n == 1 || is_prime(n)){ cout << "0\n"; return; }
    int l = n - 1, r = n + 1;
    while(!is_prime(l)) l--;
    while(!is_prime(r)) r++;

    cout << r - l << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(true){
        ll n; cin >> n;
        if(n == 0) break;
        solve(n);
    }
}
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

void solve(){
    int n; cin >> n;
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    long double d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    d = sqrtl(d);

    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    long double l = 0, r = accumulate(a.begin(), a.end(), (long double) 0.0);
    long double mx = *max_element(a.begin(), a.end());
    
    if(r < d || r - mx + d < mx) cout << "NO\n";
    else cout << "YES\n";
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) solve();
}
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

vi primes = {2, 3, 5, 7};

ll get(ll l){
    ll ans = 0;
    for(int mask = 0; mask < (1 << 4); mask++){
        int bits = __builtin_popcount(mask);
        int val = 1;
        for(int i = 0; i < 4; i++) if(mask & (1 << i)) val *= primes[i];
        if(bits % 2) ans -= l / val;
        else ans += l / val;
    }
    return ans;
}

void solve(){
    ll l , r; cin >> l >> r;
    cout << get(r) - get(l - 1) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) solve();
}
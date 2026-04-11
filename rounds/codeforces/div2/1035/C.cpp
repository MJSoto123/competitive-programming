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
    ll n, l, r, k; cin >> n >> l >> r >> k;
    if(n % 2 == 0){
        if(n == 2){ cout << "-1\n"; return; }
        ll ans = -1;
        for(int bit = 0; bit <= 62; bit++){
            if((1LL << bit) > l){
                if((1LL << bit) <= r) ans = (1LL << bit);
                break;
            }
        }
        if(ans == -1) cout << "-1\n";
        else{
            if(k <= n - 2) cout << l << "\n";
            else cout << ans << "\n";
        }
    }else cout << l << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) solve();
}